//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DateTime;

void display_date(DateTime dt) {
    printf("Current Date and Time: %04d-%02d-%02d %02d:%02d:%02d\n",
           dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
}

void travel_back_in_time(DateTime* dt, int seconds) {
    time_t rawtime = mktime(&(struct tm){ .tm_year = dt->year - 1900,
                                          .tm_mon = dt->month - 1,
                                          .tm_mday = dt->day,
                                          .tm_hour = dt->hour,
                                          .tm_min = dt->minute,
                                          .tm_sec = dt->second });
    rawtime -= seconds; // Travel back in time
    struct tm *new_time = localtime(&rawtime);

    dt->year = new_time->tm_year + 1900;
    dt->month = new_time->tm_mon + 1;
    dt->day = new_time->tm_mday;
    dt->hour = new_time->tm_hour;
    dt->minute = new_time->tm_min;
    dt->second = new_time->tm_sec;
}

void travel_forward_in_time(DateTime* dt, int seconds) {
    time_t rawtime = mktime(&(struct tm){ .tm_year = dt->year - 1900,
                                          .tm_mon = dt->month - 1,
                                          .tm_mday = dt->day,
                                          .tm_hour = dt->hour,
                                          .tm_min = dt->minute,
                                          .tm_sec = dt->second });
    rawtime += seconds; // Travel forward in time
    struct tm *new_time = localtime(&rawtime);

    dt->year = new_time->tm_year + 1900;
    dt->month = new_time->tm_mon + 1;
    dt->day = new_time->tm_mday;
    dt->hour = new_time->tm_hour;
    dt->minute = new_time->tm_min;
    dt->second = new_time->tm_sec;
}

int main() {
    DateTime current_time;
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    current_time.year = local->tm_year + 1900;
    current_time.month = local->tm_mon + 1;
    current_time.day = local->tm_mday;
    current_time.hour = local->tm_hour;
    current_time.minute = local->tm_min;
    current_time.second = local->tm_sec;

    int choice;
    int seconds;
        
    while (1) {
        printf("\nTime Travel Simulator\n");
        printf("Current Time: ");
        display_date(current_time);
        printf("1. Travel Back in Time\n");
        printf("2. Travel Forward in Time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter seconds to travel back: ");
            scanf("%d", &seconds);
            travel_back_in_time(&current_time, seconds);
            printf("You have traveled back in time.\n");
        } else if (choice == 2) {
            printf("Enter seconds to travel forward: ");
            scanf("%d", &seconds);
            travel_forward_in_time(&current_time, seconds);
            printf("You have traveled forward in time.\n");
        } else if (choice == 3) {
            printf("Thank you for using the Time Travel Simulator.\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}