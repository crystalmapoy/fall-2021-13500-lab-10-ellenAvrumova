#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "time.h"
#include "timeslot.h"
#include "movie.h"

TEST_CASE("TASK A") {
    Time eightFifty;
    eightFifty.h = 8;
    eightFifty.m = 50;
    Time threeFifteen;
    threeFifteen.h = 3;
    threeFifteen.m = 15;
    CHECK(printTime(eightFifty) == "8:50");
    CHECK(printTime(addMinutes(eightFifty, 15)) == "9:05");
    CHECK(printTime(addMinutes(threeFifteen, 45)) == "4:00");
    CHECK(minutesSinceMidnight(eightFifty) == 530);
    CHECK(minutesSinceMidnight(threeFifteen) == 195);
}
