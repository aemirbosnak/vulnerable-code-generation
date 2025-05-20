//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void travel_menu();
void time_travel();
void print_current_time(struct tm* ti);
void print_future_time(struct tm* ti);

// Global variables
time_t current_time;
struct tm* current_time_info;

int main()
{
    // Get the current time
    current_time = time(NULL);
    current_time_info = localtime(&current_time);

    printf("Welcome to the Time Travel Simulator!\n");

    // Show the travel menu
    travel_menu();

    return 0;
}

void travel_menu()
{
    int travel_choice;
    int travel_years;
    int travel_months;
    int travel_days;

    printf("\nWhat type of travel do you want?\n");
    printf("---------------------\n");
    printf("1. Travel to the future\n");
    printf("2. Travel to the past\n");
    printf("3. Quit\n");
    printf("---------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &travel_choice);

    switch (travel_choice) {
        case 1:
            printf("\nHow many years forward do you want to travel? ");
            scanf("%d", &travel_years);
            printf("How many months forward do you want to travel? ");
            scanf("%d", &travel_months);
            printf("How many days forward do you want to travel? ");
            scanf("%d", &travel_days);
            time_travel(travel_years, travel_months, travel_days);
            break;
        case 2:
            printf("\nHow many years back do you want to travel? ");
            scanf("%d", &travel_years);
            printf("How many months back do you want to travel? ");
            scanf("%d", &travel_months);
            printf("How many days back do you want to travel? ");
            scanf("%d", &travel_days);
            time_travel(-travel_years, -travel_months, -travel_days);
            break;
        case 3:
            printf("\nThank you for using the Time Travel Simulator!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
            travel_menu();
    }
}

void time_travel(int travel_years, int travel_months, int travel_days)
{
    // Calculate the target time
    time_t target_time = current_time + (travel_years * 31536000) + (travel_months * 2592000) + (travel_days * 86400);

    // Get the target time information
    struct tm* target_time_info = localtime(&target_time);

    // Print the current time and target time
    printf("\nCurrent time: ");
    print_current_time(current_time_info);
    printf("Target time: ");
    print_future_time(target_time_info);

    // Wait for 2 seconds before going back to the menu
    printf("Returning to the menu...");
    sleep(2);
    travel_menu();
}

void print_current_time(struct tm* ti)
{
    printf("%02d-%02d-%04d %02d:%02d:%02d\n", 
        ti->tm_mday, ti->tm_mon+1, ti->tm_year+1900, 
        ti->tm_hour, ti->tm_min, ti->tm_sec);
}

void print_future_time(struct tm* ti)
{
    printf("%02d-%02d-%04d %02d:%02d:%02d\n", 
        ti->tm_mday, ti->tm_mon+1, ti->tm_year+1900, 
        ti->tm_hour, ti->tm_min, ti->tm_sec);
}