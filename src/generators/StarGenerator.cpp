#include "Generator.hpp"

class StarGenerator : public Generator {
public:
    StarGenerator(int n) : n_(n) {}
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        for (int i = 0; i < n_; ++i) g->addVertex(i);
        for (int i = 1; i < n_; ++i) {
            g->addEdge(0, i);
        }
        return g;
    }
private:
    int n_;
};