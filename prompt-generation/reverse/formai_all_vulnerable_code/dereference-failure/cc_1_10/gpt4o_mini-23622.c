//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRAVEL_YEARS 10000
#define MAX_TRAVEL_TIMES 10

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date travel_dates[MAX_TRAVEL_TIMES];
    int current_time_index;
} TimeMachine;

void display_current_date(Date date) {
    printf("Current date: %04d-%02d-%02d\n", date.year, date.month, date.day);
}

void print_menu() {
    printf("\n=== Time Travel Simulator ===\n");
    printf("1. Travel to a specific date\n");
    printf("2. Jump back to the last location\n");
    printf("3. Show current date\n");
    printf("4. Exit\n");
    printf("=============================\n");
}

Date get_current_date() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    Date current_date;
    current_date.year = tm_info->tm_year + 1900; // Year since 1900
    current_date.month = tm_info->tm_mon + 1; // Month is zero-based
    current_date.day = tm_info->tm_mday;
    
    return current_date;
}

void travel_to_date(TimeMachine *tm, Date destination) {
    if (tm->current_time_index >= MAX_TRAVEL_TIMES) {
        printf("Time machine's travel history is full!\n");
        return;
    }

    tm->travel_dates[tm->current_time_index] = destination;
    tm->current_time_index++;
    display_current_date(destination);
    printf("You have time traveled to the year %04d, month %02d, day %02d!\n", 
           destination.year, destination.month, destination.day);
}

void jump_back(TimeMachine *tm) {
    if (tm->current_time_index <= 1) {
        printf("No previous locations to jump back to!\n");
        return;
    }

    tm->current_time_index -= 1; // Move back to previous location
    Date last_travel_date = tm->travel_dates[tm->current_time_index - 1];
    display_current_date(last_travel_date);
    printf("You have jumped back to the year %04d, month %02d, day %02d!\n", 
           last_travel_date.year, last_travel_date.month, last_travel_date.day);
}

void input_date(Date *date) {
    printf("Enter year (YYYY): ");
    scanf("%d", &date->year);
    printf("Enter month (1-12): ");
    scanf("%d", &date->month);
    printf("Enter day (1-31): ");
    scanf("%d", &date->day);
}

int is_valid_date(Date date) {
    if (date.month < 1 || date.month > 12) return 0;
    if (date.day < 1 || date.day > 31) return 0;

    // Check for month specific days
    if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30) return 0;
    if (date.month == 2) {
        if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)) { // Leap year
            if (date.day > 29) return 0;
        } else {
            if (date.day > 28) return 0;
        }
    }
    return 1;
}

int main() {
    TimeMachine tm = { .current_time_index = 0 }; 
    Date current_date = get_current_date();
    display_current_date(current_date);
    
    int option;
    while (1) {
        print_menu();
        printf("Select an option: ");
        scanf("%d", &option);

        if (option == 1) {
            Date destination;
            input_date(&destination);
            if (is_valid_date(destination)) {
                travel_to_date(&tm, destination);
            } else {
                printf("Invalid date! Please try again.\n");
            }
        } else if (option == 2) {
            jump_back(&tm);
        } else if (option == 3) {
            display_current_date(current_date);
        } else if (option == 4) {
            printf("Exiting Time Travel Simulator. Safe travels!\n");
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}