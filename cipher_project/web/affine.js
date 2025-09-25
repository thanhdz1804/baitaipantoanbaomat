function gcd(a, b) {
    a = Math.abs(a);
    b = Math.abs(b);
    while (b) [a, b] = [b, a % b];
    return a;
}

function modInverse(a, m) {
    a = ((a % m) + m) % m;
    for (let x = 1; x < m; x++) {
        if ((a * x) % m === 1) return x;
    }
    return -1;
}

/**
 * affineShift(text, key, encrypt = true)
 * - text: input string
 * - key: can be one of:
 *     - string like "5,8"
 *     - array [5, 8]
 *     - object {a:5, b:8}
 *     - or two numbers passed as an array
 * - encrypt: true = encrypt, false = decrypt
 */
function affineShift(text, key, encrypt = true) {
    let a, b;

    // Accept multiple key formats (string, array, object)
    if (typeof key === 'string') {
        const parts = key.split(',').map(x => parseInt(x.trim(), 10));
        a = parts[0];
        b = parts[1];
    } else if (Array.isArray(key)) {
        a = parseInt(key[0], 10);
        b = parseInt(key[1], 10);
    } else if (typeof key === 'object' && key !== null) {
        a = parseInt(key.a, 10);
        b = parseInt(key.b, 10);
    } else {
        throw new Error('Khóa không hợp lệ. Hãy truyền "a,b" hoặc [a,b] hoặc {a:...,b:...}');
    }

    if (isNaN(a) || isNaN(b)) throw new Error('Khóa phải là hai số (a,b), ví dụ: 5,8');

    if (gcd(a, 26) !== 1) throw new Error('a phải nguyên tố cùng 26!');

    const a_inv = modInverse(a, 26);
    if (a_inv === -1) throw new Error('Không tìm được nghịch đảo modulo cho a.');

    b = ((b % 26) + 26) % 26;

    return text.replace(/[a-zA-Z]/g, function(c) {
        const base = c <= 'Z' ? 65 : 97;
        const x = c.charCodeAt(0) - base;
        let res;
        if (encrypt) {
            res = (a * x + b) % 26;
        } else {
            res = (a_inv * ((x - b + 26) % 26)) % 26;
        }
        return String.fromCharCode(res + base);
    });
}

// Example usage:
// affineShift('hello', '7,9');
// affineShift('hello', [7,9]);
// affineShift('hello', {a:7, b:9});
