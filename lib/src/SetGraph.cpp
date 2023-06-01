#include "SetGraph.hpp"

SetGraph::SetGraph(size_t size)
: graph_sets(size) 
{

}

SetGraph::SetGraph(const IGraph &new_graph)
: graph_sets(new_graph.VerticesCount()) 
{
    std::vector<size_t> next_vertices;
    for (size_t i = 0; i < new_graph.VerticesCount(); i++) {
        next_vertices = new_graph.GetNextVertices(i);
        graph_sets[i] = std::unordered_set<size_t>(next_vertices.begin(), next_vertices.end());
    }
}

void SetGraph::AddEdge(size_t from, size_t to) {
    graph_sets[from].insert(to);
}

size_t SetGraph::VerticesCount() const {
    return graph_sets.size();
}

std::vector<size_t> SetGraph::GetNextVertices(size_t vertex) const {
    return std::vector<size_t>(graph_sets[vertex].begin(), graph_sets[vertex].end());
}

std::vector<size_t> SetGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prev_vertices;
    for (size_t from = 0; from < graph_sets.size(); from++) {
        for (size_t to: graph_sets[from]) {
            if (to == vertex)
                prev_vertices.push_back(from);
        }
    }
    return prev_vertices;
}
