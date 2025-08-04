#include "allocator.h"
#include <algorithm>
#include <cmath>

using json = nlohmann::json;

nlohmann::json allocateDiscount(int kitty, const std::vector<SalesAgent>& agents) {
    std::vector<double> weights;
    double totalWeight = 0.0;

    // Normalize each metric (0–1) and calculate weighted score
    for (const auto& agent : agents) {
        double perf = agent.performanceScore / 100.0;
        double senior = std::min(agent.seniorityMonths / 24.0, 1.0); // cap at 2 yrs
        double target = agent.targetAchievedPercent / 100.0;
        double clients = std::min(agent.activeClients / 20.0, 1.0); // cap at 20

        // Weighted sum: performance (0.4), target (0.3), seniority (0.2), clients (0.1)
        double score = 0.4 * perf + 0.3 * target + 0.2 * senior + 0.1 * clients;
        weights.push_back(score);
        totalWeight += score;
    }

    json result;
    result["allocations"] = json::array();

    for (size_t i = 0; i < agents.size(); ++i) {
        double proportion = (totalWeight > 0) ? weights[i] / totalWeight : 1.0 / agents.size();
        int assigned = std::round(proportion * kitty);

        std::string justification;
        if (weights[i] >= 0.75)
            justification = "Top performer with strong all-round contribution.";
        else if (weights[i] >= 0.5)
            justification = "Consistent performance and target achievements.";
        else
            justification = "Moderate performance with room to grow.";

        result["allocations"].push_back({
            {"id", agents[i].id},
            {"assignedDiscount", assigned},
            {"justification", justification}
        });
    }

    return result;
}
