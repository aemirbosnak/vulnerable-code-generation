//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 10
#define TIME_TRAVEL_LIMIT 1000

typedef struct {
    char event_description[256];
    time_t event_time;
} Event;

Event timeline[MAX_EVENTS];
int event_count = 0;

void add_event(const char *description) {
    if (event_count >= MAX_EVENTS) {
        printf("Timeline is full! Cannot add more events.\n");
        return;
    }

    time(&timeline[event_count].event_time);
    strcpy(timeline[event_count].event_description, description);
    event_count++;
    printf("Event added: %s\n", description);
}

void list_events() {
    printf("\n--- Timeline Events ---\n");
    for (int i = 0; i < event_count; i++) {
        printf("Time: %sEvent: %s\n", ctime(&timeline[i].event_time), timeline[i].event_description);
    }
    printf("------------------------\n");
}

void time_travel(int travel_years) {
    if (travel_years < -TIME_TRAVEL_LIMIT || travel_years > TIME_TRAVEL_LIMIT) {
        printf("Time travel limit exceeded! Please select a range within -%d and %d years.\n", TIME_TRAVEL_LIMIT, TIME_TRAVEL_LIMIT);
        return;
    }
    
    time_t current_time;
    time(&current_time);
    struct tm *new_time = localtime(&current_time);
    new_time->tm_year += travel_years;

    if (new_time->tm_year < 0) {
        printf("Cannot travel to before the year 0.\n");
        return;
    }

    time_t travel_time = mktime(new_time);
    printf("Time traveling to: %s", ctime(&travel_time));
}

void detective_query(int year) {
    printf("Detective Watson is accessing the information from the year %d...\n", year);
    
    for (int i = 0; i < event_count; i++) {
        struct tm *event_tm = localtime(&timeline[i].event_time);
        if (event_tm->tm_year + 1900 == year) {
            printf("In %d: %s\n", year, timeline[i].event_description);
        }
    }
}

void show_menu() {
    printf("\n--- Sherlock Holmes Time Travel Simulator ---\n");
    printf("1. Add Event\n");
    printf("2. List Events\n");
    printf("3. Time Travel\n");
    printf("4. Query Events by Year\n");
    printf("5. Exit\n");
    printf("---------------------------------------------\n");
}

int main() {
    int choice;
    char description[256];
    int years;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the event description: ");
                getchar(); // Consume the newline
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove trailing newline
                add_event(description);
                break;

            case 2:
                list_events();
                break;

            case 3:
                printf("Enter the number of years to travel (positive or negative): ");
                scanf("%d", &years);
                time_travel(years);
                break;

            case 4:
                printf("Enter the year to query: ");
                scanf("%d", &years);
                detective_query(years);
                break;

            case 5:
                printf("Exiting the Time Travel Simulator. Until we meet again, Watson!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}