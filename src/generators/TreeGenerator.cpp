#include "Generator.hpp"
#include <random>

class TreeGenerator : public Generator {
public:
    TreeGenerator(int n) : n_(n) {}
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        for (int i = 0; i < n_; ++i) g->addVertex(i);
        // Простое дерево: цепочка
        for (int i = 0; i < n_-1; ++i) {
            g->addEdge(i, i+1);
        }
        return g;
    }
private:
    int n_;
};