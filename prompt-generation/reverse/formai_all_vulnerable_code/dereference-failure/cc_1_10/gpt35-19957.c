//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <time.h>

int main() {
    // Get the current date and time
    time_t now = time(NULL);

    // Set the destination time
    struct tm dest_time;
    dest_time.tm_year = 2050 - 1900; // Year 2050
    dest_time.tm_mon = 0; // January
    dest_time.tm_mday = 1; // 1st day
    dest_time.tm_hour = 0; // 12:00 AM
    dest_time.tm_min = 0;
    dest_time.tm_sec = 0;
    dest_time.tm_isdst = -1;

    // Calculate the time difference between now and destination time
    double diff = difftime(mktime(&dest_time), now);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("-------------------------------------\n\n");
    printf("You are currently in the year %d.\n", localtime(&now)->tm_year + 1900);
    printf("You have %ld seconds before you reach your destination time.\n\n", (long)diff);

    // Start the time travel countdown
    for (int i = diff; i >= 0; i--) {
        if (i % 10 == 0) { // Every 10 seconds, print a message
            printf("Time remaining: %d seconds...\n", i);
        }
        if (i == 5) { // At 5 seconds, warn the user
            printf("WARNING: Time disturbance detected!\n");
        }
        if (i == 3) { // At 3 seconds, give the user a choice
            printf("\nYou have a choice:\n");
            printf("1. Continue with time travel.\n");
            printf("2. Abort mission.\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Continuing with time travel...\n");
            } else {
                printf("Mission aborted. Returning to present time.\n");
                return 0;
            }
        }
        sleep(1); // Wait for 1 second
    }

    // Destination time reached!
    printf("\n\nYou have arrived at your destination time.\n");
    printf("Current year: %d\n", localtime(&now)->tm_year + 1900);
    printf("Destination year: %d\n", dest_time.tm_year + 1900);
    printf("Time travel successful!\n");

    return 0;
}