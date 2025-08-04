#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <string>
#include <vector>
#include "json.hpp"

struct SalesAgent {
    std::string id;
    int performanceScore;
    int seniorityMonths;
    int targetAchievedPercent;
    int activeClients;
};

nlohmann::json allocateDiscount(int kitty, const std::vector<SalesAgent>& agents);

#endif
