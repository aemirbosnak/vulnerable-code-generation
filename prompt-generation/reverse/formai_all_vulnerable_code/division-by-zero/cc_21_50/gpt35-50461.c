//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t current_time;
    srand(time(NULL));
    time(&current_time);

    struct tm* time_info = localtime(&current_time);

    // Set initial date as current date
    int day = time_info->tm_mday;
    int month = time_info->tm_mon + 1;
    int year = time_info->tm_year + 1900;

    printf("Welcome to the Time Travel Simulator!\n");

    while(1) {
        printf("\nCurrent Date: %d/%d/%d\n", day, month, year);
        printf("Choose an option:\n");
        printf("1. Travel to a Random Date\n");
        printf("2. Travel to a Specific Date\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            // Generate random date between 1000 and current year
            int min_year = 1000;
            int max_year = year;

            int random_year = rand() % (max_year - min_year + 1) + min_year;
            int random_month = rand() % 12 + 1;
            int random_day = rand() % 31 + 1;

            printf("You have arrived at %d/%d/%d!\n", random_day, random_month, random_year);

            day = random_day;
            month = random_month;
            year = random_year;

        } else if(choice == 2) {

            printf("Enter the date you wish to travel to (dd/mm/yyyy):\n");

            int new_day, new_month, new_year;
            scanf("%d/%d/%d", &new_day, &new_month, &new_year);

            if(new_year < 1000 || new_year > year) {
                printf("Sorry, time travel to dates before the year 1000 or after the current year is not possible.\n");
                continue;
            }

            if(new_month < 1 || new_month > 12) {
                printf("Invalid month.\n");
                continue;
            }

            if(new_day < 1 || new_day > 31) {
                printf("Invalid day.\n");
                continue;
            }

            if((new_month == 4 || new_month == 6 || new_month == 9 || new_month == 11) && new_day > 30) {
                printf("Invalid day.\n");
                continue;
            }

            if(new_month == 2 && new_day > 29) {
                printf("Invalid day.\n");
                continue;
            }

            if(new_month == 2 && new_day == 29) {
                // Check if it's a leap year
                if((new_year % 4 == 0 && new_year % 100 != 0) || new_year % 400 == 0) {
                    printf("You have arrived at %d/%d/%d (Leap Day)!\n", new_day, new_month, new_year);
                    day = new_day;
                    month = new_month;
                    year = new_year;
                } else {
                    printf("Sorry, %d is not a leap year.\n", new_year);
                    continue;
                }
            } else {
                printf("You have arrived at %d/%d/%d!\n", new_day, new_month, new_year);
                day = new_day;
                month = new_month;
                year = new_year;
            }

        } else if(choice == 3) {
            printf("Goodbye!");
            break;
        } else {
            printf("Invalid option.");
        }
    }

    return 0;
}