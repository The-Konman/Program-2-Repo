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
        //Getters
        T getNode()
        {
           return value;
        } 

        ListNode* getNext()
        {
            return next;
        }

        //Setters
        void setNode(T v)
        {
            value = v;
        }  

        void setNext(ListNode* n)
        {
            next = n;
        }

        //Constructor
        ListNode(T v)
        {
            value = v;
            this->next = NULL;
        }

        //Default constructor
        ListNode()
        {
            this->next = NULL;
        }



};


#endif