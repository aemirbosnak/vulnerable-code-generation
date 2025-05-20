//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int year = tm.tm_year + 1900;
    int month = tm.tm_mon + 1;
    int day = tm.tm_mday;
    int hour = tm.tm_hour;
    int minute = tm.tm_min;
    int second = tm.tm_sec;

    printf("You are currently in the year %d, month %d, day %d, at %02d:%02d:%02d.\n", year, month, day, hour, minute, second);

    int travelYear, travelMonth, travelDay, travelHour, travelMinute, travelSecond;
    
    printf("\nEnter year to travel to: ");
    scanf("%d", &travelYear);
    printf("Enter month to travel to: ");
    scanf("%d", &travelMonth);
    printf("Enter day to travel to: ");
    scanf("%d", &travelDay);
    printf("Enter hour to travel to: ");
    scanf("%d", &travelHour);
    printf("Enter minute to travel to: ");
    scanf("%d", &travelMinute);
    printf("Enter second to travel to: ");
    scanf("%d", &travelSecond);

    struct tm travelTime = { 0 };
    travelTime.tm_year = travelYear - 1900;
    travelTime.tm_mon = travelMonth - 1;
    travelTime.tm_mday = travelDay;
    travelTime.tm_hour = travelHour;
    travelTime.tm_min = travelMinute;
    travelTime.tm_sec = travelSecond;

    time_t travelT = mktime(&travelTime);
    struct tm travelTM = *localtime(&travelT);

    int travelYearOut = travelTM.tm_year + 1900;
    int travelMonthOut = travelTM.tm_mon + 1;
    int travelDayOut = travelTM.tm_mday;
    int travelHourOut = travelTM.tm_hour;
    int travelMinuteOut = travelTM.tm_min;
    int travelSecondOut = travelTM.tm_sec;

    printf("\nYou have traveled through time!\n");
    printf("You are now in the year %d, month %d, day %d, at %02d:%02d:%02d.\n", travelYearOut, travelMonthOut, travelDayOut, travelHourOut, travelMinuteOut, travelSecondOut);

    return 0;
}