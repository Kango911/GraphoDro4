#include "Generator.hpp"
#include <vector>

class FixedTwoBridgesGenerator : public Generator {
public:
    FixedTwoBridgesGenerator(int n, int twoBridges) : n_(n), twoBridges_(twoBridges) {}
    std::unique_ptr<Graph> generate() override {
        auto g = std::make_unique<Graph>(false);
        for (int i = 0; i < n_; ++i) g->addVertex(i);
        // Создаем граф, содержащий заданное число 2-мостов (рёбер, принадлежащих всем циклам)
        // Для простоты: создаем цепочку из блоков, каждый блок — это K4 минус ребро и т.п.
        // Здесь просто заглушка
        return g;
    }
private:
    int n_, twoBridges_;
};