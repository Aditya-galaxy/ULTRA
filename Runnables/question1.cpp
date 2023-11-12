#include "path/to/Dijkstra.h"
#include "path/to/FloridaGraph.h" 
#include <iostream>
#include <ctime>

int main() {

    FloridaGraphType floridaGraph;
    const int numPairs = 200;
    std::srand(std::time(nullptr));

    double totalRuntime = 0.0;

    for (int i = 0; i < numPairs; ++i) {
 
        VertexType source = std::rand() % floridaGraph.numVertices();
        VertexType destination = std::rand() % floridaGraph.numVertices();

        Dijkstra<FloridaGraphType> dijkstraAlgorithm(floridaGraph);

        clock_t start = clock();
        dijkstraAlgorithm.run(source, destination);
        clock_t end = clock();

        double runtimeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        totalRuntime += runtimeInSeconds;
    }
    std::cout << "Total runtime in seconds for " << numPairs << " random Dijkstra: " << totalRuntime << std::endl;

    return 0;
}
