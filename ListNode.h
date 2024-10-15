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

        ListNode<T>::setValue(T v)
        {
            value = v;
        }

        //***Next function needs work, not really sure about it 
        ListNode<T>::setNext(T n)
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