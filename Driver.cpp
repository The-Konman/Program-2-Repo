#include "Stack.h"
#include "ListNode.h"
#include "Movie.h"

int main()
{

    Stack<Movie> MovieStack;
    int choice;
    do
    {
        //printMenu();
        //Validate user input is in the correct range
        cin >> choice;
        while(choice>10||choice<1)
        {
            
                cout << "\nWrong choice, pick a valid option.";
                //printMenu();
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