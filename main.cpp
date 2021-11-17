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

    return 0;
}