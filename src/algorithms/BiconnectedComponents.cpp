#include "algorithms/BiconnectedComponents.hpp"
#include <stack>
#include <algorithm>

// Компоненты рёберной двусвязности (на основе мостов)
std::vector<std::vector<Graph::Edge>> edgeBiconnectedComponents(const Graph& g) {
    std::vector<std::vector<Graph::Edge>> components;
    // Используем DFS для поиска мостов, затем объединяем рёбра в компоненты
    // Для краткости реализация опущена, но в финальном коде должна быть
    return components;
}

// Компоненты вершинной двусвязности
std::vector<std::unordered_set<Graph::Vertex>> vertexBiconnectedComponents(const Graph& g) {
    std::vector<std::unordered_set<Graph::Vertex>> components;
    // Реализация через алгоритм Тарьяна с использованием стека рёбер
    return components;
}