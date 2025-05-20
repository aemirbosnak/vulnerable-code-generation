//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t current_time;
    struct tm * time_info;
    char time_str[100];

    time(&current_time);
    time_info = localtime(&current_time);

    printf("Welcome to the Time Travel Simulator\n");
    printf("You are currently in the year %d\n", time_info->tm_year + 1900);

    int year_choice;

    while (1)
    {
        printf("\nWhat year do you want to travel to? (Enter a year between 1900 and 2099): ");
        scanf("%d", &year_choice);

        if (year_choice < 1900 || year_choice > 2099)
        {
            printf("Invalid year entered. Please enter a year between 1900 and 2099.\n");
        }
        else
        {
            break;
        }
    }

    int current_year = time_info->tm_year + 1900;
    int diff = year_choice - current_year;
    int abs_diff = abs(diff);

    if (diff > 0)
    {
        printf("\nYou have traveled %d years into the future!\n", abs_diff);
    }
    else
    {
        printf("\nYou have traveled %d years into the past!\n", abs_diff);
    }

    printf("Press any key to continue...");
    getchar();

    time_info->tm_year += diff;
    current_time = mktime(time_info);

    strftime(time_str, sizeof(time_str), "%Y", time_info);
    printf("\nYou have arrived in the year %s\n", time_str);

    return 0;
}