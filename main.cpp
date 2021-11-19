/**
 * Author: Ellen Avrumova
 * Course: CSCI-135
 * Instructor: Tong Yi & Mike Zamansky
 * Assignment: Lab 10 A-E
 * 
 * This is the main file that runs all the functions in time.cpp.
*/

#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main() {
    std::cout << "***** PART A *****" << std::endl;
    Time now;
    now.h = 17;
    now.m = 45;
    Time t = { 17, 45 };
    std::cout << minutesSinceMidnight(t) << std::endl;

    Time morningLecture = {8, 10};
    Time myAlarm;
    myAlarm = morningLecture;
    std::cout << printTime(morningLecture);
    std::cout << std::endl;
    std::cout << printTime(myAlarm);
    std::cout << std::endl;

    Time a = {10, 30};
    Time b = {13, 40};
    std::cout << minutesUntil(a, b) << std::endl;

    std::cout << std::endl;
    std::cout << "***** PART B *****" << std::endl;
    Time c = {8, 10};
    std::cout << printTime(addMinutes(c, 75));
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "***** PART C *****" << std::endl;
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"No Time To Die", ACTION, 163};
    Movie movie4 = {"Mean Girls", COMEDY, 97};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot afternoon = {movie3, {14, 10}};
    TimeSlot evening = {movie4, {16, 45}}; 

    std::cout << getTimeSlot(morning);
    std::cout << std::endl;
    std::cout <<  getTimeSlot(daytime);
    std::cout << std::endl;
    std::cout << getTimeSlot(afternoon);
    std::cout << std::endl;
    std::cout << getTimeSlot(evening);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "***** PART D *****" << std::endl;
    Movie movie5 = {"Back to the Future", COMEDY, 120};
    Movie movie6 = {"Black Panther", ACTION, 134};
    TimeSlot oneMovie = {movie5, {14, 10}};
    TimeSlot after = scheduleAfter(oneMovie, movie6);
    std::cout << after.startTime.h << ":" << after.startTime.m << std::endl;

    std::cout << std::endl;
    std::cout << "***** PART E *****" << std::endl;
    Movie movie7 = {"Back to the Future", COMEDY, 90};
    TimeSlot first = {movie7, {10, 00}};
    Movie movie8 = {"Black Panther", ACTION, 90};
    TimeSlot second = {movie8, {11, 30}};
    std::cout << timeOverlap(first, second) << std::endl;
    TimeSlot third = {movie8, {11, 29}};
    std::cout << timeOverlap(first, third) << std::endl;

    return 0;
}