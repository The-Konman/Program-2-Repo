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


int main()
{

    Stack<Movie> MovieStack;
    string genre, title, mR;
    int year, length, numMovies, bO, rT, choice;
    Movie movie;

    do
    {
        ListNode<Movie>* head;
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

                break;
            //Find the most recent movie
            case 7:

                break;
            //Sort movie stack by oldest
            case 8:
                head = MovieStack.getTop();
                head = sortAscending(head);
                MovieStack.setTop(head);              
                break;
            //Sort movie stack by newest
            case 9:
                //MovieStack.sortDescending();
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
    cout << "\n\tChoose 1-10: ";

}


/*
    Member Function Name: getTail()
    Purpose: Finds the last element of the stack
    Return type: ListNode<T>*
*/
ListNode<Movie>* getTail(ListNode<Movie>* temp)
{
    while((temp->getNext()!=NULL)&&(temp != NULL))
    {
        temp = temp->getNext();
    }
    
    return temp;
}


ListNode<Movie>* sortAscending(ListNode<Movie>* head)  
{
    ListNode<Movie>* tail = getTail(head);
    sortAscendingHelper(head, tail);
    return head;
}


/*
    Member Function Name: sortAscendingHelper()
    Purpose: Finds the pivot of the list of recursively sorts each side before and after the pivot
    Return type: void
*/
void sortAscendingHelper(ListNode<Movie>* head, ListNode<Movie>* tail)  
{
    //Something is wrong here, still trying to figure it out
    if((head==NULL)||(head==tail)) 
    {
        return;
    }
    
    // Call partition to find the pivot node
    ListNode<Movie>* pivot = partitionAscending(head, tail);

    // Recursive call for the left part of the list (before the pivot)
    sortAscendingHelper(head, pivot);
    
    // Recursive call for the right part of the list (after the pivot)
    sortAscendingHelper(pivot->getNext(), tail);

}


/*
    Member Function Name: partitionAscending()
    Purpose: Finds tail node, then uses quick sort helper to sort the movies by year in ascending order
    Return type: ListNode<T>*
*/
ListNode<Movie>* partitionAscending(ListNode<Movie>* head, ListNode<Movie>* tail)  
{

    ListNode<Movie>* pivot = head;
  
    // 'pre' and 'curr' are used to shift all 
      // smaller nodes' data to the left side of the pivot node
    ListNode<Movie>* pre = head;
    ListNode<Movie>* curr = head;

    // Traverse the list until you reach the node after the tail
    while(curr != tail->getNext()) 
    {
        if(curr->getNode() < pivot->getNode()) 
        {
            Movie temp = curr->getNode();
            curr->setNode(pre->getNext()->getNode());
            pre->getNext()->setNode(temp);
            //RIght here konnor
            pre = pre->getNext();
        }
        
          // Move 'curr' to the next node
        curr = curr->getNext();
    }
    
    Movie currData = pivot->getNode();
    pivot->setNode(pre->getNode());
    pre->setNode(currData);

    return pre;
}