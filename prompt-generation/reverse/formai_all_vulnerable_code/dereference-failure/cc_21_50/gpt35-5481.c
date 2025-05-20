//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    struct tm* timeinfo;
    time_t now;

    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Enter the year you want to travel to (from 1 to 9999):\n");

    int year_choice;
    scanf("%d", &year_choice);

    while(year_choice < 1 || year_choice > 9999) {
        printf("Please enter a valid year (from 1 to 9999):\n");
        scanf("%d", &year_choice);
    }

    printf("\nGreat! Now enter the month (from 1 to 12) and the day (from 1 to 31) you want to travel to, in the format MM/DD:\n");

    int month_choice, day_choice;
    scanf("%d/%d", &month_choice, &day_choice);

    while(month_choice < 1 || month_choice > 12 || day_choice < 1 || day_choice > 31) {
        printf("Please enter a valid date (from 01/01 to 12/31):\n");
        scanf("%d/%d", &month_choice, &day_choice);
    }

    time(&now);
    timeinfo = localtime(&now);

    int current_year = timeinfo->tm_year + 1900;
    int current_month = timeinfo->tm_mon + 1;

    printf("\nOne moment please...\n\n");

    int travelled_years = year_choice - current_year;
    int travelled_months = month_choice - current_month;
    int travelled_days = day_choice - timeinfo->tm_mday;

    // Calculate total seconds between the two dates
    time_t current_time_sec = time(&now);
    timeinfo = gmtime(&current_time_sec);
    timeinfo->tm_mday = day_choice;
    timeinfo->tm_mon = month_choice - 1;
    timeinfo->tm_year = year_choice - 1900;
    time_t chosen_time_sec = mktime(timeinfo);

    double seconds_diff = difftime(chosen_time_sec, current_time_sec);

    // Define time machine interface
    printf("Travelling to %s %d, %d...\n\n", months[month_choice - 1], day_choice, year_choice);
    printf("Initiating Time Warp in...\n\n");

    int delay_counter = 3;
    while (delay_counter >= 1) {
        printf("%d...\n", delay_counter);
        sleep(1);
        delay_counter--;
    }

    printf("\n\n");

    // Time machine activated
    printf("Welcome to %s %d, %d!\n\n", months[month_choice - 1], day_choice, year_choice);
    printf("It is currently ");
    if(timeinfo->tm_hour < 10) {
        printf("0");
    }
    printf("%d:", timeinfo->tm_hour);
    if(timeinfo->tm_min < 10) {
        printf("0");
    }
    printf("%d:", timeinfo->tm_min);
    if(timeinfo->tm_sec < 10) {
        printf("0");
    }
    printf("%d on %s %d, %d.\n\n", timeinfo->tm_sec, months[month_choice - 1], day_choice, year_choice);

    // Check for time travel consequences
    if(travelled_years > 0 || (travelled_years == 0 && (travelled_months > 0 || (travelled_months == 0 && travelled_days > 0)))) {
        printf("You have made a forward jump in time. The consequences of your actions are yet unknown...\n\n");
    } else if(travelled_years < 0 || (travelled_years == 0 && (travelled_months < 0 || (travelled_months == 0 && travelled_days < 0)))) {
        printf("You have travelled back in time. Be careful not to change the course of history...\n\n");
    } else {
        printf("You have travelled to the present time. The world may look the same, but you have changed...\n\n");
    }

    printf("You have travelled %ld seconds in time.\n\n", (long)seconds_diff);

    printf("\n");

    return 0;
}