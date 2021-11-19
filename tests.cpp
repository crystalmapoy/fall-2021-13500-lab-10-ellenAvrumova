/**
 * Author: Ellen Avrumova
 * Course: CSCI-135
 * Instructor: Tong Yi & Mike Zamansky
 * Assignment: Lab 10 A-E
 * 
 * This3 file tests all the functions in time.cpp which holds all the functions of Lab10.
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
#include "time.h"
#include "timeslot.h"
#include "movie.h"

TEST_CASE("TASK A") {
    Time time1;
    time1.h = 9;
    time1.m = 25;
    Time threeFourtyPM;
    threeFourtyPM.h = 15;
    threeFourtyPM.m = 40;
    CHECK(printTime(time1) == "9:25");
    CHECK(printTime(threeFourtyPM) == "15:40");
    CHECK(minutesSinceMidnight(time1) == 565);
    CHECK(minutesSinceMidnight(threeFourtyPM) == 940);
    CHECK(minutesUntil(time1, threeFourtyPM) == 375);
    CHECK(minutesUntil(threeFourtyPM, time1) == -375);
}

TEST_CASE("TASK B") {
    Time eightFifty;
    eightFifty.h = 8;
    eightFifty.m = 50;
    Time fourFifteen;
    fourFifteen.h = 4;
    fourFifteen.m = 15;
    CHECK(printTime(addMinutes(eightFifty, 15)) == "9:05");
    CHECK(printTime(addMinutes(fourFifteen, 45)) == "5:00");
}

TEST_CASE("TASK C") {
    Movie heathers = {"Heathers", COMEDY, 103};
    TimeSlot afternoon = {heathers, {13, 30}};
    CHECK(getTimeSlot(afternoon) == "Heathers COMEDY (103 min)[Starts at 13:30, ends by 15:13]");

    Movie venom = {"Venom: Let There Be Carnage", ACTION, 97};
    TimeSlot evening = {venom, {6, 10}};
    CHECK(getTimeSlot(evening) == "Venom: Let There Be Carnage ACTION (97 min)[Starts at 6:10, ends by 7:47]");
}

TEST_CASE("TASK D") {
    Movie venom = {"Venom: Let There Be Carnage", ACTION, 97};
	Movie heathers = {"Heathers", COMEDY, 103};
	TimeSlot ts = {heathers, {9, 25}};	
	TimeSlot schedule = scheduleAfter(ts, venom);
    CHECK(schedule.startTime.h == 11);
    CHECK(schedule.startTime.m == 8);
	CHECK(getTimeSlot(schedule) == "Venom: Let There Be Carnage ACTION (97 min)[Starts at 11:08, ends by 12:45]");	
    
    Movie blackPanther = {"Black Panther", ACTION, 134};
    Movie noTime = {"No Time To Die", ACTION, 163};
    TimeSlot ts2 = {noTime, {15, 15}};
    TimeSlot schedule2 = scheduleAfter(ts2, blackPanther);
    CHECK(schedule2.startTime.h == 17);
    CHECK(schedule2.startTime.m == 58);
	CHECK(getTimeSlot(schedule2) == "Black Panther ACTION (134 min)[Starts at 17:58, ends by 20:12]");
}