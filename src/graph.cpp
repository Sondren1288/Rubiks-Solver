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

template <typename T>
Node<T> Graph<T>::getNode(int n) {
    for (Node<T> node : nodes) {
        if (node.id == n) {
            return node;
        }
        
    }
    return nullptr;
}

template <typename T>
std::vector<Node<T>> Graph<T>::getNeighbours(Node<T> node) {
    std::vector<Node<T>> retVec = {};
    for (Edge<T> edge : edges) {
        if (edge.n1 == node || edge.n2 == node) {
            retVec.push_back(edge.other(node));
        }
    }
    return retVec;
}

template <typename T>
bool Graph<T>::connectNodes(Node<T> n1, Node<T> n2) {
    for (Node<T> neighbour : getNeighbours(n1)) {
        if (neighbour == n2) {
            return false;
        }
    }
    edges.push_back(Edge<T>(n1, n2));
    return true;
}

template <typename T>
bool Graph<T>::disconnectNodes(Node<T> n1, Node<T> n2) {
    std::vector<Node<T>> neighbours = getNeighbours(n1);
    for (int i = 0; i < neighbours.size(); i++) {
        if (neighbours[i] == n2) {
            edges.erase(i);
            return true;
        }
    }
    return false;
}
