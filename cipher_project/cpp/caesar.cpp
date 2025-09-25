#include <iostream>
#include <string>

std::string caesarEncrypt(const std::string& plaintext, int key) {
    std::string ciphertext = "";
    key = (key % 26 + 26) % 26; // Chuẩn hóa khóa cho cả số âm
    for (char c : plaintext) {
        if (isupper(c)) {
            ciphertext += (c - 'A' + key) % 26 + 'A';
        } else if (islower(c)) {
            ciphertext += (c - 'a' + key) % 26 + 'a';
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

std::string caesarDecrypt(const std::string& ciphertext, int key) {
    return caesarEncrypt(ciphertext, -key); // Dịch ngược
}

int main() {
    std::string text = "Hello World";
    int key = 3;
    std::string encrypted = caesarEncrypt(text, key);
    std::string decrypted = caesarDecrypt(encrypted, key);
    std::cout << "Plaintext: " << text << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}