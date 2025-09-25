#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class Playfair {
private:
    std::vector<std::vector<char>> matrix;
    std::pair<int, int> findPos(char c) {
        c = toupper(c) == 'J' ? 'I' : toupper(c);
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (matrix[i][j] == c) return {i, j};
            }
        }
        return {-1, -1};
    }

public:
    Playfair(const std::string& key) {
        std::string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
        std::string uniqueKey = "";
        std::vector<bool> used(26, false);
        for (char c : key) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            if (isalpha(c) && !used[c - 'A']) {
                uniqueKey += c;
                used[c - 'A'] = true;
            }
        }
        for (char c : alphabet) {
            if (!used[c - 'A']) uniqueKey += c;
        }
        matrix.resize(5, std::vector<char>(5));
        int idx = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                matrix[i][j] = uniqueKey[idx++];
            }
        }
    }

    std::string encrypt(const std::string& plaintext) {
        std::string prepared = "";
        for (char c : plaintext) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            if (isalpha(c)) prepared += c;
        }
        for (size_t i = 0; i < prepared.length(); i += 2) {
            if (i == prepared.length() - 1) {
                prepared += 'X';
            } else if (prepared[i] == prepared[i+1]) {
                prepared.insert(i+1, "X");
            }
        }
        std::string ciphertext = "";
        for (size_t i = 0; i < prepared.length(); i += 2) {
            auto [r1, c1] = findPos(prepared[i]);
            auto [r2, c2] = findPos(prepared[i+1]);
            if (r1 == r2) {
                ciphertext += matrix[r1][(c1 + 1) % 5];
                ciphertext += matrix[r2][(c2 + 1) % 5];
            } else if (c1 == c2) {
                ciphertext += matrix[(r1 + 1) % 5][c1];
                ciphertext += matrix[(r2 + 1) % 5][c2];
            } else {
                ciphertext += matrix[r1][c2];
                ciphertext += matrix[r2][c1];
            }
        }
        return ciphertext;
    }

    std::string decrypt(const std::string& ciphertext) {
        if (ciphertext.length() % 2 != 0) return "Ciphertext không hợp lệ";
        std::string plaintext = "";
        for (size_t i = 0; i < ciphertext.length(); i += 2) {
            auto [r1, c1] = findPos(ciphertext[i]);
            auto [r2, c2] = findPos(ciphertext[i+1]);
            if (r1 == r2) {
                plaintext += matrix[r1][(c1 - 1 + 5) % 5];
                plaintext += matrix[r2][(c2 - 1 + 5) % 5];
            } else if (c1 == c2) {
                plaintext += matrix[(r1 - 1 + 5) % 5][c1];
                plaintext += matrix[(r2 - 1 + 5) % 5][c2];
            } else {
                plaintext += matrix[r1][c2];
                plaintext += matrix[r2][c1];
            }
        }
        // Loại bỏ 'X' padding
        std::string result = "";
        for (size_t i = 0; i < plaintext.length(); ++i) {
            if (i < plaintext.length() - 1 && plaintext[i+1] == 'X' && i % 2 == 0) {
                result += plaintext[i];
                ++i;
            } else {
                result += plaintext[i];
            }
        }
        if (result.back() == 'X') result.pop_back();
        return result;
    }
};

int main() {
    std::string key = "PLAYFAIR";
    Playfair pf(key);
    std::string text = "Hello";
    std::string encrypted = pf.encrypt(text);
    std::string decrypted = pf.decrypt(encrypted);
    std::cout << "Plaintext: " << text << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}