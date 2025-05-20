//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <time.h>

void travel_to_past(int years, int months, int days)
{
    struct tm travel_time = {0};
    time_t current_time;
    time(&current_time);
    travel_time = *localtime(&current_time);
    travel_time.tm_year -= years;
    travel_time.tm_mon -= months;
    travel_time.tm_mday -= days;
    mktime(&travel_time);
    
    char travel_str[50];
    strftime(travel_str, sizeof(travel_str), "%A, %B %d %Y", &travel_time);
    printf("You have successfully traveled to %s!\n", travel_str);
}

void travel_to_future(int years, int months, int days)
{
    struct tm travel_time = {0};
    time_t current_time;
    time(&current_time);
    travel_time = *localtime(&current_time);
    travel_time.tm_year += years;
    travel_time.tm_mon += months;
    travel_time.tm_mday += days;
    mktime(&travel_time);
    
    char travel_str[50];
    strftime(travel_str, sizeof(travel_str), "%A, %B %d %Y", &travel_time);
    printf("You have successfully traveled to %s!\n", travel_str);
}

int main()
{
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Would you like to travel to the past or the future?\n");
    printf("Enter P for past or F for future: ");
    char choice;
    scanf("%c", &choice);
    
    if(choice == 'P' || choice == 'p')
    {
        int years, months, days;
        printf("Enter the number of years to travel back: ");
        scanf("%d", &years);
        printf("Enter the number of months to travel back: ");
        scanf("%d", &months);
        printf("Enter the number of days to travel back: ");
        scanf("%d", &days);
        travel_to_past(years, months, days);
    }
    else if(choice == 'F' || choice == 'f')
    {
        int years, months, days;
        printf("Enter the number of years to travel forward: ");
        scanf("%d", &years);
        printf("Enter the number of months to travel forward: ");
        scanf("%d", &months);
        printf("Enter the number of days to travel forward: ");
        scanf("%d", &days);
        travel_to_future(years, months, days);
    }
    else
    {
        printf("Invalid choice! Please try again.\n");
    }
    
    printf("Thank you for using the Time Travel Simulator!\n");
    
    return 0;
}