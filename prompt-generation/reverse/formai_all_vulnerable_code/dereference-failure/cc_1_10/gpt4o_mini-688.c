//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char *event;
} TimeTravelLog;

TimeTravelLog *createLog(int year, int month, int day, const char *event);
void travelInTime(TimeTravelLog *log);
void displayLog(TimeTravelLog *log);
void freeLog(TimeTravelLog *log);

int main() {
    printf("Welcome to the C Time Travel Simulator!\n");
    int choice;
    TimeTravelLog *log;

    while (1) {
        printf("Choose an action:\n");
        printf("1. Travel to the past\n");
        printf("2. Travel to the future\n");
        printf("3. Display time travel log\n");
        printf("4. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int year, month, day;
                char event[256];
                printf("Enter year to travel to: ");
                scanf("%d", &year);
                printf("Enter month (1-12): ");
                scanf("%d", &month);
                printf("Enter day (1-31): ");
                scanf("%d", &day);
                printf("Enter an event for this time travel: ");
                scanf(" %[^\n]", event);
                log = createLog(year, month, day, event);
                travelInTime(log);
                freeLog(log);
                break;
            }
            case 2: {
                int year, month, day;
                char event[256];
                printf("Enter year to travel to: ");
                scanf("%d", &year);
                printf("Enter month (1-12): ");
                scanf("%d", &month);
                printf("Enter day (1-31): ");
                scanf("%d", &day);
                printf("Enter an event for this time travel: ");
                scanf(" %[^\n]", event);
                log = createLog(year, month, day, event);
                travelInTime(log);
                freeLog(log);
                break;
            }
            case 3:
                if (log != NULL) {
                    displayLog(log);
                } else {
                    printf("No time travel log to display.\n");
                }
                break;
            case 4:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

TimeTravelLog *createLog(int year, int month, int day, const char *event) {
    TimeTravelLog *log = (TimeTravelLog *)malloc(sizeof(TimeTravelLog));
    if (log == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    log->date.year = year;
    log->date.month = month;
    log->date.day = day;
    log->event = (char *)malloc(strlen(event) + 1);
    if (log->event == NULL) {
        printf("Memory allocation failed for event!\n");
        free(log);
        exit(1);
    }
    strcpy(log->event, event);
    return log;
}

void travelInTime(TimeTravelLog *log) {
    printf("Traveling to %04d-%02d-%02d...\n", log->date.year, log->date.month, log->date.day);
    printf("Event: %s\n", log->event);
    printf("Welcome to your journey!\n");
}

void displayLog(TimeTravelLog *log) {
    printf("Time Travel Log:\n");
    printf("Date: %04d-%02d-%02d\n", log->date.year, log->date.month, log->date.day);
    printf("Event: %s\n", log->event);
}

void freeLog(TimeTravelLog *log) {
    free(log->event);
    free(log);
}