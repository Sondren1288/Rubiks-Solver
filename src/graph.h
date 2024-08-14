#ifndef GRAPH
#define GRAPH
#include "node.h"
#include <vector>
template <typename T>
class Graph {
    std::vector<Edge<T>> edges;
    std::vector<Node<T>> nodes;

    public:

        Graph(std::vector<Node<T>> nodes);
        bool addNode(Node<T> node);
        bool removeNode(Node<T> node);
        Node<T> getNode(int);
        std::vector<Node<T>> getNeighbours(Node<T> node);
        bool connectNodes(Node<T> n1, Node<T> n2);
        bool disconnectNodes(Node<T> n1, Node<T> n2);

};
#endif
