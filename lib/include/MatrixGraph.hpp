#pragma once
#include <iostream>
#include <cstddef>
#include <vector>

#include "BasicGraph.hpp"

class MatrixGraph: public IGraph {
public:
    MatrixGraph(size_t size);
    MatrixGraph(const IGraph& new_graph);
    ~MatrixGraph() override = default;
    virtual void AddEdge(size_t from, size_t to) override;
    virtual size_t VerticesCount() const override;
    virtual std::vector<size_t> GetNextVertices(size_t vertex) const override;
    virtual std::vector<size_t> GetPrevVertices(size_t vertex) const override;
private:
    std::vector<std::vector<size_t>> graph_matrix;
};