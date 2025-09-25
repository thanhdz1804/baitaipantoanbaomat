#include <iostream>
#include <string>

std::string vigenereEncrypt(const std::string& plaintext, const std::string& key) {
    if (key.empty()) return "Khóa rỗng";
    std::string ciphertext = "";
    size_t keyLen = key.length();
    size_t keyIdx = 0;
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = toupper(key[keyIdx % keyLen]) - 'A';
            ciphertext += (c - base + k) % 26 + base;
            ++keyIdx;
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

std::string vigenereDecrypt(const std::string& ciphertext, const std::string& key) {
    if (key.empty()) return "Khóa rỗng";
    std::string plaintext = "";
    size_t keyLen = key.length();
    size_t keyIdx = 0;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = toupper(key[keyIdx % keyLen]) - 'A';
            plaintext += (c - base - k + 26) % 26 + base;
            ++keyIdx;
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    std::string text = "Hello World";
    std::string key = "KEY";
    std::string encrypted = vigenereEncrypt(text, key);
    std::string decrypted = vigenereDecrypt(encrypted, key);
    std::cout << "Plaintext: " << text << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}