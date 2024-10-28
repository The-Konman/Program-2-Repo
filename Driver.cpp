#include "Stack.h"
#include "ListNode.h"
#include "Movie.h"

void printMenu();

int main()
{

    Stack<Movie> MovieStack;
    string genre, title, mR;
    int year, length, numMovies, bO, rT, choice;
    Movie movie;

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
            //Remove the movie ad the top of the stack
            case 2:
                //Not sure about this one yet
                MovieStack.pop(movie);
                break;

            case 3:

                break;
        }
        
    }while(choice!=10);
    





    return 0;
}


/*
    Function Name:



*/
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
