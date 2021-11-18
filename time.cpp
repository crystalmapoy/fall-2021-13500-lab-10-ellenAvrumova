#include <iostream>
#include <cmath> 
#include <string>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

void printTime(Time time) {
    std::cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time) {
    int hoursToMinutes;
    int minutes;
    if(time.h > 12) {
        hoursToMinutes = (12 + (time.h-12)) * 60;
    }
    else {
        hoursToMinutes = (12 - time.h) * 60;
    }
    minutes = 60 - time.m;

    return hoursToMinutes + minutes;
}

int minutesUntil(Time earlier, Time later) {
    int hoursToMinutes;
    int minutes;
    if(earlier.h > 12 && later.h < 10) {
        hoursToMinutes = (12 - earlier.h - later.h) * 60;
    }
    else if(earlier.h > later.h) {
        hoursToMinutes = 12 - (earlier.h - later.h);
    }
    else {
        hoursToMinutes = (later.h - earlier.h) * 60;
    }
    if(earlier.m < later.m) {
        minutes = later.m - earlier.m;
    }
    else {
        minutes = (earlier.m - later.m);
    }

    return hoursToMinutes + minutes;
}

Time addMinutes(Time time0, int min) {
    Time time;
    if(time0.m + min >= 60) {
        time.h = time0.h + ((time0.m + min)/60);
        time.m = (time0.m + min) % 60;
    }
    else {
        time.m = time0.m + min;
    }
    return time;
}

void printMovie(Movie mv) {
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts) {
    printMovie(ts.movie);
    std::cout << "[Starts at ";
    printTime(ts.startTime);
    std::cout << ", ends by ";
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    printTime(endTime);
    std::cout << "]";
}