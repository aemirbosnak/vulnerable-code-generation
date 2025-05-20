//FormAI DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef struct SystemEvent {
    int eventID;
    char description[100];
    struct tm timestamp;
} SystemEvent;

SystemEvent eventLog[MAX_EVENTS];
int numEvents = 0;

void logEvent(char* description) {
    if(numEvents >= MAX_EVENTS) {
        printf("Error: Event log is full. Cannot log more events.\n");
        return;
    }
    
    SystemEvent newEvent;
    newEvent.eventID = numEvents + 1;
    strcpy(newEvent.description, description);
    time_t now = time(NULL);
    newEvent.timestamp = *localtime(&now);
    
    eventLog[numEvents++] = newEvent;
    
    printf("Event Logged:\n");
    printf("Event ID: %d\n", newEvent.eventID);
    printf("Description: %s\n", newEvent.description);
    printf("Timestamp: %d-%02d-%02d %02d:%02d:%02d\n", 
            newEvent.timestamp.tm_year + 1900, newEvent.timestamp.tm_mon + 1, newEvent.timestamp.tm_mday,
            newEvent.timestamp.tm_hour, newEvent.timestamp.tm_min, newEvent.timestamp.tm_sec);
}

int main() {
    printf("Welcome to the System Event Logger!\n");
    printf("Please enter events to log or type 'exit' to quit:\n");
    
    char input[100];
    while(scanf("%[^\n]%*c", input) == 1) {
        if(strcmp(input, "exit") == 0) break;
        logEvent(input);
    }
    
    printf("Event Log:\n");
    for(int i = 0; i < numEvents; i++) {
        SystemEvent e = eventLog[i];
        printf("Event ID: %d\n", e.eventID);
        printf("Description: %s\n", e.description);
        printf("Timestamp: %d-%02d-%02d %02d:%02d:%02d\n", 
                e.timestamp.tm_year + 1900, e.timestamp.tm_mon + 1, e.timestamp.tm_mday,
                e.timestamp.tm_hour, e.timestamp.tm_min, e.timestamp.tm_sec);
    }
    
    printf("Thank you for using the System Event Logger!\n");
    return 0;
}