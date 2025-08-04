#include "allocator.h"
#include <iostream>
#include <cassert>

void testEqualAgents() {
    std::vector<SalesAgent> agents = {
        {"A1", 80, 12, 80, 10},
        {"A2", 80, 12, 80, 10}
    };
    auto result = allocateDiscount(10000, agents);
    assert(result["allocations"][0]["assignedDiscount"] == 5000);
    assert(result["allocations"][1]["assignedDiscount"] == 5000);
    std::cout << "✅ testEqualAgents passed\n";
}

void testRoundingEdge() {
    std::vector<SalesAgent> agents = {
        {"A1", 100, 24, 100, 20},
        {"A2", 1, 1, 1, 1}
    };
    auto result = allocateDiscount(10001, agents);
    int total = result["allocations"][0]["assignedDiscount"].get<int>() +
                result["allocations"][1]["assignedDiscount"].get<int>();
    assert(total == 10001);
    std::cout << "✅ testRoundingEdge passed\n";
}

void testNormalCase() {
    std::vector<SalesAgent> agents = {
        {"A1", 90, 18, 85, 12},
        {"A2", 70, 6, 60, 8}
    };
    auto result = allocateDiscount(10000, agents);
    assert(result["allocations"].size() == 2);
    std::cout << "✅ testNormalCase passed\n";
}

int main() {
    testEqualAgents();
    testRoundingEdge();
    testNormalCase();
    std::cout << "🎉 All tests passed!\n
