#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(size_t size)
: graph_matrix(size) 
{
    for (size_t i = 0; i < graph_matrix.size(); i++) {
        graph_matrix[i].resize(size);
    }
}

MatrixGraph::MatrixGraph(const IGraph &new_graph)
: MatrixGraph(new_graph.VerticesCount()) 
{
    std::vector<size_t> next_vertices;
    for (size_t from = 0; from < new_graph.VerticesCount(); from++) {
        next_vertices = new_graph.GetNextVertices(from);
        for (auto &to: next_vertices) {
            graph_matrix[from][to] = 1;
        }
    }
}

void MatrixGraph::AddEdge(size_t from, size_t to) {
    graph_matrix[from][to] = 1;
}

size_t MatrixGraph::VerticesCount() const {
    return graph_matrix.size();
}

std::vector<size_t> MatrixGraph::GetNextVertices(size_t vertex) const {
    std::vector<size_t> next_vertices;
    for (size_t to = 0; to < graph_matrix.size(); to++) {
        if (graph_matrix[vertex][to] == 1) 
            next_vertices.push_back(to);
    }
    return next_vertices;
}

std::vector<size_t> MatrixGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prev_vertices;
    for (size_t from = 0; from < graph_matrix.size(); from++) {
        if (graph_matrix[from][vertex] == 1)
            prev_vertices.push_back(from);
    }
    return prev_vertices;
}
