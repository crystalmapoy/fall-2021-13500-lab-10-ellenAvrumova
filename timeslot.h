/**
 * Author: Ellen Avrumova
 * Course: CSCI-135
 * Instructor: Tong Yi & Mike Zamansky
 * Assignment: Lab 10 C, D, and E
 * 
 * This is the header file for the Movie class and all of it's methods.
 * These methods are first used in parts C, D and E.
*/

#pragma once
#include "movie.h"
#include "time.h"

class TimeSlot { 
public: 
    Movie movie;
    Time startTime;
};

std::string getTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);