// main.cpp
#include "Graph.hpp"
#include "EulerCircuit.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <getopt.h>

// Ensure that all vertices have even degrees
void generateEulerianGraph(Graph &graph, int edges, int seed) {
    srand(seed);
    int vertices = graph.getVertices();

    // Add pairs of edges to ensure all degrees are even
    for (int i = 0; i < edges; i++) {
        int src = rand() % vertices;
        int dest = rand() % vertices;

        // Prevent self-loops and duplicate edges
        while (src == dest || 
               std::find(graph.getAdjList()[src].begin(), graph.getAdjList()[src].end(), dest) != graph.getAdjList()[src].end()) {
            src = rand() % vertices;
            dest = rand() % vertices;
        }

        // Add two edges between src and dest to ensure even degrees
        graph.addEdge(src, dest);
        graph.addEdge(dest, src);
    }
}

int main(int argc, char *argv[]) {
    int vertices = 0, edges = 0, seed = 0;
    int opt;
    while ((opt = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (opt) {
            case 'v':
                vertices = std::atoi(optarg);
                break;
            case 'e':
                edges = std::atoi(optarg);
                break;
            case 's':
                seed = std::atoi(optarg);
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " -v vertices -e edges -s seed\n";
                return EXIT_FAILURE;
        }
    }

    if (vertices <= 0 || edges <= 0) {
        std::cerr << "Vertices and edges must be positive numbers.\n";
        return EXIT_FAILURE;
    }

    Graph graph(vertices);
    generateEulerianGraph(graph, edges, seed);
    graph.printGraph();

    findEulerCircuit(graph, 0);
    return EXIT_SUCCESS;
}
