using namespace std;
#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    Node<T> * next;
    Node<T> * prev;
    T value;

    public:
    
    Node(Node<T> * next, Node<T> * prev, T value) : next(next), prev(prev), value(value){}
    Node( T value) : Node(value, nullptr, nullptr){}

    Node<T> * getNext()
    {
        return next;
    }

    Node<T> * getPrev()
    {
        return prev;
    }

    T getValue()
    {
        return value;
    }

    void setNext(Node<T> * n)
    {
        this->next = n;
    }

    void setPrev(Node<T> * n)
    {
        this->prev = n;
    }

    void setValue(T n)
    {
        this->value = n;
    }

};
#endif