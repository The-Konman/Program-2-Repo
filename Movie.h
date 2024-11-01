/*
    Title: Movie.h
  Authors: Konnor Lorance, George Vaporis, Madeline Griffin
     Date: 
  Purpose: Movie class header file
*/

#ifndef MOVIE_H
#define MOVIE_H

#include "Rating.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Movie {

    private:
        string title;
        string genre;
        int year;
        int movieLength;

    public:
        Rating movieRating;
        //Getter prototypes
        string getTitle() const;
        string getGenre() const;
        int getYear() const;
        int getMovieLength() const;
        Movie getUserInput() const;
        //Setter prototypes
        void setTitle(string);
        void setGenre(string);
        void setYear(int);
        void setMovieLength(int);

        //Constructor prototype
        Movie();
        Movie(string, string, Rating, int, int);

        friend std::ostream& operator<<(std::ostream& os, const Movie& m)
        {
            os << "\nTitle: " << m.title;
            os << "\nGenre: " << m.genre;
            os << "\nYear: " << m.year;
            os << "\nLength: " << m.movieLength;
            os << "\nRating: " << m.movieRating.getMovieRating();
            os << "\nBox Office: " << m.movieRating.getBoxOffice();
            os << "\nRotten Tomatoe Score: " << m.movieRating.getRTScore();
            return os;
        }

};


#endif