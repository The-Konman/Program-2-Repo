#include "Stack.h"
#include "ListNode.h"
#include "Movie.h"

void printMenu();

int main()
{

    Stack<Movie> MovieStack;
    int choice;
    do
    {
        printMenu();
        cin >> choice;
        //Validate user input is in the correct range
        while(choice>10||choice<1)
        {
            
                cout << "\nWrong choice, pick a valid option.";
                printMenu();
                cin >> choice;
        }
        //Geeneral switch
        switch(choice)
        {
            case 1:
                
            break;

            case 2:

            break;

            case 3:

            break;
        }
        
    }while(choice!=10);
    





    return 0;
}

void printMenu()
{

    cout << "\n\nWelcome to the Movie Stack Program!";
    cout <<   "\nPlease choose from the following:";
    cout <<   "\n\t1. Add to Movie Stack";
    cout <<   "\n\t2. Remove Current Movie";
    cout <<   "\n\t3. Display the Current Movie";
    cout <<   "\n\t4. Display the Entrie Stack";
    cout <<   "\n\t5. Find Movie";
    cout <<   "\n\t6. Find Oldest";
    cout <<   "\n\t7. Find Newest";
    cout <<   "\n\t8. Sort Movies by Oldest";
    cout <<   "\n\t9. Sort Movies by Newest";
    cout <<   "\n\t10. Delete Movie Stack";
    cout <<   "\n\t11. Leave Program";

    cout << "\n\tChoose 1-10: ";


}
