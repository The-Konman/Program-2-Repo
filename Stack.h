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
        ListNode<T>* getTop() const;
        void setTop(ListNode<T>*);
        ListNode<T>* sortAscending(ListNode<T>*);
        void sortAscendingHelper(ListNode<T>*, ListNode<T>*);
        ListNode<T>* partitionAscending(ListNode<T>*, ListNode<T>*);
        void sortDescending();
        void sortDecendingHelper(ListNode<T>*, ListNode<T>*);
        ListNode<T>* partitionDescending(ListNode<T>*, ListNode<T>*);
        ListNode<T>* getTail();
        void push(T);
        void pop();
        bool isEmpty();
        void displayStack();
        void displayNode();
        void deleteStack();
    

};

template <typename T>
void Stack<T>::setTop(ListNode<T>* t)
{
    top = t;
}


template <typename T>
ListNode<T>* Stack<T>::getTop() const
{
    return top;
}


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
            cout << temp->getNode();
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
    ListNode<T>* temp = top;
    while((temp->getNext()!=NULL)&&(temp != NULL))
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
ListNode<T>* Stack<T>::sortAscending(ListNode<T>* head)  
{
    ListNode<T>* tail = getTail();
    sortAscendingHelper(head, tail);
    return head;
}


/*
    Member Function Name: sortAscendingHelper()
    Purpose: Finds the pivot of the list of recursively sorts each side before and after the pivot
    Return type: void
*/
template <typename T>
void Stack<T>::sortAscendingHelper(ListNode<T>* head, ListNode<T>* tail)  
{
    //Something is wrong here, still trying to figure it out
    if((head==NULL)||(head==tail)) 
    {
        cout << "\n\nTEST\n\n";
        return;
    }
    
    // Call partition to find the pivot node
    ListNode<T>* pivot = partitionAscending(head, tail);
    cout << "\n\n\nTEST FOR CURRENT PIVOT\n";
    cout << pivot->getNode();

    // Recursive call for the left part of the list (before the pivot)
    sortAscendingHelper(head, pivot);
    
    // Recursive call for the right part of the list (after the pivot)
    sortAscendingHelper((pivot->getNext()), tail);

}


/*
    Member Function Name: partitionAscending()
    Purpose: Finds tail node, then uses quick sort helper to sort the movies by year in ascending order
    Return type: ListNode<T>*
*/
template <typename T>
ListNode<T>* Stack<T>::partitionAscending(ListNode<T>* head, ListNode<T>* tail)  
{

    ListNode<T>* pivot = head;
  
    // 'pre' and 'curr' are used to shift all 
      // smaller nodes' data to the left side of the pivot node
    ListNode<T>* pre = head;
    ListNode<T>* curr = head;

    // Traverse the list until you reach the node after the tail
    while(curr!=(tail->getNext())) 
    {
        
        if((curr->getNode())<(pivot->getNode())) 
        {
            T temp = curr->getNode();
            curr->getNode() = pre->getNext()->getNode();
            pre->getNext()->getNode() = temp;

            pre = pre->getNext();
        }
        
          // Move 'curr' to the next node
        curr = curr->getNext();
    }
    
    T currData = pivot->getNode();
    pivot->getNode() = pre->getNode();
    pre->getNode() = currData;

    return pre;
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