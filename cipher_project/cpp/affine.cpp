#include <iostream>
#include <string>

// Tính GCD
int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// Tìm nghịch đảo modular
int modInverse(int a, int m) {
    for (int x = 1; x < m; ++x) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

std::string affineEncrypt(const std::string& plaintext, int a, int b) {
    if (gcd(a, 26) != 1) return "Khóa a không hợp lệ (phải nguyên tố cùng 26)";
    std::string ciphertext = "";
    b = (b % 26 + 26) % 26;
    for (char c : plaintext) {
        if (isupper(c)) {
            ciphertext += ((a * (c - 'A') + b) % 26) + 'A';
        } else if (islower(c)) {
            ciphertext += ((a * (c - 'a') + b) % 26) + 'a';
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

std::string affineDecrypt(const std::string& ciphertext, int a, int b) {
    if (gcd(a, 26) != 1) return "Khóa a không hợp lệ (phải nguyên tố cùng 26)";
    std::string plaintext = "";
    int a_inv = modInverse(a, 26);
    b = (b % 26 + 26) % 26;
    for (char c : ciphertext) {
        if (isupper(c)) {
            plaintext += (a_inv * ((c - 'A' - b + 26) % 26)) % 26 + 'A';
        } else if (islower(c)) {
            plaintext += (a_inv * ((c - 'a' - b + 26) % 26)) % 26 + 'a';
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    std::string text = "Hello World";
    int a = 5, b = 8;
    std::string encrypted = affineEncrypt(text, a, b);
    std::string decrypted = affineDecrypt(encrypted, a, b);
    std::cout << "Plaintext: " << text << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}