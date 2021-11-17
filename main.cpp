#include <iostream>
#include "time.h"

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

    return 0;
}