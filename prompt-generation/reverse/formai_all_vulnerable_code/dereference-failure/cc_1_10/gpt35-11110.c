//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);
    struct tm* tm_now = localtime(&now);
    int choice;
    
    // Display current date and time
    printf("You are currently in the year %d\n\n", tm_now->tm_year + 1900);
    printf("Select an option:\n");
    printf("1. Travel to a specific year\n");
    printf("2. Travel to a specific date\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        int year;
        printf("\nEnter the year you want to travel to: ");
        scanf("%d", &year);

        if(year > (tm_now->tm_year + 1900))
        {
            printf("\nTravelling to %d...\n\n", year);

            while(tm_now->tm_year + 1900 != year)
            {
                now += 31536000; // Add 1 year to time
                tm_now = localtime(&now);
            }

            printf("You have arrived in the year %d\n", tm_now->tm_year + 1900);
        }
        else
        {
            printf("\nTime travel only possible to future years\n");
        }
    }
    else if(choice == 2)
    {
        int day, month, year;
        printf("\nEnter the date you want to travel to in format DD MM YYYY: ");
        scanf("%d %d %d", &day, &month, &year);

        if(mktime(tm_now) > mktime(&((struct tm){0, 0, 0, day, month - 1, year - 1900})))
        {
            printf("\nTravelling to %d/%d/%d...\n\n", day, month, year);
            tm_now->tm_mday = day;
            tm_now->tm_mon = month - 1;
            tm_now->tm_year = year - 1900;
            now = mktime(tm_now);
            printf("You have arrived in %d/%d/%d\n", tm_now->tm_mday, tm_now->tm_mon + 1, tm_now->tm_year + 1900);  
        }
        else
        {
            printf("\nTime travel only possible to future dates\n");
        }
    }
    else
    {
        printf("\nInvalid choice\n");
    }
   
    return 0;
}