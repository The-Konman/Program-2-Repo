#ifndef MOVIESTACK_H
#define MOVIESTACK_H

#include <iostream>
#include <string>
#include <fstream>
#include "ListNode.h"
using namespace std;


//DELETE LATER, FOR TESTING
//cout << "\nTEST\n";
template <typename T>
class Stack
{
    
    private:
        ListNode<T> *top;
        
    
    public:
        //Constructor prototype
        Stack();
   
        //Destructor prototype
        ~Stack();
   
        //Member function prototypes
        void swap(T, T);
        void sortAscending();
        void sortAscendingHelper(ListNode<T>*, ListNode<T>*);
        ListNode<T>* partitionAscending(ListNode<T>*, ListNode<T>*);
        void sortDescending();
        void sortDecendingHelper(ListNode<T>*, ListNode<T>*);
        ListNode<T>* partitionDecending(ListNode<T>*, ListNode<T>*);
        ListNode<T>* getTail();
        void push(T);
        void pop();
        bool isEmpty();
        void displayStack();
        void displayNode();
        void deleteStack();
    

};


/*
    Member Function Name: Stack()
    Purpose: Constructor for the stack
    Return type: none
*/
template <typename T>
Stack<T>::Stack()
{
    top = NULL;
}


/*
    Member Function Name: ~Stack() (destructor)
    Purpose: Deletes the stack
    Return type: none
*/
template <typename T>
Stack<T>::~Stack()
{
    ListNode<T> *nodePtr, *nextNode;

    //Delete every node in the list until nodePtr gets to NULL
    nodePtr = top;
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->getNext();
        delete nodePtr;
        nodePtr = nextNode;
    }
}

//Still working on this
template <typename T>
void Stack<T>::swap(T first, T second)
{}

/*
    Member Function Name: push()
    Purpose: Adds node to the top of the stack
    Return type: void
*/
template <typename T>
void Stack<T>::push(T item)
{
    ListNode<T> *newNode = NULL;
    newNode = new ListNode<T>;
    newNode->setNode(item);

    //If there aren't any nodes, newNode becomes the first. 
    //If there are nodes, it goes right before the current top and becomes the top
    if(isEmpty())
    {
        top = newNode;
        newNode->setNext(NULL);
    }
    else
    {
        newNode->setNext(top);
        top = newNode;
    }
}
 

/*
    Member Function Name: pop()
    Purpose: Deletes the top node of the stack
    Return type: void
*/
template <typename T>
void Stack<T>::pop()  
{
    ListNode<T> *temp = NULL;

    //If it's not empty, remove the top element and reassign pointers
    if(isEmpty())
    { 
        cout << "\nThe stack is empty.\n";
    }
    else
    {
        temp = top->getNext();
        delete top;
        top = temp;
    }
}


/*
    Member Function Name: deleteStack()
    Purpose: Deletes the top node of the stack
    Return type: void
*/
template <typename T>
void Stack<T>::deleteStack()
{
    ListNode<T> *nodePtr, *nextNode;

    //Delete every node in the list until nodePtr gets to NULL
    nodePtr = top;
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->getNext();
        delete nodePtr;
        nodePtr = nextNode;
    }
    top = NULL;
}


/*
    Member Function Name: isEmpty()
    Purpose: Checks if the stack is empty 
    Return type: bool
*/
template <typename T>
bool Stack<T>::isEmpty()
{
    bool status;

    if(!top)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}


/*
    Member Function Name: displayStack()
    Purpose: Displays the entire stack
    Return type: void
*/
template <typename T>
void Stack<T>::displayStack()
{
    ListNode<T>* temp = top;
    int count = 0;
    if(!(isEmpty()))
    {
        while(temp->getNext()!=NULL)
        {
            count++;
            cout << "\n\nItem #" << count;
            cout << endl << temp->getNode();
            temp = temp->getNext();
        }
        count++;
        cout << "\n\nItem #" << count;
        cout << temp->getNode();
    }
    else
    {
        cout << "\nThe stack is empty.\n";
    }
    
}


/*
    Member Function Name: getTail()
    Purpose: Finds the last element of the stack
    Return type: ListNode<T>*
*/
template <typename T>
ListNode<T>* Stack<T>::getTail()
{
    ListNode<T> temp = top;
    while(temp->getNext()!=NULL)
    {
        temp = temp->getNext();
    }
    return temp;
}

/*
    Member Function Name: sortAscending()
    Purpose: Finds tail node, then uses quick sort helper to sort the movies by year in ascending order
    Return type: void
*/
template <typename T>
void Stack<T>::sortAscending()  
{
    ListNode<T>* tail = getTail();
    sortAscendingHelper(top, tail);
}


/*
    Member Function Name: sortAscendingHelper()
    Purpose: 
    Return type: void
*/
template <typename T>
void Stack<T>::sortAscendingHelper(ListNode<T>* head, ListNode<T>* tail)  
{
    if ((head == NULL)||(head == tail)) 
        return;
    
    // Call partition to find the pivot node
    ListNode<T>* pivot = partitionAscending(head, tail);
    
    // Recursive call for the left part of the list (before the pivot)
    sortAscendingHelper(head, pivot);
    
    // Recursive call for the right part of the list (after the pivot)
    sortAscendingHelper(pivot->next, tail);

}


/*
    Member Function Name: sortAscendingHelper()
    Purpose: Finds tail node, then uses quick sort helper to sort the movies by year in ascending order
    Return type: ListNode<T>*
*/
//Still working on this...
template <typename T>
ListNode<T>* Stack<T>::partitionAscending(ListNode<T>* head, ListNode<T>* tail)  
{

    ListNode<T>* pivot = head;
  
    // 'pre' and 'curr' are used to shift all 
      // smaller nodes' data to the left side of the pivot node
    ListNode<T>* pre = head;
    ListNode<T>* curr = head;

    // Traverse the list until you reach the node after the tail
    while (curr != tail->getNext()) {
        
        if (curr->getNode() < pivot->getNode()) {
            swap(curr->getNode(), pre->getNext()->getNode());
          
              // Move 'pre' to the next node
            pre = pre->getNext();
        }
        
          // Move 'curr' to the next node
        curr = curr->getNext();
    }
    
    //swap(pivot->data, pre->data);
}


/*
    Member Function Name: displayNode()
    Purpose: Displays the current/top node
    Return type: void
*/
template <typename T>
void Stack<T>::displayNode()
{
    if(!(isEmpty()))
    {
        cout << "\nCURRENT NODE:";
        cout << top->getNode();
    }
    else
    {
        cout << "\nThe stack is empty.\n";
    }
}



#endif