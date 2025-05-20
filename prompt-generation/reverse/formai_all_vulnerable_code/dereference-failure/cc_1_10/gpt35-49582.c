//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *time_now = localtime(&now);

    printf("Welcome to the Time Travel Simulator\n");
    printf("Current date and time: %s\n", asctime(time_now));

    printf("Enter the number of years you would like to travel: ");
    int years;
    scanf("%d", &years);

    // Calculate the future date
    struct tm future_time = *time_now;        
    future_time.tm_year += years;
    mktime(&future_time);

    // Calculate the past date
    struct tm past_time = *time_now;
    past_time.tm_year -= years;
    mktime(&past_time);

    printf("\nTime Travel Destination Options:\n");
    printf("1. Travel %d years into the future\n", years);
    printf("2. Travel %d years into the past\n", years);
    printf("3. Exit the Time Travel Simulator\n");

    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: 
            printf("\nTraveling %d years into the future...\n", years);
            printf("The year is now %4d\n", future_time.tm_year + 1900);
            break;

        case 2: 
            printf("\nTraveling %d years into the past...\n", years);
            printf("The year is now %4d\n", past_time.tm_year + 1900);
            break;

        case 3: 
            printf("\nThank you for using the Time Travel Simulator\n");
            break;

        default: 
            printf("\nInvalid choice. Please enter a valid option.\n");
            break;
    }

    return 0;
}