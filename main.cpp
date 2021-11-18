#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main() {
    Time now;
    now.h = 17;
    now.m = 45;
    Time t = { 17, 45 };

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

    Time c = {8, 10};
    printTime(addMinutes(c, 75));
    std::cout << std::endl;

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

    return 0;
}