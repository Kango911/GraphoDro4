#include "Generator.hpp"
#include <vector>

class FixedArticulationPointsGenerator : public Generator {
public:
    FixedArticulationPointsGenerator(int n, int ap) : n_(n), ap_(ap) {}
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        for (int i = 0; i < n_; ++i) g->addVertex(i);
        // Создаем ap точек сочленения, соединяя их последовательно и добавляя по листу
        if (ap_ > 0) {
            for (int i = 0; i < ap_-1; ++i) {
                g->addEdge(i, i+1);
            }
            // Добавляем листья к каждой точке сочленения
            int next = ap_;
            for (int i = 0; i < ap_; ++i) {
                if (next < n_) {
                    g->addEdge(i, next++);
                }
            }
            // Оставшиеся вершины прицепляем куда-нибудь
            while (next < n_) {
                g->addEdge(0, next++);
            }
        } else {
            // Граф без точек сочленения: просто дерево без вершин степени >2? проще цикл
            for (int i = 0; i < n_-1; ++i) g->addEdge(i, i+1);
            if (n_ > 2) g->addEdge(n_-1, 0);
        }
        return g;
    }
private:
    int n_, ap_;
};