function isValidKey(key) {
    const sorted = [...key].sort().join('');
    return sorted === [...Array(key.length).keys()].map(x => x+1).join('');
}

function transpositionEncrypt(plaintext, key) {
    if (!isValidKey(key)) throw new Error('Khóa không hợp lệ! Phải là hoán vị, ví dụ: 3142');
    const cols = key.length;
    const rows = Math.ceil(plaintext.length / cols);
    let grid = Array.from({length: rows}, () => Array(cols).fill('X'));
    let idx = 0;
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (idx < plaintext.length) grid[r][c] = plaintext[idx++];
        }
    }
    let order = [...key].map((k, i) => ({k: k, i: i})).sort((a,b) => a.k.localeCompare(b.k));
    let ciphertext = '';
    for (let p of order) {
        let col = p.i;
        for (let r = 0; r < rows; r++) {
            ciphertext += grid[r][col];
        }
    }
    return ciphertext;
}

function transpositionDecrypt(ciphertext, key) {
    if (!isValidKey(key) || ciphertext.length % key.length !== 0) {
        throw new Error('Khóa hoặc ciphertext không hợp lệ!');
    }
    const cols = key.length;
    const rows = ciphertext.length / cols;
    let grid = Array.from({length: rows}, () => Array(cols).fill(' '));
    let order = [...key].map((k, i) => ({k: k, i: i})).sort((a,b) => a.k.localeCompare(b.k));
    let idx = 0;
    for (let p of order) {
        let col = p.i;
        for (let r = 0; r < rows; r++) {
            grid[r][col] = ciphertext[idx++];
        }
    }
    let plaintext = '';
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (grid[r][c] !== 'X') plaintext += grid[r][c];
        }
    }
    return plaintext;
}