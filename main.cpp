#include <iostream>
#include <fstream>
#include "allocator.h"
#include "json.hpp"

using json = nlohmann::json;

int main() {
    std::ifstream inputFile("input.json");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input.json" << std::endl;
        return 1;
    }

    json inputData;
    inputFile >> inputData;
    inputFile.close();

    int siteKitty = inputData["siteKitty"];
    std::vector<SalesAgent> agents;

    for (auto& agent : inputData["salesAgents"]) {
        agents.push_back(SalesAgent{
            agent["id"],
            agent["performanceScore"],
            agent["seniorityMonths"],
            agent["targetAchievedPercent"],
            agent["activeClients"]
        });
    }

    json output = allocateDiscount(siteKitty, agents);

    std::ofstream outputFile("output.json");
    outputFile << output.dump(4);
    outputFile.close();

    std::cout << "Discount allocation completed. Check output.json\n";
    return 0;
}
