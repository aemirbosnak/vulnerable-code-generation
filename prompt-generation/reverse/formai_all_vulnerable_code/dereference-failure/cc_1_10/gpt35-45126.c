//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //declare time variables
    struct tm current_time = {0};
    struct tm future_time = {0};

    //set current time
    time_t t = time(NULL);
    current_time = *localtime(&t);

    //set future time to 100 years later
    future_time.tm_year = current_time.tm_year + 100;
    future_time.tm_mon = current_time.tm_mon;
    future_time.tm_mday = current_time.tm_mday;

    //print current and future time
    printf("Current time is: %02d/%02d/%04d %02d:%02d:%02d\n", current_time.tm_mday, current_time.tm_mon + 1, current_time.tm_year + 1900, current_time.tm_hour, current_time.tm_min, current_time.tm_sec);
    printf("100 years from now it will be: %02d/%02d/%04d %02d:%02d:%02d\n", future_time.tm_mday, future_time.tm_mon + 1, future_time.tm_year + 1900, future_time.tm_hour, future_time.tm_min, future_time.tm_sec);

    //ask user if they want to travel to the future
    printf("\nDo you want to travel to the future? (y/n): ");
    char response = getchar();

    //clear input buffer
    while ((getchar()) != '\n');

    //continue only if user responds with 'y'
    if (response == 'y') {

        //simulate time travel by incrementally increasing year until it reaches future year
        while (current_time.tm_year < future_time.tm_year) {

            //update current time
            current_time.tm_year++;
            t = mktime(&current_time);
            current_time = *localtime(&t);

            //print current time
            printf("\nTime is progressing...\n");
            printf("Current time is: %02d/%02d/%04d %02d:%02d:%02d\n", current_time.tm_mday, current_time.tm_mon + 1, current_time.tm_year + 1900, current_time.tm_hour, current_time.tm_min, current_time.tm_sec);

            //wait for one second to simulate time travel
            sleep(1);
        }

        //print message upon arriving at future year
        printf("\nYou have arrived in the future!\n");
    }

    return 0;
}