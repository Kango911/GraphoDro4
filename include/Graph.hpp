#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <memory>
#include <stdexcept>

class Graph {
public:
    using Vertex = int;
    using Edge = std::pair<Vertex, Vertex>;

    explicit Graph(bool directed = false);
    virtual ~Graph() = default;

    // Вершины
    virtual void addVertex(Vertex v);
    virtual void removeVertex(Vertex v);
    virtual bool hasVertex(Vertex v) const;
    virtual size_t vertexCount() const;
    virtual std::vector<Vertex> vertices() const;

    // Рёбра
    virtual void addEdge(Vertex u, Vertex v, double weight = 1.0);
    virtual void removeEdge(Vertex u, Vertex v);
    virtual bool hasEdge(Vertex u, Vertex v) const;
    virtual size_t edgeCount() const;
    virtual std::vector<Edge> edges() const;

    // Соседи
    virtual std::vector<Vertex> neighbors(Vertex v) const;
    virtual size_t degree(Vertex v) const;

    // Свойства
    bool isDirected() const { return directed_; }

    // Кэширование результатов метрик (опционально)
    void invalidateCache() { cacheValid_ = false; }

    // Метрики (возвращают cached или вычисляют)
    double getDensity();
    int getDiameter();
    double getTransitivity();
    int getConnectedComponents();
    int getArticulationPoints();
    int getBridges();
    bool getIsBipartite();
    int getGreedyChromaticNumber();

protected:
    bool directed_;
    std::unordered_map<Vertex, std::unordered_map<Vertex, double>> adj_;

    // Кэш
    mutable bool cacheValid_ = false;
    mutable double cachedDensity_ = 0.0;
    mutable int cachedDiameter_ = -1;
    mutable double cachedTransitivity_ = 0.0;
    mutable int cachedComponents_ = -1;
    mutable int cachedArticulationPoints_ = -1;
    mutable int cachedBridges_ = -1;
    mutable bool cachedBipartite_ = false;
    mutable int cachedGreedyChromatic_ = -1;
};

#endif