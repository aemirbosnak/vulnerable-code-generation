//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include <stdio.h>
#include <time.h>

int main() {
    // get current time
    time_t now;
    time(&now);

    // convert to struct tm format
    struct tm *current_time = localtime(&now);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("The current date and time is %d/%d/%d %d:%02d:%02d\n\n", 
            current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900, 
            current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

    // ask user where they want to go
    int year, month, day;
    printf("Enter a date to travel to (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &year, &month, &day);

    // convert user input to time_t format
    struct tm travel_time = {0};
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;
    time_t travel_time_t = mktime(&travel_time);

    // check if input is valid and not in the past
    if ((travel_time_t == -1) || (difftime(now, travel_time_t) > 0)) {
        printf("Invalid date. Please enter a future date.\n");
        return 0;
    }

    // calculate difference between current time and travel time
    double difference = difftime(travel_time_t, now);

    // simulate time travel
    printf("\nYou are now time traveling to %d-%02d-%02d...\n", year, month, day);
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("\nWelcome to %d-%02d-%02d!", year, month, day);

    // wait for a while before returning to current time
    printf("\n\nYou can stay here for %.0f seconds before returning to the present.\n", difference);
    printf("Press any key to return to %d/%d/%d %d:%02d:%02d...", 
            current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900, 
            current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
    getchar(); // wait for user input

    // simulate time travel back to present
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("\nWelcome back to %d/%d/%d %d:%02d:%02d!\n", 
            current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900, 
            current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

    return 0;
}