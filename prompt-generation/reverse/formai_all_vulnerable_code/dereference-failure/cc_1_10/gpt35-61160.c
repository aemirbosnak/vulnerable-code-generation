//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_SIZE 11 // mm-dd-yyyy + '\0'
#define MAX_TIME_SIZE 9 // hh:mm:ss + '\0'

// Structure for holding date and time info
struct DateTime {
    char date[MAX_DATE_SIZE];
    char time[MAX_TIME_SIZE];
};

// Get current date and time
void getCurrentDateTime(struct DateTime *dateTime) {
    time_t current_time;
    struct tm *current_tm;

    // Get current time
    current_time = time(NULL);
    current_tm = localtime(&current_time);

    // Format date and time strings
    sprintf(dateTime->date, "%.2d-%.2d-%d", current_tm->tm_mon + 1, current_tm->tm_mday, current_tm->tm_year + 1900);
    sprintf(dateTime->time, "%.2d:%.2d:%.2d", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
}

// Travel to past or future date and time
void travel(struct DateTime *currentDateTime, struct DateTime *targetDateTime) {
    time_t current_time, target_time;
    struct tm *current_tm, *target_tm;

    // Convert current and target times to time_t format
    current_tm = (struct tm*) malloc(sizeof(struct tm));
    sscanf(currentDateTime->date, "%.2d-%.2d-%d", &current_tm->tm_mon, &current_tm->tm_mday, &current_tm->tm_year);
    sscanf(currentDateTime->time, "%.2d:%.2d:%.2d", &current_tm->tm_hour, &current_tm->tm_min, &current_tm->tm_sec);
    current_tm->tm_year -= 1900; // Count years from 1900
    current_tm->tm_mon -= 1; // Count months from 0

    target_tm = (struct tm*) malloc(sizeof(struct tm));
    sscanf(targetDateTime->date, "%.2d-%.2d-%d", &target_tm->tm_mon, &target_tm->tm_mday, &target_tm->tm_year);
    sscanf(targetDateTime->time, "%.2d:%.2d:%.2d", &target_tm->tm_hour, &target_tm->tm_min, &target_tm->tm_sec);
    target_tm->tm_year -= 1900; // Count years from 1900
    target_tm->tm_mon -= 1; // Count months from 0

    current_time = mktime(current_tm);
    target_time = mktime(target_tm);

    // Calculate time difference
    int time_diff = (int) difftime(target_time, current_time);
    if (time_diff < 0) {
        printf("You traveled back in time!\n");
    } else if (time_diff > 0) {
        printf("You traveled to the future!\n");
    } else {
        printf("You are already in the target date and time!\n");
        return;
    }

    // Wait for dramatic effect
    printf("..........\n");
    sleep(1);
    printf("..........\n");
    sleep(1);
    printf("..........\n");
    sleep(1);

    // Output target date and time
    printf("You have arrived at the target date and time: %s %s\n", targetDateTime->date, targetDateTime->time);
}

int main() {
    struct DateTime currentDateTime, targetDateTime;

    // Get current date and time
    getCurrentDateTime(&currentDateTime);

    // Print current date and time
    printf("Current date and time: %s %s\n", currentDateTime.date, currentDateTime.time);

    // Prompt user to input target date and time
    printf("Enter target date and time (mm-dd-yyyy hh:mm:ss): ");
    scanf("%s %s", targetDateTime.date, targetDateTime.time);

    // Travel to target date and time
    travel(&currentDateTime, &targetDateTime);

    return 0;
}