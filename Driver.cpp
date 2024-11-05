#include "Stack.h"
#include "ListNode.h"
#include "Rating.h"
#include "Movie.h"
#include <iostream>
using namespace std;

void printMenu();
ListNode<Movie>* getTail(ListNode<Movie>*);
ListNode<Movie>* sortAscending(ListNode<Movie>*);
void sortAscendingHelper(ListNode<Movie>*, ListNode<Movie>*);
ListNode<Movie>* partitionAscending(ListNode<Movie>*, ListNode<Movie>*);
ListNode<Movie>* sortDescending(ListNode<Movie>*);
void sortDescendingHelper(ListNode<Movie>*, ListNode<Movie>*);
ListNode<Movie>* partitionDescending(ListNode<Movie>*, ListNode<Movie>*);


int main()
{

    Stack<Movie> MovieStack;
    string genre, title, mR;
    int year, length, numMovies, bO, rT, choice;
    Movie movie;

    do
    {
        ListNode<Movie> *ascendingHead, *descendingHead;
        printMenu();
        cin >> choice;
        //Validate user input is in the correct range
        while(choice>11||choice<1)
        {
                cout << "\nWrong choice, pick a valid option.";
                printMenu();
                cin >> choice;
        }
        //General switch
        switch(choice)
        {
            //Add movie 
            case 1:
                cout << "\n\nWhat is the title of your movie?\t";
                cin.ignore();
                getline(cin, title);
                movie.setTitle(title);
    
                cout << "\n\nWhat genre is " << title << "?\t";
                getline(cin, genre);
                movie.setGenre(genre);

                cout << "\n\nWhat year did " << title << " come out?\t";
                cin >> year;
                movie.setYear(year);

                cout << "\n\nHow long is " << title << " in minutes?\t";
                cin >> length;
                movie.setMovieLength(length);

                cout << "\n\nWhat is " << title << " rated?(G, PG, PG13, M)\t";
                cin >> mR;
                movie.movieRating.setMovieRating(mR);

                cout << "\n\nWhat is " << title << "s box office?\t$";
                cin >> bO;
                movie.movieRating.setBoxOffice(bO);

                cout << "\n\nWhat is " << title << "s rotten tomatoe score?\t%";
                cin >> rT;
                movie.movieRating.setRTScore(rT);

                MovieStack.push(movie);
                cout << "\n\nYour movie has been added." << endl;

                break;
            //Remove the movie at the top of the stack
            case 2:
                cout << "\n\nRemoving the element at the top of the stack!";
                MovieStack.pop();
                break;
            //Display the top movie
            case 3:
                MovieStack.displayNode();
                break;
            //Display the movie stack
            case 4:
                MovieStack.displayStack();
                break;

            //Find movie by title
            case 5:

                break;

            //Find the oldest movie    
            case 6:
                MovieStack.FindOldest();
                break;
            //Find the most recent movie
            case 7:
                MovieStack.FindNewest();
                break;
            //Sort movie stack by oldest
            case 8:
                ascendingHead = MovieStack.getTop();
                ascendingHead = sortAscending(ascendingHead);
                MovieStack.setTop(ascendingHead);              
                break;
            //Sort movie stack by newest
            case 9:
                descendingHead = MovieStack.getTop();
                descendingHead = sortDescending(descendingHead);
                MovieStack.setTop(descendingHead);   
                break; 
            //Delete the entire movie stack
            case 10:
                cout << "\n\nDeleting the stack!";
                MovieStack.deleteStack();
                break;
        }
                
    }while(choice!=11);
    
    cout << "\n\nLeaving the movie stack program. Thanks!\n\n";
    return 0;
}


/*
    Function Name: printMenu()
    Purpose: Displays the user menu
    Return type: void
*/
void printMenu()
{

    cout << "\n\nWelcome to the Movie Stack Program!";
    cout <<   "\nPlease choose from the following:";
    cout <<   "\n\t1. Add to Movie Stack";
    cout <<   "\n\t2. Remove Current Movie";
    cout <<   "\n\t3. Display the Current Movie";
    cout <<   "\n\t4. Display the Entire Stack";
    cout <<   "\n\t5. Find Movie";
    cout <<   "\n\t6. Find Oldest";
    cout <<   "\n\t7. Find Newest";
    cout <<   "\n\t8. Sort Movies by Oldest";
    cout <<   "\n\t9. Sort Movies by Newest";
    cout <<   "\n\t10. Delete Movie Stack";
    cout <<   "\n\t11. Leave Program";
    cout << "\n\tChoose 1-11: ";


}


/*
    Member Function Name: getTail()
    Purpose: Finds the last element of the stack
    Return type: ListNode<Movie>*
*/
ListNode<Movie>* getTail(ListNode<Movie>* temp)
{
    while((temp->getNext()!=NULL)&&(temp != NULL))
    {
        temp = temp->getNext();
    }
    
    return temp;
}

/*
    Function Name: sortAscending()
    Purpose: Uses quick sort algorithm top sort movies by oldest
    Return type: ListNode<Movie>*
*/
ListNode<Movie>* sortAscending(ListNode<Movie>* head)  
{
    if(head!=NULL)
    {
        ListNode<Movie>* tail = getTail(head);
        sortAscendingHelper(head, tail);
    }
    else
    {
        cout << "\n\nThe list is empty!\n";
    }
    return head;
}


/*
    Function Name: sortAscendingHelper()
    Purpose: Finds the pivot of the list of recursively sorts each side before and after the pivot
    Return type: void
*/
void sortAscendingHelper(ListNode<Movie>* head, ListNode<Movie>* tail)  
{
    if((head==NULL)||(head==tail)) 
    {
        return;
    }
    
    //Find the pivot node and return it into pivot
    ListNode<Movie>* pivot = partitionAscending(head, tail);

    //Use recursion to sort left side of list
    sortAscendingHelper(head, pivot);
    
    //Use recursion to sort right side of the list
    sortAscendingHelper(pivot->getNext(), tail);

}


/*
    Function Name: partitionAscending()
    Purpose: Finds pivot and moves everything smaller to the left and everything bigger on the right
    Return type: ListNode<Movie>*
*/
ListNode<Movie>* partitionAscending(ListNode<Movie>* head, ListNode<Movie>* tail)  
{

    ListNode<Movie>* pivot = head;
  
    //Current and previous are used to move the nodes into the left side
    ListNode<Movie>* current = head;
    ListNode<Movie>* previous = head;

    //Go through each node until you get to the node after tail
    while(current != tail->getNext()) 
    {
        //If the current node is less than the current pivot, swap current and previous
        if(current->getNode() < pivot->getNode()) 
        {
            Movie temp = current->getNode();
            current->setNode(previous->getNext()->getNode());
            previous->getNext()->setNode(temp);
            previous = previous->getNext();
        }
        
        //Go to the next node
        current = current->getNext();
    }
    //Swap the data of pivot and previous
    Movie currData = pivot->getNode();
    pivot->setNode(previous->getNode());
    previous->setNode(currData);

    return previous;
}


/*
    Function Name: sortDescending()
    Purpose: Uses quick sort algorithm top sort movies by newest
    Return type: ListNode<Movie>*
*/
ListNode<Movie>* sortDescending(ListNode<Movie>* head)  
{
    if(head!=NULL)
    {
        ListNode<Movie>* tail = getTail(head);
        sortDescendingHelper(head, tail);
    }
    else
    {
        cout << "\n\nThe list is empty!\n";
    }
    return head;
}


/*
    Function Name: sortDescendingHelper()
    Purpose: Finds the pivot of the list of recursively sorts each side before and after the pivot
    Return type: void
*/
void sortDescendingHelper(ListNode<Movie>* head, ListNode<Movie>* tail)  
{
    if((head==NULL)||(head==tail)) 
    {
        return;
    }
    
    //Find the pivot node and return it into pivot
    ListNode<Movie>* pivot = partitionDescending(head, tail);

    //Use recursion to sort left side of list
    sortDescendingHelper(head, pivot);
    
    //Use recursion to sort right side of the list
    sortDescendingHelper(pivot->getNext(), tail);

}


/*
    Function Name: partitionDescending()
    Purpose: Finds pivot and moves everything smaller to the left and everything bigger on the right
    Return type: ListNode<Movie>*
*/
ListNode<Movie>* partitionDescending(ListNode<Movie>* head, ListNode<Movie>* tail)  
{

    ListNode<Movie>* pivot = head;
  
    //Current and previous are used to move the nodes into the left side
    ListNode<Movie>* current = head;
    ListNode<Movie>* previous = head;

    //Go through each node until you get to the node after tail
    while(current != tail->getNext()) 
    {
        //If the current node is larger than the current pivot, swap current and previous
        if(current->getNode() > pivot->getNode()) 
        {
            Movie temp = current->getNode();
            current->setNode(previous->getNext()->getNode());
            previous->getNext()->setNode(temp);
            previous = previous->getNext();
        }
        
        //Go to the next node
        current = current->getNext();
    }
    //Swap the data of pivot and previous
    Movie currData = pivot->getNode();
    pivot->setNode(previous->getNode());
    previous->setNode(currData);

    return previous;
}