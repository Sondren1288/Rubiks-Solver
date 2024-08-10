#ifndef NODE
#define NODE
#include <vector>
template <typename T>
class Node {
    public:
        Node(T value, std::vector<Node> connections);
        std::vector<Node> getNeighbours();
        T getNode();
        
};
#endif
