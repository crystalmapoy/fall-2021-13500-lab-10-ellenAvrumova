#pragma once
#include "movie.h"
#include "time.h"

class TimeSlot { 
public: 
    Movie movie;
    Time startTime;
};

void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);