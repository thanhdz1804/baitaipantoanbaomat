class Playfair {
    constructor(key) {
        if (!key) throw new Error('Khóa không được rỗng!');
        this.matrix = this.buildMatrix(key);
    }

    buildMatrix(key) {
        const alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
        let uniqueKey = "";
        let used = new Set();
        for (let c of key.toUpperCase()) {
            if (c === 'J') c = 'I';
            if (/[A-Z]/.test(c) && !used.has(c)) {
                uniqueKey += c;
                used.add(c);
            }
        }
        for (let c of alphabet) {
            if (!used.has(c)) uniqueKey += c;
        }
        let matrix = [];
        for (let i = 0; i < 5; i++) {
            matrix.push(uniqueKey.slice(i*5, (i+1)*5).split(''));
        }
        return matrix;
    }

    findPos(c) {
        c = c.toUpperCase() === 'J' ? 'I' : c.toUpperCase();
        for (let i = 0; i < 5; i++) {
            for (let j = 0; j < 5; j++) {
                if (this.matrix[i][j] === c) return [i, j];
            }
        }
        throw new Error('Ký tự không hợp lệ: ' + c);
    }

    prepareText(text) {
        let prepared = "";
        for (let c of text.toUpperCase()) {
            c = c === 'J' ? 'I' : c;
            if (/[A-Z]/.test(c)) prepared += c;
        }
        let i = 0;
        while (i < prepared.length) {
            if (i === prepared.length - 1) {
                prepared += 'X';
                break;
            }
            if (prepared[i] === prepared[i+1]) {
                prepared = prepared.slice(0, i+1) + 'X' + prepared.slice(i+1);
            }
            i += 2;
        }
        return prepared;
    }

    encrypt(plaintext) {
        plaintext = this.prepareText(plaintext);
        let ciphertext = "";
        for (let i = 0; i < plaintext.length; i += 2) {
            let [r1, c1] = this.findPos(plaintext[i]);
            let [r2, c2] = this.findPos(plaintext[i+1]);
            if (r1 === r2) {
                ciphertext += this.matrix[r1][(c1 + 1) % 5];
                ciphertext += this.matrix[r2][(c2 + 1) % 5];
            } else if (c1 === c2) {
                ciphertext += this.matrix[(r1 + 1) % 5][c1];
                ciphertext += this.matrix[(r2 + 1) % 5][c2];
            } else {
                ciphertext += this.matrix[r1][c2];
                ciphertext += this.matrix[r2][c1];
            }
        }
        return ciphertext;
    }

    decrypt(ciphertext) {
        if (ciphertext.length % 2 !== 0) throw new Error('Ciphertext không hợp lệ!');
        let plaintext = "";
        for (let i = 0; i < ciphertext.length; i += 2) {
            let [r1, c1] = this.findPos(ciphertext[i]);
            let [r2, c2] = this.findPos(ciphertext[i+1]);
            if (r1 === r2) {
                plaintext += this.matrix[r1][(c1 - 1 + 5) % 5];
                plaintext += this.matrix[r2][(c2 - 1 + 5) % 5];
            } else if (c1 === c2) {
                plaintext += this.matrix[(r1 - 1 + 5) % 5][c1];
                plaintext += this.matrix[(r2 - 1 + 5) % 5][c2];
            } else {
                plaintext += this.matrix[r1][c2];
                plaintext += this.matrix[r2][c1];
            }
        }
        let result = "";
        for (let i = 0; i < plaintext.length; ++i) {
            if (i < plaintext.length - 1 && plaintext[i+1] === 'X' && i % 2 === 0) {
                result += plaintext[i];
                ++i;
            } else {
                result += plaintext[i];
            }
        }
        if (result.endsWith('X')) result = result.slice(0, -1);
        return result;
    }
}