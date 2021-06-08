#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <iostream>

template<class T>
class list
{
    Node<T> * head=nullptr;
    Node<T> * tail=nullptr;

    public:

    void insertHead(Node<T> * h)
    {
        if(head == nullptr && tail == nullptr)
        {
            head = h;
            tail = head;
            head->setNext(nullptr);
            head->setPrev(nullptr);
            tail->setPrev(nullptr);
            tail->setNext(nullptr);
        }

        if(head == tail)
        {
            head = h;
            head->setNext(tail);
            head->setPrev(nullptr);
            tail->setNext(nullptr);
            tail->setPrev(head);
        }

        else
        {
            h->setNext(head);
            head = h;
            head->setPrev(nullptr);
        }
    }

    void insertTail(Node<T> * t)
    {
        if(tail == nullptr && head == nullptr)
        {
            head = t;
            tail = t;
            head->setNext(nullptr);
            head->setPrev(nullptr);
            tail->setNext(nullptr);
            tail->setPrev(nullptr);
        }
        if(head == tail)
        {
            tail=t;
            head->setNext(tail);
            head->setPrev(nullptr);
            tail->setNext(nullptr);
            tail->setPrev(head);
        }

        else
        {
            tail->setNext(t);
            t->setPrev(tail);
            tail=t;
            tail->setNext(nullptr);
        }
    }

    void printList()
    {
        if(head == nullptr)
        {
            cout<<"lista vuota ";
            return;
        }

        Node<T> * p = head;
        while(p != nullptr)
        {
            cout<<"|"<< p->getValue()<<"| ";

            p = p->getNext();
        }
        cout<<endl;
    }

    Node<T> * search(T x)
    {
        Node<T> * s = head;
        if(head == nullptr)
        {
            cout<<"la lista e' vuota ";
            return nullptr;
        }

        while(s != nullptr)
        {
            if(s->getValue() == x)
            {
                return s;
            }
            s = s->getNext();
        }

        return s;
    }

    Node<T> * remove(T x)
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        if(head->getValue() == x)
        {
            Node<T> * DeleteNode = head;
            head = head->getNext();
            DeleteNode->setNext(nullptr);
            DeleteNode->setPrev(nullptr);
            return DeleteNode;
        }

        if(tail->getValue() == x)
        {
            Node<T> * DeleteNode = tail;
            tail = tail->getPrev();
            tail->setNext(nullptr);
            DeleteNode->setPrev(nullptr);
            DeleteNode->setNext(nullptr);
            return DeleteNode;
        }
        else
        {
             Node<T> * deleteNode = head;
            while(deleteNode != nullptr)
            {
                if(deleteNode->getValue() == x)
                {
                    deleteNode->getPrev()->setNext(deleteNode->getNext());
                    deleteNode->getNext()->setPrev(deleteNode->getPrev());
                    deleteNode->setNext(nullptr);
                    deleteNode->setPrev(nullptr);
                    return deleteNode;
                }
                deleteNode = deleteNode->getNext();
            }
        }
        return nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }


};
#endif