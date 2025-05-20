//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    //Initializing variables with current date-time
    time_t current_time = time(NULL);
    struct tm current_tm = *localtime(&current_time);
    int current_year = current_tm.tm_year + 1900;

    //Prompting user for year they want to travel to
    printf("Enter the year you want to travel to: ");
    int travel_year;
    scanf("%d", &travel_year);

    //Calculating time difference
    int time_diff = travel_year - current_year;

    //Printing travel year and time difference
    printf("Travel Year: %d\n", travel_year);
    printf("Time Difference from Current Year: %d\n", time_diff);

    if(time_diff == 0)
    {
        printf("You are already in the year %d!", travel_year);
    }
    else if(time_diff < 0)
    {
        printf("Time travel to past is not possible yet!");
    }
    else
    {
        //Initializing variables for date-time of travel year
        struct tm travel_tm = current_tm;
        travel_tm.tm_year = travel_year - 1900;

        //Creating time travel simulation by manipulating travel_tm 
        //and printing date-time at every step of the simulation
        printf("\nTime Travel Simulation:\n");
        printf("Current Date-Time: %d-%02d-%02d %02d:%02d:%02d\n", 
                current_year, current_tm.tm_mon+1, current_tm.tm_mday, 
                current_tm.tm_hour, current_tm.tm_min, current_tm.tm_sec);

        for(int i=0; i<time_diff; i++)
        {
            travel_tm.tm_year = current_year + i;
            mktime(&travel_tm);
            printf("In %d: %d-%02d-%02d %02d:%02d:%02d\n", 
                    current_year+i, travel_tm.tm_year+1900, travel_tm.tm_mon+1, 
                    travel_tm.tm_mday, travel_tm.tm_hour, travel_tm.tm_min, travel_tm.tm_sec);
        }
    }

    return 0;
}