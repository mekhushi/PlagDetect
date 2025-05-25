#include "similarity.hpp"

double jaccardSimilarity(
    const std::unordered_set<std::string>& a,
    const std::unordered_set<std::string>& b
) {
    if (a.empty() || b.empty()) return 0.0;

    size_t intersection = 0;
    for (const auto& token : a) {
        if (b.count(token)) ++intersection;
    }

    size_t union_size = a.size() + b.size() - intersection;
    return static_cast<double>(intersection) / union_size;
}
