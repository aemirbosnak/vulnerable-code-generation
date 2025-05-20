//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    time_t now, travel_time;
    struct tm* current_timeinfo, * travel_timeinfo;
    int year, month, day, hour, minute, second;

    // get current time
    now = time(NULL);
    current_timeinfo = localtime(&now);

    // get the year
    printf("Enter the year you want to travel to: ");
    scanf("%d", &year);

    // get the month
    printf("Enter the month (1-12) you want to travel to: ");
    scanf("%d", &month);

    // get the day
    printf("Enter the day (1-31) you want to travel to: ");
    scanf("%d", &day);

    // get the hour
    printf("Enter the hour (0-23) you want to travel to: ");
    scanf("%d", &hour);

    // get the minute
    printf("Enter the minute (0-59) you want to travel to: ");
    scanf("%d", &minute);

    // get the second
    printf("Enter the second (0-59) you want to travel to: ");
    scanf("%d", &second);

    // set the travel time
    travel_timeinfo = (struct tm*)malloc(sizeof(struct tm));
    travel_timeinfo->tm_year = year - 1900;
    travel_timeinfo->tm_mon = month - 1;
    travel_timeinfo->tm_mday = day;
    travel_timeinfo->tm_hour = hour;
    travel_timeinfo->tm_min = minute;
    travel_timeinfo->tm_sec = second;
    travel_time = mktime(travel_timeinfo);

    // check if the travel time is possible
    if (difftime(travel_time, now) < 0) {
        printf("\nYou cannot travel back in time to the past!\n");
        exit(0);
    }

    // simulate the travel time
    printf("\nTraveling through time...\n\n");
    for (int i = 3; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }

    // print the travel time
    printf("\nYou have arrived at:\n");
    printf("%d-%02d-%02d %02d:%02d:%02d\n", travel_timeinfo->tm_year + 1900, travel_timeinfo->tm_mon + 1, travel_timeinfo->tm_mday,
        travel_timeinfo->tm_hour, travel_timeinfo->tm_min, travel_timeinfo->tm_sec);

    // calculate the time travel difference
    double difference = difftime(travel_time, now);

    // print the time travel difference
    if (difference < 60) {
        printf("You traveled %d seconds into the future!\n", (int)difference);
    }
    else if (difference < 3600) {
        printf("You traveled %.1f minutes into the future!\n", difference / 60);
    }
    else if (difference < 86400) {
        printf("You traveled %.1f hours into the future!\n", difference / 3600);
    }
    else {
        printf("You traveled %.1f days into the future!\n", difference / 86400);
    }

    // free the allocated memory
    free(travel_timeinfo);

    return 0;
}