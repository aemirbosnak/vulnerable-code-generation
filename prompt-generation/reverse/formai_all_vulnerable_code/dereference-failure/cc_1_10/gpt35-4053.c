//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime; // time_t is an integral data type used for storing the time
    struct tm* currentTimeStruct; // struct tm is a structure which holds the date and time
    int year, month, day, hour, minute, second; // variables to store the desired time
    struct tm* timeAtDesired; // structure to hold the desired time
    
    time(&currentTime); // get the current time
    currentTimeStruct = localtime(&currentTime); // convert to local time
    
    printf("Current date and time: %s", asctime(currentTimeStruct)); // display the current time
    
    printf("\nEnter the desired year (YYYY): ");
    scanf("%d", &year);
    printf("Enter the desired month (1-12): ");
    scanf("%d", &month);
    printf("Enter the desired day (1-31): ");
    scanf("%d", &day);
    printf("Enter the desired hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter the desired minute (0-59): ");
    scanf("%d", &minute);
    printf("Enter the desired second (0-59): ");
    scanf("%d", &second);
    
    timeAtDesired = localtime(&currentTime); // get the current time again to avoid conflicts
    
    timeAtDesired->tm_year = year - 1900; // set the desired year
    timeAtDesired->tm_mon = month - 1; // set the desired month
    timeAtDesired->tm_mday = day; // set the desired day
    timeAtDesired->tm_hour = hour; // set the desired hour
    timeAtDesired->tm_min = minute; // set the desired minute
    timeAtDesired->tm_sec = second; // set the desired second
    
    time_t timeDifference = difftime(mktime(timeAtDesired), currentTime); // calculate the time difference
    
    if (timeDifference > 0) { // if the desired time is in the future
        printf("\nTime travel successful! Travelling to the desired time...\n");
        for (int i = 0; i < 10; i++) { // wait for 1 second 10 times
            printf(".");
            fflush(stdout); // flush the output buffer to display the dots
            sleep(1); // wait for 1 second
        }
        printf("\nWelcome to the year %d!\n", year);
    } else { // if the desired time is in the past
        printf("\nSorry, time travel to the past is not possible.\n");
    }
    
    return 0;
}