#pragma once
#include <unordered_set>
#include <string>

double jaccardSimilarity(
    const std::unordered_set<std::string>& a,
    const std::unordered_set<std::string>& b
);
