#include "Generator.hpp"

class HalinGraphGenerator : public Generator {
public:
    HalinGraphGenerator(int n) : n_(n) {} // n >= 4
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        // Захардкоженный пример для n=4: колесо W4 (K1,3 + цикл)
        if (n_ == 4) {
            for (int i = 0; i < 4; ++i) g->addVertex(i);
            g->addEdge(0,1); g->addEdge(0,2); g->addEdge(0,3);
            g->addEdge(1,2); g->addEdge(2,3); g->addEdge(3,1);
        } else {
            // Для других n можно генерировать общий случай: дерево без вершин степени 2, затем цикл по листьям
            throw std::runtime_error("Halin graph generation for n != 4 not implemented");
        }
        return g;
    }
private:
    int n_;
};