//
// Created by Zainab Mohamed Basheer on 18.08.24.
//

#include <Interview_Question2_Answers.cpp>
#include <gtest/gtest.h>

// Test 1: Standardgraph
TEST(DijkstraTest, StandardGraph) {
    std::unordered_map<int, std::unordered_map<int, int>> graph;
    graph = {
            {0, {{1, 4}, {2, 1}}},
            {1, {{3, 1}}},
            {2, {{1, 2}, {3, 5}}},
            {3, {}}
    };

    std::unordered_map<int, int> expected = {
            {0, 0},
            {1, 3},
            {2, 1},
            {3, 4}
    };

    EXPECT_EQ(dijkstra(0,graph), expected);
}

// Test 2: Graph mit einem einzelnen Knoten
TEST(DijkstraTest, SingleNodeGraph) {
    std::unordered_map<int, std::unordered_map<int, int>> graph;
    graph = {{0, {}}};
    std::unordered_map<int, int> expected = {{0, 0}};

    EXPECT_EQ(dijkstra(0, graph), expected);
}

// Test 3: Nicht verbundener Graph
TEST(DijkstraTest, DisconnectedGraph) {
    std::unordered_map<int, std::unordered_map<int, int>> graph;
    graph = {
            {0, {{1, 2}}},
            {1, {}},
            {2, {{3, 1}}},
            {3, {}}
    };

    std::unordered_map<int, int> expected = {
            {0, 0},
            {1, 2},
            {2, std::numeric_limits<int>::max()},
            {3, std::numeric_limits<int>::max()}
    };

    EXPECT_EQ(dijkstra(0, graph), expected);
}

// Test 4: leerer Graph
TEST(DijkstraTest, EmptyGraph) {
    std::unordered_map<int, std::unordered_map<int, int>> graph;

    EXPECT_THROW(dijkstra(0,graph), std::range_error);
}
