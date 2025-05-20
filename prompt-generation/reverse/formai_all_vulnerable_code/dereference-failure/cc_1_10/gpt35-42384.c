//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t current_time;                //declare a time variable
    struct tm *time_info;               //create a tm struct pointer
    char time_string[30];               //create a string to hold time info

    //get the current time and print it
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%m/%d/%Y %I:%M:%S %p", time_info);
    printf("Current time: %s\n\n", time_string);

    //ask user for time travel input
    printf("Enter a date and time to travel to (mm/dd/yyyy hh:mm:ss AM/PM): ");
    fgets(time_string, sizeof(time_string), stdin);

    //convert input into a time_t variable
    time_info = calloc(1, sizeof(struct tm));
    strptime(time_string, "%m/%d/%Y %I:%M:%S %p", time_info);
    time_t travel_time = mktime(time_info);

    //check if input is valid
    if (travel_time == -1)
    {
        printf("Invalid input. Exiting program.\n\n");
        return 1;
    }

    //print time travel confirmation message
    printf("\nTraveling to %s...\n\n", time_string);

    //wait for travel time to arrive
    while (difftime(travel_time, time(NULL)) >= 0)
    {
        time(&current_time);
        time_info = localtime(&current_time);
        strftime(time_string, sizeof(time_string), "%m/%d/%Y %I:%M:%S %p", time_info);
        printf("Current time: %s\n", time_string);
        printf("Waiting for travel time to arrive...\n\n");
        sleep(1);
    }

    //time travel complete
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%m/%d/%Y %I:%M:%S %p", time_info);
    printf("\nWelcome to %s!\n\n", time_string);

    return 0;
}