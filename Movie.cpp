/*
    Title: Movie.cpp  
  Authors: Konnor Lorance, George Vaporis, Madeline Griffin
     Date: 
  Purpose: Movie class definitions and member functions
*/

#include "Movie.h"
        //Mutators
        string Movie::getTitle() const
        {
            return title; 
        }
        string Movie::getGenre() const
        {
            return genre;
        }
        int Movie::getYear() const
        {
            return year;
        }
        int Movie::getMovieLength() const
        {
            return movieLength;
        }

        //Setters
        void Movie::setTitle(string t) 
        {
            title = t;
        }
        void Movie::setGenre(string g) 
        {
            genre = g;
        }
        void Movie::setYear(int y) 
        {
            year = y;
        }
        void Movie::setMovieLength(int m) 
        {
            movieLength = m;
        }
        //Default Constructor
        Movie::Movie()
        {
            title = "N/A";
            genre = "N/A";
            movieRating.setBoxOffice(0);
            movieRating.setRTScore(0);
            movieRating.setMovieRating("N/A");
            year = 0;
            movieLength = 0;
        }
        //Overloaded constructor
        Movie::Movie(string t, string g, Rating r, int y,  int mL)
        {
            title = t;
            genre = g;
            movieRating = r;
            year = y;
            movieLength = mL;
        }