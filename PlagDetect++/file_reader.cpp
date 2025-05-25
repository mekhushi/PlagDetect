#include "file_reader.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

std::string cleanToken(const std::string& token) {
    std::string result;
    for (char c : token) {
        if (std::isalnum(c)) result += std::tolower(c);
    }
    return result;
}

std::unordered_set<std::string> tokenizeFile(const std::string& filename) {
    std::unordered_set<std::string> tokens;
    std::ifstream file(filename);
    if (!file.is_open()) return tokens;

    std::string word;
    while (file >> word) {
        std::string cleaned = cleanToken(word);
        if (!cleaned.empty()) tokens.insert(cleaned);
    }

    file.close();
    return tokens;
}
