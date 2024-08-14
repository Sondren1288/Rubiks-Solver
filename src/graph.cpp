#include <vector>

#include "node.h"
#include "graph.h"


template <typename T>
Graph<T>::Graph(std::vector<Node<T>> nodes) {
    this->nodes = nodes;
}

template <typename T>
bool Graph<T>::addNode(Node<T> node) {
    for (Node<T> n : nodes) {
        if (node == n) {
            return false;
        }
    }
    nodes.push_back(node);
    return true;
}

template <typename T>
bool Graph<T>::removeNode(Node<T> node) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] == node) {
            nodes.erase(i);
            return true;
        }
    }
    return false;
}


