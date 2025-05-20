//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int year, month, day, hour, minute, second;
    time_t now;
    struct tm *timeinfo;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please select a destination time:\n");
    printf("1. The year 1900\n");
    printf("2. The year 2000\n");
    printf("3. The year 2100\n");
    printf("4. A custom time\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            year = 1900;
            month = 1;
            day = 1;
            hour = 0;
            minute = 0;
            second = 0;
            break;
        case 2:
            year = 2000;
            month = 1;
            day = 1;
            hour = 0;
            minute = 0;
            second = 0;
            break;
        case 3:
            year = 2100;
            month = 1;
            day = 1;
            hour = 0;
            minute = 0;
            second = 0;
            break;
        case 4:
            printf("Enter the year (YYYY): ");
            scanf("%d", &year);
            printf("Enter the month (1-12): ");
            scanf("%d", &month);
            printf("Enter the day (1-31): ");
            scanf("%d", &day);
            printf("Enter the hour (0-23): ");
            scanf("%d", &hour);
            printf("Enter the minute (0-59): ");
            scanf("%d", &minute);
            printf("Enter the second (0-59): ");
            scanf("%d", &second);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    time(&now);
    timeinfo = localtime(&now);

    printf("Current time: %s", asctime(timeinfo));

    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = minute;
    timeinfo->tm_sec = second;

    printf("\nDestination time: %s", asctime(timeinfo));

    return 0;
}