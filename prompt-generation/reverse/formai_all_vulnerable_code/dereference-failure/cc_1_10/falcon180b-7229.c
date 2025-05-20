//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE 1

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

int travel_time(Time *destination) {
    time_t current_time = time(NULL);
    struct tm current_tm = *localtime(&current_time);
    struct tm destination_tm = *localtime(mktime(destination));

    if (destination_tm.tm_year < current_tm.tm_year ||
        (destination_tm.tm_year == current_tm.tm_year &&
         destination_tm.tm_mon < current_tm.tm_mon) ||
        (destination_tm.tm_year == current_tm.tm_year &&
         destination_tm.tm_mon == current_tm.tm_mon &&
         destination_tm.tm_mday < current_tm.tm_mday)) {
        printf("Cannot travel to the past.\n");
        return TIME_TRAVEL_FAILURE;
    }

    return TIME_TRAVEL_SUCCESS;
}

void print_time(Time time) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n",
           time.year, time.month, time.day, time.hour, time.minute, time.second);
}

int main() {
    Time current_time;
    time(&current_time);

    printf("Current time: ");
    print_time(current_time);

    Time destination_time;
    printf("Enter destination time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%04d-%02d-%02d %02d:%02d:%02d",
           &destination_time.year, &destination_time.month, &destination_time.day,
           &destination_time.hour, &destination_time.minute, &destination_time.second);

    int result = travel_time(&destination_time);

    if (result == TIME_TRAVEL_SUCCESS) {
        printf("Time travel successful.\n");
        printf("Destination time: ");
        print_time(destination_time);
    } else {
        printf("Time travel failed.\n");
    }

    return 0;
}