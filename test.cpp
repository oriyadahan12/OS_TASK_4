#include "Graph.hpp"
#include "EulerCircuit.hpp"
#include <iostream>
#include <cassert>

void testEmptyGraph() {
    Graph graph(0);
    std::cout << "Test: Empty graph\n";
    assert(graph.getVertices() == 0);
    std::cout << "Passed: Empty graph test\n";
}

void testAddEdges() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);

    std::cout << "Test: Adding edges\n";
    assert(graph.getAdjList()[0].size() == 2);
    assert(graph.getAdjList()[1].size() == 2);
    assert(graph.getAdjList()[2].size() == 2);
    assert(graph.getAdjList()[3].size() == 2);
    assert(graph.getAdjList()[4].size() == 2);
    std::cout << "Passed: Adding edges test\n";
}

void testEulerCircuitExists() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);

    std::cout << "Test: Euler circuit exists\n";
    assert(findEulerCircuit(graph, 0) == true);
    std::cout << "Passed: Euler circuit exists test\n";
}

void testEulerCircuitNotExists() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    std::cout << "Test: Euler circuit does not exist\n";
    assert(findEulerCircuit(graph, 0) == false);
    std::cout << "Passed: Euler circuit does not exist test\n";
}

void testSingleVertexNoEdges() {
    Graph graph(1);
    std::cout << "Test: Single vertex with no edges\n";
    assert(findEulerCircuit(graph, 0) == false);
    std::cout << "Passed: Single vertex with no edges test\n";
}

void testDisconnectedGraph() {
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    std::cout << "Test: Disconnected graph\n";
    assert(findEulerCircuit(graph, 0) == false);
    std::cout << "Passed: Disconnected graph test\n";
}

void testLargeEulerianGraph() {
    Graph graph(10);
    for (int i = 0; i < 10; i++) {
        graph.addEdge(i, (i + 1) % 10); // Forming a cycle
        graph.addEdge(i, (i + 2) % 10); // Adding more edges
    }

    std::cout << "Test: Large Eulerian graph\n";
    assert(findEulerCircuit(graph, 0) == true);
    std::cout << "Passed: Large Eulerian graph test\n";
}

int main() {
    testEmptyGraph();
    testAddEdges();
    testEulerCircuitExists();
    testEulerCircuitNotExists();
    testSingleVertexNoEdges();
    testDisconnectedGraph();
    testLargeEulerianGraph();

    std::cout << "All tests passed successfully!\n";
    return 0;
}
