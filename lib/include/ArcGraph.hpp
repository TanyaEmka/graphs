#pragma once
#include <iostream>
#include <cstddef>
#include <vector>
#include <unordered_set>

#include "BasicGraph.hpp"

class ArcGraph: public IGraph {
public:
    ArcGraph(size_t size);
    ArcGraph(const IGraph& new_graph);
    ~ArcGraph() override = default;
    virtual void AddEdge(size_t from, size_t to) override;
    virtual size_t VerticesCount() const override;
    virtual std::vector<size_t> GetNextVertices(size_t vertex) const override;
    virtual std::vector<size_t> GetPrevVertices(size_t vertex) const override;
private:
    std::vector<std::pair<size_t, size_t>> graph_arcs;
};