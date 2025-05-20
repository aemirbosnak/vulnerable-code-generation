//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_TRAVELS 10
#define MAX_MESSAGE_LENGTH 256

typedef enum {
    PAST,
    FUTURE
} TimeDirection;

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    TimeDirection direction;
    char message[MAX_MESSAGE_LENGTH];
} TimeTravelEvent;

typedef struct {
    TimeTravelEvent events[MAX_TIME_TRAVELS];
    int count;
} TimeTravelHistory;

void initializeHistory(TimeTravelHistory *history) {
    history->count = 0;
}

void addTimeTravelEvent(TimeTravelHistory *history, int year, int month, int day, TimeDirection direction, const char *message) {
    if (history->count < MAX_TIME_TRAVELS) {
        history->events[history->count].date.year = year;
        history->events[history->count].date.month = month;
        history->events[history->count].date.day = day;
        history->events[history->count].direction = direction;
        strncpy(history->events[history->count].message, message, MAX_MESSAGE_LENGTH - 1);
        history->events[history->count].message[MAX_MESSAGE_LENGTH - 1] = '\0';
        history->count++;
    } else {
        printf("Maximum time travel events reached.\n");
    }
}

void listTimeTravelEvents(const TimeTravelHistory *history) {
    printf("\nTime Travel Events:\n");
    for (int i = 0; i < history->count; i++) {
        const TimeTravelEvent *event = &history->events[i];
        const char *direction = (event->direction == PAST) ? "To the Past" : "To the Future";
        printf("[%d] %s: %02d/%02d/%04d - %s\n",
               i + 1, direction, event->date.day, event->date.month, event->date.year, event->message);
    }
}

void timeTravel(const char *destination, TimeDirection direction, TimeTravelHistory *history) {
    time_t t;
    struct tm *tm_info;
    
    // Get current date-time
    time(&t);
    tm_info = localtime(&t);
    
    // Just an example of how the travel might affect the current date
    if (direction == PAST) {
        tm_info->tm_year -= (rand() % 50 + 1); // Randomly go back 1-50 years
    } else if (direction == FUTURE) {
        tm_info->tm_year += (rand() % 50 + 1); // Randomly go forward 1-50 years
    }
    
    mktime(tm_info); // Normalize struct tm
    
    // Add travel event
    addTimeTravelEvent(history, tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday, direction, destination);
}

void printWelcomeMessage() {
    printf("========================================\n");
    printf(" Welcome to the C Time Travel Simulator!\n");
    printf("----------------------------------------\n");
    printf(" Experience the thrill of traveling through time!\n");
    printf("========================================\n");
}

void printInstructions() {
    printf("Instructions:\n");
    printf("1. Type your desired destination in time (e.g., 'Ancient Rome', '2050 New York').\n");
    printf("2. Choose a direction: (1) Past or (2) Future.\n");
}

int main() {
    TimeTravelHistory history;
    initializeHistory(&history);
    
    printWelcomeMessage();
    printInstructions();
    
    char destination[MAX_MESSAGE_LENGTH];
    int choice;
    
    while (1) {
        printf("\nEnter your time travel destination: ");
        fgets(destination, MAX_MESSAGE_LENGTH, stdin);
        destination[strcspn(destination, "\n")] = 0; // remove newline
        
        printf("Choose your direction (1 for Past, 2 for Future): ");
        scanf("%d", &choice);
        getchar(); // absorb newline after scanf
        
        if (choice == 1) {
            timeTravel(destination, PAST, &history);
            printf("Traveling to the past to %s...\n", destination);
        } else if (choice == 2) {
            timeTravel(destination, FUTURE, &history);
            printf("Traveling to the future to %s...\n", destination);
        } else {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        
        listTimeTravelEvents(&history);
        
        char continueChoice;
        printf("Do you want to travel again? (y/n): ");
        scanf(" %c", &continueChoice);
        getchar(); // absorb newline
        
        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
    }
    
    printf("Thank you for using the C Time Travel Simulator. Safe travels!\n");
    return 0;
}