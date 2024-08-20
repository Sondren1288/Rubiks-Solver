#ifndef NODE
#define NODE
#include <vector>
template <typename T>
class Node {
    int id;
    T value;
    public:
        Node(int id, T value);
        T getContents();
        bool operator==(Node<T> other);
        // Connections?
};
template <typename T>
class Edge {
    public:
        Node<T> n1;
        Node<T> n2;
        Edge(Node<T> n1, Node<T> n2);
        std::vector<Node<T>> getNeighbours();
        Node<T> getConnection(Node<T> n1);
};
#endif
