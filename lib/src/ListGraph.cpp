#include "ListGraph.hpp"

ListGraph::ListGraph(size_t size)
: graph(size) 
{

}

ListGraph::ListGraph(const IGraph &new_graph)
: graph(new_graph.VerticesCount()) 
{
    for (size_t i = 0; i < new_graph.VerticesCount(); i++) {
        graph[i] = new_graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(size_t from, size_t to) {
    graph[from].push_back(to);
}

size_t ListGraph::VerticesCount() const {
    return graph.size();
}

std::vector<size_t> ListGraph::GetNextVertices(size_t vertex) const {
    return graph[vertex];
}

std::vector<size_t> ListGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prev_vertices;
    for (size_t from = 0; from < graph.size(); from++) {
        for (size_t i = 0; i < graph[from].size(); i++) {
            size_t to = graph[from][i];
            if (to == vertex)
                prev_vertices.push_back(from);
        }
    }
    return prev_vertices;
}
