function caesarShift(text, key, encrypt = true) {
    key = parseInt(key);
    if (isNaN(key)) throw new Error('Khóa phải là số!');
    key = (key % 26 + 26) % 26;
    if (!encrypt) key = -key;
    return text.replace(/[a-zA-Z]/g, function(c) {
        const base = c <= 'Z' ? 65 : 97;
        return String.fromCharCode((c.charCodeAt(0) - base + key + 26) % 26 + base);
    });
}