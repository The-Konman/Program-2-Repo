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

        //Overload insertion operator
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


        //Overload comparision operatora
        bool operator>(const Movie& m)
        {
            return this->year > m.year;
        }
        bool operator<(const Movie& m)
        {
            return this->year < m.year;
        }
        bool operator==(const Movie& m)
        {
            return this->year == m.year;
        }
    
        
        //Overload assignment operator 
        Movie& operator=(const Movie& m)
        {
            // Check for self-assignment
            if (this != &m) 
            {
                this->title = m.title;
                this->year = m.year;
                this->genre = m.genre;
                this->movieLength = m.movieLength;
                this->movieRating.setMovieRating(m.movieRating.getMovieRating());
                this->movieRating.setBoxOffice(m.movieRating.getBoxOffice());
                this->movieRating.setRTScore(m.movieRating.getRTScore());
            }
            return *this;
        }

        
};


#endif