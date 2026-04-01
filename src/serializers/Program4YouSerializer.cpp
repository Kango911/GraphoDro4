#include "Serializer.hpp"
#include <fstream>

class Program4YouSerializer : public Serializer {
public:
    void serialize(const Graph& graph, const std::string& filename) override {
        std::ofstream out(filename);
        if (!out) throw std::runtime_error("Cannot open file");
        // Формат .edges: каждая строка "u v" для неориентированного графа
        for (auto [u, v] : graph.edges()) {
            out << u << " " << v << "\n";
        }
    }
};