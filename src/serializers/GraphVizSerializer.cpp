#include "Serializer.hpp"
#include "algorithms/BiconnectedComponents.hpp"
#include <fstream>
#include <random>
#include <unordered_set>

class GraphVizSerializer : public Serializer {
public:
    GraphVizSerializer(bool showSpanningTree = false,
                       bool showRandomCycle = false,
                       bool showEdgeBiconnected = false)
        : showSpanningTree_(showSpanningTree),
          showRandomCycle_(showRandomCycle),
          showEdgeBiconnected_(showEdgeBiconnected) {}

    void serialize(const Graph& graph, const std::string& filename) override {
        std::ofstream out(filename);
        if (!out) throw std::runtime_error("Cannot open file");
        out << (graph.isDirected() ? "digraph G {\n" : "graph G {\n");
        out << "  node [shape=circle];\n";

        // Если нужно показать рёберную двусвязность, получим компоненты
        std::vector<std::vector<Graph::Edge>> edgeComp;
        if (showEdgeBiconnected_) {
            edgeComp = edgeBiconnectedComponents(graph);
        }

        // Вершины
        for (auto v : graph.vertices()) {
            out << "  " << v << ";\n";
        }

        // Рёбра
        for (auto [u, v] : graph.edges()) {
            out << "  " << u << (graph.isDirected() ? " -> " : " -- ") << v;
            if (showEdgeBiconnected_ && !edgeComp.empty()) {
                // Найти компоненту и установить цвет
                int compIdx = -1;
                for (size_t i = 0; i < edgeComp.size(); ++i) {
                    for (auto e : edgeComp[i]) {
                        if ((e.first == u && e.second == v) || (e.first == v && e.second == u)) {
                            compIdx = i;
                            break;
                        }
                    }
                    if (compIdx != -1) break;
                }
                if (compIdx != -1) {
                    out << " [color=\"" << (compIdx % 6 + 1) << "\"]";
                }
            }
            out << ";\n";
        }

        // Если нужно показать остов и случайный цикл, добавим дополнительные элементы
        if (showSpanningTree_) {
            // Найти остов (например, через BFS) и выделить его
            out << "  // Spanning tree edges would be highlighted here\n";
        }
        if (showRandomCycle_) {
            out << "  // Random cycle edges would be highlighted here\n";
        }

        out << "}\n";
    }

private:
    bool showSpanningTree_;
    bool showRandomCycle_;
    bool showEdgeBiconnected_;
};