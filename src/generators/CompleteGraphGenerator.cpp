#include "Generator.hpp"

class CompleteGraphGenerator : public Generator {
public:
    CompleteGraphGenerator(int n) : n_(n) {}
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        for (int i = 0; i < n_; ++i) g->addVertex(i);
        for (int i = 0; i < n_; ++i) {
            for (int j = i+1; j < n_; ++j) {
                g->addEdge(i, j);
            }
        }
        return g;
    }
private:
    int n_;
};