#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
class ListNode
{
    private:
        T value;         
        ListNode *next; 


    public:

        ListNode<T>::getNode()
        {
           return value;
        }

        ListNode<T>::setNode(T v)
        {
            value = v;
        }

        ListNode<T>::getNext()
        {
            return next;
        }

        ListNode<T>::setNext(ListNode* n)
        {
            next = n;
        }

        ListNode<T>::~ListNode()
        {
            if(ListNode!=NULL)
            {
                delete ListNode;
            }
        }



};


#endif