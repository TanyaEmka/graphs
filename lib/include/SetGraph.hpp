#pragma once
#include <iostream>
#include <cstddef>
#include <vector>
#include <unordered_set>

#include "BasicGraph.hpp"

class SetGraph: public IGraph {
public:
    SetGraph(size_t size);
    SetGraph(const IGraph& new_graph);
    ~SetGraph() override = default;
    virtual void AddEdge(size_t from, size_t to) override;
    virtual size_t VerticesCount() const override;
    virtual std::vector<size_t> GetNextVertices(size_t vertex) const override;
    virtual std::vector<size_t> GetPrevVertices(size_t vertex) const override;
private:
    std::vector<std::unordered_set<size_t>> graph_sets;
};