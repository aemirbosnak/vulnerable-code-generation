//FormAI DATASET v1.0 Category: Date and time ; Style: complex
#include<stdio.h>
#include<time.h>

int main()
{
    //Declare Variables
    time_t curr_time;
    struct tm *local_time;
    char time_string[100];
    
    //Get Current Time
    curr_time = time(NULL);
    
    //Get Local Time
    local_time = localtime(&curr_time);
    
    //Format Time String
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);
    
    //Print Time Information
    printf("Current Time: %s\n", time_string);
    printf("Year: %d\n", local_time->tm_year + 1900);
    printf("Month: %d\n", local_time->tm_mon + 1);
    printf("Day: %d\n", local_time->tm_mday);
    printf("Hour: %d\n", local_time->tm_hour);
    printf("Minute: %d\n", local_time->tm_min);
    printf("Second: %d\n", local_time->tm_sec);
    
    //Create Another Time Struct Object
    struct tm new_time;
    new_time.tm_year = 2022 - 1900;
    new_time.tm_mon = 11 - 1; //November
    new_time.tm_mday = 25; //Christmas Day
    new_time.tm_hour = 0;
    new_time.tm_min = 0;
    new_time.tm_sec = 0;
    
    //Convert Time Struct to Time T object
    time_t new_t = mktime(&new_time);
    
    //Get Local Time
    struct tm *new_local_time;
    new_local_time = localtime(&new_t);
    
    //Format Time String
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", new_local_time);
    
    //Print Time Information of Christmas Day 2022
    printf("\nChristmas Day 2022 Information: %s\n", time_string);
    printf("Year: %d\n", new_local_time->tm_year + 1900);
    printf("Month: %d\n", new_local_time->tm_mon + 1);
    printf("Day: %d\n", new_local_time->tm_mday);
    printf("Hour: %d\n", new_local_time->tm_hour);
    printf("Minute: %d\n", new_local_time->tm_min);
    printf("Second: %d\n", new_local_time->tm_sec);
    
    return 0;
}