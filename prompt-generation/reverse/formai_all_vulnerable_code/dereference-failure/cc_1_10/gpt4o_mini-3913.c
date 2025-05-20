//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 5

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date travel_dates[MAX_TIME_TRAVELS];
    int travel_count;
} TimeTraveler;

void initialize_time_traveler(TimeTraveler *traveler) {
    traveler->travel_count = 0;
}

void print_date(const Date *date) {
    printf("%02d/%02d/%04d\n", date->day, date->month, date->year);
}

void add_time_travel_entry(TimeTraveler *traveler, int year, int month, int day) {
    if (traveler->travel_count < MAX_TIME_TRAVELS) {
        traveler->travel_dates[traveler->travel_count].year = year;
        traveler->travel_dates[traveler->travel_count].month = month;
        traveler->travel_dates[traveler->travel_count].day = day;
        traveler->travel_count++;
    } else {
        printf("Maximum time travels reached!\n");
    }
}

void show_time_travel_history(const TimeTraveler *traveler) {
    printf("Time Travel History:\n");
    for (int i = 0; i < traveler->travel_count; i++) {
        print_date(&traveler->travel_dates[i]);
    }
}

void travel_to_future(TimeTraveler *traveler, int years) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    int future_year = local->tm_year + 1900 + years;
    int future_month = local->tm_mon + 1;
    int future_day = local->tm_mday;

    add_time_travel_entry(traveler, future_year, future_month, future_day);
    printf("You have traveled to the year %d!\n", future_year);
}

void travel_to_past(TimeTraveler *traveler, int years) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    int past_year = local->tm_year + 1900 - years;
    int past_month = local->tm_mon + 1;
    int past_day = local->tm_mday;

    add_time_travel_entry(traveler, past_year, past_month, past_day);
    printf("You have traveled to the year %d!\n", past_year);
}

int main() {
    TimeTraveler traveler;
    initialize_time_traveler(&traveler);
    
    int choice, years;

    while (1) {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("1. Travel to Future\n");
        printf("2. Travel to Past\n");
        printf("3. Show Travel History\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of years to travel to the future: ");
                scanf("%d", &years);
                travel_to_future(&traveler, years);
                break;
            case 2:
                printf("Enter number of years to travel to the past: ");
                scanf("%d", &years);
                travel_to_past(&traveler, years);
                break;
            case 3:
                show_time_travel_history(&traveler);
                break;
            case 4:
                printf("Thank you for using the Time Travel Simulator!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    }

    return 0;
}