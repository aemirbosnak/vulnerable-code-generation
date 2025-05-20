//FormAI DATASET v1.0 Category: Date and time ; Style: enthusiastic
#include<stdio.h>
#include<time.h>

int main() {

    time_t currentTime; //declare variable to hold current time
    struct tm *localTime; //struct to hold local time details

    time( &currentTime ); //get current system time
    localTime = localtime( &currentTime ); //convert system time to local time

    int dayOfWeek = localTime->tm_wday; //get the day of the week from the local time
    int month = localTime->tm_mon + 1; //get the month from the local time (+1 to adjust for 0 indexing)
    int dayOfMonth = localTime->tm_mday; //get the day of the month from the local time
    int year = localTime->tm_year + 1900; //get the year from the local time (+1900 to adjust for years since 1900)
    int hour = localTime->tm_hour; //get the hour from the local time
    int minute = localTime->tm_min; //get the minute from the local time
    int second = localTime->tm_sec; //get the second from the local time

    switch(dayOfWeek) { //switch statement to print out the day of the week
        case 0:
            printf("Today is Sunday\n");
            break;
        case 1:
            printf("Today is Monday\n");
            break;
        case 2:
            printf("Today is Tuesday\n");
            break;
        case 3:
            printf("Today is Wednesday\n");
            break;
        case 4:
            printf("Today is Thursday\n");
            break;
        case 5:
            printf("Today is Friday\n");
            break;
        case 6:
            printf("Today is Saturday\n");
            break;
        default:
            printf("Error: Invalid Day of Week\n");
            break;
    }

    printf("The date is %d/%d/%d\n", dayOfMonth, month, year); //print out the date
    printf("The time is %d:%d:%d\n", hour, minute, second); //print out the time

    return 0; //indicate successful program execution
}