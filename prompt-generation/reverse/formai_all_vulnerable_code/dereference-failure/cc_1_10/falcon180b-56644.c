//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TIME_TRAVELS 100
#define MAX_TIME_TRAVEL_LENGTH 100

struct time_travel {
    int length;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

int main(int argc, char *argv[]) {
    struct time_travel time_travels[MAX_TIME_TRAVELS];
    int num_time_travels = 0;

    srand(time(NULL));

    while (num_time_travels < MAX_TIME_TRAVELS) {
        int length = rand() % MAX_TIME_TRAVEL_LENGTH + 1;
        time_t now = time(NULL);
        struct tm *tm = localtime(&now);

        time_travels[num_time_travels].length = length;
        time_travels[num_time_travels].year = tm->tm_year + length;
        time_travels[num_time_travels].month = tm->tm_mon + length / 12;
        time_travels[num_time_travels].day = tm->tm_mday + length / (24 * 365.25);
        time_travels[num_time_travels].hour = tm->tm_hour;
        time_travels[num_time_travels].minute = tm->tm_min;
        time_travels[num_time_travels].second = tm->tm_sec;

        num_time_travels++;
    }

    for (int i = 0; i < num_time_travels; i++) {
        printf("Time travel #%d: ", i + 1);
        printf("%d years, ", time_travels[i].length);
        printf("%d-%d-%d ", time_travels[i].year % 100, time_travels[i].month % 100, time_travels[i].day % 100);
        printf("%d:%d:%d\n", time_travels[i].hour, time_travels[i].minute, time_travels[i].second);
    }

    return 0;
}