#include <iostream>
#include <vector>
#include <functional>
#include <queue>

#include "ArcGraph.hpp"
#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"

std::vector<size_t> BFS(const IGraph &graph) {
    std::vector<size_t> result;
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (size_t i = 0; i < graph.VerticesCount(); i++) {
        if (!visited[i]) {
            std::queue<size_t> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                size_t current = q.front();
                q.pop();
                result.push_back(current);
                for (size_t child: graph.GetNextVertices(current)) {
                    if (!visited[child]) {
                        q.push(child);
                        visited[child] = true;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    ListGraph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 4);
    graph.AddEdge(4, 3);
    std::vector<size_t> result;

    result = BFS(graph);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
    result.clear();

    MatrixGraph matrix(graph);
    result = BFS(graph);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
    result.clear();

    ArcGraph arcs(matrix);
    result = BFS(graph);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
    result.clear();

    SetGraph setGraph(matrix);
    result = BFS(graph);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
    result.clear();

    return 0;
}