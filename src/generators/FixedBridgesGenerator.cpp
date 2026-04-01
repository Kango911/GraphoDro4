#include "Generator.hpp"
#include <random>
#include <vector>

class FixedBridgesGenerator : public Generator {
public:
    FixedBridgesGenerator(int n, int bridges) : n_(n), bridges_(bridges) {
        if (bridges > n-1) throw std::invalid_argument("too many bridges");
    }
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        for (int i = 0; i < n_; ++i) g->addVertex(i);
        // Создаем цепочку из bridges+1 компонент, соединенных мостами
        std::vector<int> compSizes(bridges+1, 1);
        int remaining = n_ - (bridges+1);
        for (int i = 0; i < remaining; ++i) {
            compSizes[i % (bridges+1)]++;
        }
        int start = 0;
        for (int i = 0; i <= bridges; ++i) {
            int size = compSizes[i];
            for (int j = start; j < start+size-1; ++j) {
                g->addEdge(j, j+1);
            }
            if (i < bridges) {
                g->addEdge(start+size-1, start+size);
            }
            start += size;
        }
        return g;
    }
private:
    int n_, bridges_;
};