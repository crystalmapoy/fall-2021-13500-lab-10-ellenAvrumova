#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main() {
    std::cout << "***** PART A *****" << std::endl;
    Time test;
    test.h = 8;
    test.m = 50;
    printTime(addMinutes(test, 15));
    std::cout << std::endl;

    Time now;
    now.h = 17;
    now.m = 45;
    Time t = { 17, 45 };
    std::cout << minutesSinceMidnight(t) << std::endl;

    Time morningLecture = {8, 10};
    Time myAlarm;
    myAlarm = morningLecture;
    printTime(morningLecture);
    std::cout << std::endl;
    printTime(myAlarm);
    std::cout << std::endl;

    Time a = {10, 30};
    Time b = {13, 40};
    std::cout << minutesUntil(a, b) << std::endl;

    std::cout << std::endl;
    std::cout << "***** PART B *****" << std::endl;
    Time c = {8, 10};
    printTime(addMinutes(c, 75));
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "***** PART C *****" << std::endl;
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}}; 

    printTimeSlot(morning);
    std::cout << std::endl;
    printTimeSlot(daytime);
    std::cout << std::endl;
    printTimeSlot(evening);
    std::cout << std::endl;

    Movie movie3 = {"Heathers", COMEDY, 103};
    TimeSlot afternoon = {movie3, {13, 30}};
    Movie movie4 = {"Mean Girls", COMEDY, 97};
    TimeSlot eveningTime = {movie4, {15, 20}};

    printTimeSlot(afternoon);
    std::cout << std::endl;
    printTimeSlot(eveningTime);
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