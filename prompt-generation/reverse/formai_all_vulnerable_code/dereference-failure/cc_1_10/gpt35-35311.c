//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <time.h>

int main()
{
    time_t present_time = time(NULL);  // Get the current time

    struct tm *hr_local_time = localtime(&present_time);  // Convert the current time to the local time of the user

    printf("Welcome to the Happy Time Travel Simulator!\n");

    int travel_year;

    printf("Enter a year to travel to (must be after 1900): ");
    scanf("%d", &travel_year);

    if (travel_year <= 1900) {
        printf("Invalid year entered. Please enter a year after 1900.\n");
        return 0;
    }

    time_t travel_time = present_time;

    travel_time -= (hr_local_time->tm_year - (travel_year - 1900)) * 31536000;
    travel_time -= (hr_local_time->tm_yday * 86400);
    travel_time -= (hr_local_time->tm_hour * 3600);
    travel_time -= (hr_local_time->tm_min * 60);
    travel_time -= hr_local_time->tm_sec;

    struct tm *travel_tm = localtime(&travel_time);

    printf("You have successfully time traveled to the year %d!\n", travel_tm->tm_year + 1900);

    // Let's celebrate your time travel!
    printf("\n\n*******\nYAY! HAPPY TIME TRAVEL!\n*******\n\n\n");

    // Let's print some important events that took place in the year you traveled to.
    printf("Important events that took place in the year %d:\n\n", travel_tm->tm_year + 1900);

    if (travel_tm->tm_year + 1900 == 1969) {
        printf("1. Neil Armstrong and Buzz Aldrin land on the moon!\n");
    } else if (travel_tm->tm_year + 1900 == 1990) {
        printf("1. Nelson Mandela is released after 27 years in prison.\n");
    } else if (travel_tm->tm_year + 1900 == 2000) {
        printf("1. The Y2K bug fails to cause global chaos!\n");
    } else {
        printf("1. Sorry, no important events took place in the year %d.\n", travel_tm->tm_year + 1900);
    }

    // Let's print the current time after time travel
    printf("\n\nCurrent time after time travel: %s", asctime(travel_tm));

    return 0;
}