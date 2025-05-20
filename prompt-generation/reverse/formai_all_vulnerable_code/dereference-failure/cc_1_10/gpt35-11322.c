//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time = time(NULL);
    struct tm * time_info;
    char time_string[9], date_string[11];

    time_info = localtime(&current_time);

    if (time_info == NULL) {
        printf("Error getting local time\n");
        return 1;
    }

    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    strftime(date_string, sizeof(date_string), "%d/%m/%Y", time_info);

    printf("Current time is: %s\n", time_string);
    printf("Current date is: %s\n", date_string);

    int year, month, day;
    char choice;

    printf("Enter a year to time travel to: ");
    scanf("%d", &year);

    printf("Enter a month (1-12) to time travel to: ");
    scanf("%d", &month);

    printf("Enter a day (1-31) to time travel to: ");
    scanf("%d", &day);

    printf("You have chosen to time travel to %02d/%02d/%04d\n", day, month, year);
    printf("Are you sure? (y/n)\n");
    scanf("%s", &choice);

    if (choice == 'y') {
        time_info->tm_year = year - 1900;
        time_info->tm_mon = month - 1;
        time_info->tm_mday = day;

        current_time = mktime(time_info);

        printf("Time travel successful!\n");

        time_info = localtime(&current_time);

        if (time_info == NULL) {
            printf("Error getting local time\n");
            return 1;
        }

        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
        strftime(date_string, sizeof(date_string), "%d/%m/%Y", time_info);

        printf("Current time is now: %s\n", time_string);
        printf("Current date is now: %s\n", date_string);
    } else {
        printf("Time travel aborted.\n");
    }

    return 0;
}