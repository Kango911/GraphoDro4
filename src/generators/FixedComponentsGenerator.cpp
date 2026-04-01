#include "Generator.hpp"
#include <random>

class FixedComponentsGenerator : public Generator {
public:
    FixedComponentsGenerator(int n, int comp) : n_(n), comp_(comp) {
        if (comp > n) throw std::invalid_argument("components > vertices");
    }
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        for (int i = 0; i < n_; ++i) g->addVertex(i);
        // Разделить вершины на comp компонент, внутри каждой - дерево (например, путь)
        int base = n_ / comp_;
        int rem = n_ % comp_;
        int start = 0;
        for (int c = 0; c < comp_; ++c) {
            int size = base + (c < rem ? 1 : 0);
            for (int i = start; i < start+size-1; ++i) {
                g->addEdge(i, i+1);
            }
            start += size;
        }
        return g;
    }
private:
    int n_, comp_;
};