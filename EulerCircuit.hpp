#ifndef EULER_CIRCUIT_HPP
#define EULER_CIRCUIT_HPP

#include "Graph.hpp"
#include <stack>
#include <iostream>

bool isEulerianCircuitPossible(const Graph &graph) {
    const auto &adjList = graph.getAdjList();
    for (const auto &neighbors : adjList) {
        if (neighbors.size() % 2 != 0) {
            return false; // All vertices must have even degrees
        }
    }
    return true;
}

bool findEulerCircuit(Graph &graph, int start) {
    if (!isEulerianCircuitPossible(graph)) {
        std::cout << "Euler circuit is not possible in the given graph.\n";
        return false;
    }

    std::stack<int> currentPath, circuit;
    currentPath.push(start);
    auto adjList = graph.getAdjList(); // Copy to modify during traversal

    while (!currentPath.empty()) {
        int u = currentPath.top();
        if (!adjList[u].empty()) {
            int v = adjList[u].front();
            currentPath.push(v);
            adjList[u].remove(v);
            adjList[v].remove(u);
        } else {
            circuit.push(u);
            currentPath.pop();
        }
    }

    std::cout << "Euler Circuit: ";
    while (!circuit.empty()) {
        std::cout << circuit.top() << " ";
        circuit.pop();
    }
    std::cout << std::endl;

    return true;
}

#endif
