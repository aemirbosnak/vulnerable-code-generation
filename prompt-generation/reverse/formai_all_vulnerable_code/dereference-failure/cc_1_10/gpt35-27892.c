//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
/* Time Travel Simulator */
/* Written in Donald Knuth style */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_YEAR 2021     /* Start year for simulation */
#define END_YEAR 2300       /* End year for simulation */
#define NUM_TRIPS 5         /* Number of trips to simulate */

int main()
{
    int year, trip, i;
    struct tm *time_info;
    time_t current_time;

    srand(time(NULL));  /* Seed the random number generator */

    /* Main simulation loop */
    for (trip = 1; trip <= NUM_TRIPS; trip++)
    {
        /* Choose a random year between START_YEAR and END_YEAR */
        year = rand() % (END_YEAR - START_YEAR + 1) + START_YEAR;

        /* Convert year to a struct tm so we can print it nicely */
        time_info = localtime(&current_time);
        time_info->tm_year = year - 1900;
        time_info->tm_mon = 0;
        time_info->tm_mday = 1;
        current_time = mktime(time_info);

        /* Print the results */
        printf("Trip %d: You are in the year %d.\n", trip, year);
        printf("        Date: %s\n", asctime(time_info));
        printf("        Location: ");

        /* Choose a random location */
        i = rand() % 4;
        switch (i)
        {
            case 0:
                printf("New York City\n");
                break;
            case 1:
                printf("Los Angeles\n");
                break;
            case 2:
                printf("London\n");
                break;
            case 3:
                printf("Tokyo\n");
                break;
        }

        printf("\n");
    }

    return 0;
}