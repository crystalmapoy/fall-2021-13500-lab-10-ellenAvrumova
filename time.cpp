#include <iostream>
#include <cmath> 
#include "time.h"

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