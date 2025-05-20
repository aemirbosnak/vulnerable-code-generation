//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include<stdio.h>
#include<time.h>

int main()
{
    time_t present_time = time(NULL); // get current time
    struct tm *current_time = localtime(&present_time); // convert time_t to struct tm format
    
    // Display current time in readable format
    printf("Current time:\n%d-%02d-%02d %02d:%02d:%02d\n", current_time->tm_year+1900, current_time->tm_mon+1, current_time->tm_mday,
     current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
     
    printf("\nWelcome to the Time Travel Simulator!\n\n");
    int choice, year, month, day, hour, minute, second;
    
    printf("Enter your choice:\n");
    printf("1. Travel to the past\n2. Travel to the future\n");
    scanf("%d", &choice);
    
    printf("Enter the year: ");
    scanf("%d", &year);
    
    printf("Enter the month: ");
    scanf("%d", &month);
    
    printf("Enter the day: ");
    scanf("%d", &day);

    printf("Enter the hour: ");
    scanf("%d", &hour);

    printf("Enter the minute: ");
    scanf("%d", &minute);

    printf("Enter the second: ");
    scanf("%d", &second);
    
    // create struct tm format from user input
    struct tm time_input = {0};
    time_input.tm_year = year - 1900;
    time_input.tm_mon = month - 1;
    time_input.tm_mday = day;
    time_input.tm_hour = hour;
    time_input.tm_min = minute;
    time_input.tm_sec = second;

    time_t travel_time = mktime(&time_input); // convert struct tm to time_t format

    if (choice == 1) {
        printf("\nTravelling to the past...\n");
        printf("Time destination: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
        
        if (difftime(present_time, travel_time) < 0) {
            printf("Error: Cannot travel to the future.\n");
        }
        else {
            printf("Time travel successful!\n\n");
            printf("You have arrived at: %d-%02d-%02d %02d:%02d:%02d\n", time_input.tm_year+1900, time_input.tm_mon+1, time_input.tm_mday,
             time_input.tm_hour, time_input.tm_min, time_input.tm_sec);
        }
    }
    else if (choice == 2) {
        printf("\nTravelling to the future...\n");
        printf("Time destination: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
        printf("\nTime travel successful!\n\n");
        printf("You have arrived at: %d-%02d-%02d %02d:%02d:%02d\n", time_input.tm_year+1900, time_input.tm_mon+1, time_input.tm_mday,
         time_input.tm_hour, time_input.tm_min, time_input.tm_sec);
    }
    else {
        printf("\nInvalid choice. Exiting...\n");
    }
    return 0;
}