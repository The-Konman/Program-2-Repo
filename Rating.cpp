/*
    Title: Rating.cpp  
  Authors: Konnor Lorance, George Vaporis, Madeline Griffin
     Date: 10/4/2024
  Purpose: Rating class definitions and member functions
*/

#include "Rating.h"
    //Getters
    string Rating::getMovieRating() const
    {
        return movieRating;

    }
    int Rating::getBoxOffice() const
    {
        return boxOffice;

    }
    int Rating::getRTScore() const
    {
        return rottenTomatoScore;
    }

    //Setters
    void Rating::setMovieRating(string r)
    {
        movieRating = r;
    }
    void Rating::setBoxOffice(int bO)
    {
        boxOffice = bO;
    }
    void Rating::setRTScore(int rTS)
    {
        rottenTomatoScore = rTS;
    }

    //Default Constructor
    Rating::Rating()
    {
        movieRating = "N/A";
        boxOffice = 0;
        rottenTomatoScore = 0;
    }

    //Overloaded constructor
    Rating::Rating(char r, int bO, int rTS)
    {
        movieRating = r;
        boxOffice = bO;
        rottenTomatoScore = rTS;
    }
