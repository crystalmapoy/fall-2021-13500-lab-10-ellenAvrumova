/**
 * Author: Ellen Avrumova
 * Course: CSCI-135
 * Instructor: Tong Yi & Mike Zamansky
 * Assignment: Lab 10 C, D, and E
 * 
 * This is the header file for the Movie class and all of it's methods.
 * These methods are first used in part C and theen used in later parts.
*/

#pragma once
#include <string>

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    std::string title;
    Genre genre;
    int duration;
};

std::string printMovie(Movie mv);