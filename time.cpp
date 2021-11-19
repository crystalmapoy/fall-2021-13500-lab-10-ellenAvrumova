#include <iostream>
#include <cmath> 
#include <string>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

std::string printTime(Time time) {
    if(time.m < 10) {
        return std::to_string(time.h) + ":0" + std::to_string(time.m);
    }
    else {
        return std::to_string(time.h) + ":" + std::to_string(time.m);
    }
}

int minutesSinceMidnight(Time time) {
    return (time.h * 60) + time.m;
}

int minutesUntil(Time earlier, Time later) {
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
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

std::string printMovie(Movie mv) {
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTimeSlot(TimeSlot ts) {
    std::string movie = printMovie(ts.movie);
    std::string time = "[Starts at " + printTime(ts.startTime) + ", ends by " + printTime(addMinutes(ts.startTime, ts.movie.duration)) + "]";
    return movie + time;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    TimeSlot after;
    after.startTime = addMinutes(ts.startTime, ts.movie.duration);
    after.movie.title = nextMovie.title;
    return after;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    std::cout.setf(std::ios::boolalpha);
    if(minutesSinceMidnight(ts2.startTime) > minutesSinceMidnight(ts1.startTime) &&  minutesSinceMidnight(ts2.startTime) < (minutesSinceMidnight(addMinutes(ts1.startTime, ts1.movie.duration)))) {
        return true;
    }
    else if (minutesSinceMidnight(ts1.startTime) > minutesSinceMidnight(ts2.startTime) &&  minutesSinceMidnight(ts1.startTime) < (minutesSinceMidnight(addMinutes(ts2.startTime, ts2.movie.duration)))) {
        return true;
    }
    return false;
}