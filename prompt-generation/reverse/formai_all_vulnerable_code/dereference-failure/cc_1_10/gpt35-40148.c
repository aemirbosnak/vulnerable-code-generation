//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t currentTime;
    struct tm *currentDate;
    
    time(&currentTime);
    currentDate = localtime(&currentTime);
    
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Today's date: %d-%d-%d %d:%d:%d\n\n", 
           currentDate->tm_year + 1900, currentDate->tm_mon + 1, currentDate->tm_mday, 
           currentDate->tm_hour, currentDate->tm_min, currentDate->tm_sec);
    
    int travelYear, travelMonth, travelDay, travelHour, travelMin, travelSec;
    
    printf("Enter the year you want to travel to (> 1900): ");
    scanf("%d", &travelYear);
    
    printf("Enter the month you want to travel to (1 - 12): ");
    scanf("%d", &travelMonth);
    
    printf("Enter the day you want to travel to (1 - 31): ");
    scanf("%d", &travelDay);
    
    printf("Enter the hour you want to travel to (0 - 23): ");
    scanf("%d", &travelHour);
    
    printf("Enter the minute you want to travel to (0 - 59): ");
    scanf("%d", &travelMin);
    
    printf("Enter the second you want to travel to (0 - 59): ");
    scanf("%d", &travelSec);
    
    printf("\nTravelling to %d-%d-%d %d:%d:%d ...\n\n", travelYear, travelMonth, travelDay, travelHour, travelMin, travelSec);
    
    struct tm travelDate = { 0 };
    travelDate.tm_year = travelYear - 1900;
    travelDate.tm_mon = travelMonth - 1;
    travelDate.tm_mday = travelDay;
    travelDate.tm_hour = travelHour;
    travelDate.tm_min = travelMin;
    travelDate.tm_sec = travelSec;
    
    time_t travelTime = mktime(&travelDate);
    struct tm *travelDateResult = localtime(&travelTime);
    
    printf("Arrived at %d-%d-%d %d:%d:%d\n\n", 
           travelDateResult->tm_year + 1900, travelDateResult->tm_mon + 1, travelDateResult->tm_mday, 
           travelDateResult->tm_hour, travelDateResult->tm_min, travelDateResult->tm_sec);
    
    return 0;
}