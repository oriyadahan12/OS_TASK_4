// Graph.hpp
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Graph {
private:
    int vertices; // Number of vertices
    std::vector<std::list<int>> adjList; // Adjacency list

public:
    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // For undirected graph
    }

    void printGraph() const {
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << ": ";
            for (auto v : adjList[i]) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }

    const std::vector<std::list<int>>& getAdjList() const {
        return adjList;
    }

    int getVertices() const {
        return vertices;
    }
};

#endif
