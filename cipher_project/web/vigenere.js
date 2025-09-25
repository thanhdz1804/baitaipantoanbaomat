function vigenereShift(text, key, encrypt = true) {
    if (!key) throw new Error('Khóa không được rỗng!');
    key = key.toUpperCase();
    let keyIdx = 0;
    return text.replace(/[a-zA-Z]/g, function(c) {
        const base = c <= 'Z' ? 65 : 97;
        const k = key.charCodeAt(keyIdx++ % key.length) - 65;
        const shift = encrypt ? k : -k;
        return String.fromCharCode((c.charCodeAt(0) - base + shift + 26) % 26 + base);
    });
}