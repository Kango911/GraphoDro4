#include "Generator.hpp"

class WheelGenerator : public Generator {
public:
    WheelGenerator(int n) : n_(n) {} // n >= 4
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        for (int i = 0; i < n_; ++i) g->addVertex(i);
        // цикл на вершинах 1..n-1
        for (int i = 1; i < n_-1; ++i) g->addEdge(i, i+1);
        if (n_ > 3) g->addEdge(n_-1, 1);
        // центральная вершина 0 соединяется со всеми
        for (int i = 1; i < n_; ++i) g->addEdge(0, i);
        return g;
    }
private:
    int n_;
};