//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int year, month, day, hour, minute, second;
    time_t t;
    struct tm *tm;

    // Ask user for input
    printf("Enter the date and time in the format YYYY-MM-DD HH:MM:SS: ");
    scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    // Set the time
    tm = malloc(sizeof(struct tm));
    tm->tm_year = year - 1900;
    tm->tm_mon = month - 1;
    tm->tm_mday = day;
    tm->tm_hour = hour;
    tm->tm_min = minute;
    tm->tm_sec = second;

    // Convert time to seconds since epoch
    t = mktime(tm);

    // Get the current time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    printf("Current time: %s", asctime(current_time));

    // Get the time difference
    double diff = difftime(t, now);
    
    // Check if time is in the past or future
    if(diff < 0) {
        printf("The time you entered is in the past.\n");
    } else if(diff > 0) {
        printf("The time you entered is in the future.\n");
    } else {
        printf("The time you entered is now.\n");
    }

    // Travel through time
    printf("Traveling through time...\n");
    for(int i = 0; i < abs(diff); i++) {
        if(diff < 0) {
            now--;
        } else {
            now++;
        }
    }

    // Print the new time
    struct tm *new_time = localtime(&now);
    printf("New time: %s", asctime(new_time));

    // Free memory
    free(tm);
    
    return 0;
}