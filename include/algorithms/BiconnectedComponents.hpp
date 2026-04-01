#ifndef BICONNECTED_COMPONENTS_HPP
#define BICONNECTED_COMPONENTS_HPP

#include "Graph.hpp"
#include <vector>
#include <unordered_set>

// Компоненты рёберной двусвязности (на основе мостов)
std::vector<std::vector<Graph::Edge>> edgeBiconnectedComponents(const Graph& g);

// Компоненты вершинной двусвязности (на основе точек сочленения)
std::vector<std::unordered_set<Graph::Vertex>> vertexBiconnectedComponents(const Graph& g);

#endif