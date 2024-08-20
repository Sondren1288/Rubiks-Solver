#include "node.h"


template <typename T>
Node<T>::Node(int id, T value) {
   this->id = id;
   this->value = value;
}

template <typename T>
T Node<T>::getContents() {
    return value;
}

template <typename T>
bool Node<T>::operator==(Node<T> other) {
    if (other.id == id && other.value == value) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
Edge<T>::Edge(Node<T> n1, Node<T> n2) {
    this->n1 = n1;
    this->n2 = n2;
}

template <typename T>
Node<T> Edge<T>::getConnection(Node<T> n) {
    if (n1 == n) {
        return n2;
    } else if (n2 == n) {
        return n1;
    } else {
        return nullptr;
    }
}

