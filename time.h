/**
 * Author: Ellen Avrumova
 * Course: CSCI-135
 * Instructor: Tong Yi & Mike Zamansky
 * Assignment: Lab 10 A and B
 * 
 * This is the header file for the Time class and all of it's methods.
 * These methods are first used in parts A and B and then used in later parts.
*/

#pragma once

class Time { 
public:
    int h;
    int m;
};

std::string printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
