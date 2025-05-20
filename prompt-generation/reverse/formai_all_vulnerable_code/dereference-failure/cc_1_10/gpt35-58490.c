//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to simulate time travel
void timeTravel(int year, int month, int day, int hour, int minute, int second) {
    struct tm *timeinfo;

    // create a time structure and set the date and time to the given values
    timeinfo = (struct tm *) malloc(sizeof(struct tm));
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = minute;
    timeinfo->tm_sec = second;

    // convert the time structure to epoch time
    time_t epochTime = mktime(timeinfo);

    // print the current date and time
    printf("Current date and time: %s", asctime(timeinfo));

    // prompt the user to enter the desired time travel value
    int travelValue;
    printf("\nEnter number of seconds to time travel: ");
    scanf("%d", &travelValue);

    // add the time travel value to the epoch time
    epochTime += travelValue;

    // convert the new epoch time back to a time structure
    timeinfo = localtime(&epochTime);

    // print the new date and time
    printf("New date and time: %s", asctime(timeinfo));
}

int main() {
    // get the current date and time
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);

    // print the current date and time
    printf("Current date and time: %s", asctime(currentTime));

    // prompt the user to enter a date and time to simulate time travel from
    int year, month, day, hour, minute, second;
    printf("\nEnter a date and time to time travel from (YYYY-MM-DD HH:MM:SS): ");
    scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    // simulate time travel
    timeTravel(year, month, day, hour, minute, second);

    return 0;
}