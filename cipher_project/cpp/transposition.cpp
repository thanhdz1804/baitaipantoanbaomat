#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isValidKey(const std::string& key) {
    std::string sorted = key;
    std::sort(sorted.begin(), sorted.end());
    for (size_t i = 0; i < key.length(); ++i) {
        if (sorted[i] != '1' + i) return false;
    }
    return true;
}

std::string transpositionEncrypt(const std::string& plaintext, const std::string& key) {
    if (!isValidKey(key)) return "Khóa không hợp lệ";
    int cols = key.length();
    int rows = (plaintext.length() + cols - 1) / cols;
    std::vector<std::string> grid(rows, std::string(cols, 'X'));
    int idx = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (idx < plaintext.length()) grid[r][c] = plaintext[idx++];
        }
    }
    std::string ciphertext = "";
    std::vector<std::pair<char, int>> order;
    for (int i = 0; i < cols; ++i) order.push_back({key[i], i});
    std::sort(order.begin(), order.end());
    for (auto& p : order) {
        int col = p.second;
        for (int r = 0; r < rows; ++r) {
            ciphertext += grid[r][col];
        }
    }
    return ciphertext;
}

std::string transpositionDecrypt(const std::string& ciphertext, const std::string& key) {
    if (!isValidKey(key) || ciphertext.length() % key.length() != 0) return "Khóa hoặc ciphertext không hợp lệ";
    int cols = key.length();
    int rows = ciphertext.length() / cols;
    std::vector<std::string> grid(rows, std::string(cols, ' '));
    std::vector<std::pair<char, int>> order;
    for (int i = 0; i < cols; ++i) order.push_back({key[i], i});
    std::sort(order.begin(), order.end());
    int idx = 0;
    for (auto& p : order) {
        int col = p.second;
        for (int r = 0; r < rows; ++r) {
            grid[r][col] = ciphertext[idx++];
        }
    }
    std::string plaintext = "";
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] != 'X') plaintext += grid[r][c];
        }
    }
    return plaintext;
}

int main() {
    std::string text = "HelloWorld";
    std::string key = "3142";
    std::string encrypted = transpositionEncrypt(text, key);
    std::string decrypted = transpositionDecrypt(encrypted, key);
    std::cout << "Plaintext: " << text << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}