#include "file_reader.hpp"
#include "similarity.hpp"
#include <iostream>
#include <vector>
#include <iomanip>



int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " file1.txt file2.txt [...]\n";
        return 1;
    }

    std::vector<std::string> files;
    for (int i = 1; i < argc; ++i) {
        files.emplace_back(argv[i]);
    }

    std::vector<std::unordered_set<std::string>> tokenSets;
    for (const auto& file : files) {
        auto tokens = tokenizeFile(file);
        tokenSets.push_back(tokens);
    }

    std::cout << "\nPlagiarism Report (Jaccard Similarity %):\n";
    std::cout << std::setw(20) << " " << " ";
    for (const auto& f : files) {
        std::cout << std::setw(20) << f;
    }
    std::cout << "\n";

    for (size_t i = 0; i < files.size(); ++i) {
        std::cout << std::setw(20) << files[i] << " ";
        for (size_t j = 0; j < files.size(); ++j) {
            if (i == j) {
                std::cout << std::setw(20) << "-";
            } else {
                double sim = jaccardSimilarity(tokenSets[i], tokenSets[j]) * 100.0;
                std::cout << std::setw(20) << std::fixed << std::setprecision(2) << sim;
            }
        }
        std::cout << "\n";
    }

    return 0;
}
