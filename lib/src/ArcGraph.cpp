#include "ArcGraph.hpp"

ArcGraph::ArcGraph(size_t size)
: graph_arcs(size * size) 
{

}

ArcGraph::ArcGraph(const IGraph &new_graph)
: graph_arcs(new_graph.VerticesCount() * new_graph.VerticesCount()) 
{
    std::vector<size_t> next_vertices;
    for (size_t from = 0; from < new_graph.VerticesCount(); from++) {
        next_vertices = new_graph.GetNextVertices(from);
        for (auto &to: next_vertices)
            graph_arcs.push_back(std::pair<size_t, size_t>(from, to));
    }
}

void ArcGraph::AddEdge(size_t from, size_t to) {
    graph_arcs.push_back(std::pair<size_t, size_t>(from, to));
}

size_t ArcGraph::VerticesCount() const {
    std::unordered_set<size_t> vertices;
    for (const auto &vertex: graph_arcs) {
        vertices.insert(vertex.first);
        vertices.insert(vertex.second);
    }
    return vertices.size();
}

std::vector<size_t> ArcGraph::GetNextVertices(size_t vertex) const {
    std::vector<size_t> next_vertices;
    for (const auto &value: graph_arcs) {
        if (value.first == vertex)
            next_vertices.push_back(value.second);
    }
    return next_vertices;
}

std::vector<size_t> ArcGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prev_vertices;
    for (const auto &value: graph_arcs) {
        if (value.second == vertex)
            prev_vertices.push_back(value.first);
    }
    return prev_vertices;
}
