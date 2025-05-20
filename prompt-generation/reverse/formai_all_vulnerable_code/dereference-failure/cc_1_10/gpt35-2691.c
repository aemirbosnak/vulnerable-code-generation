//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 10000

// define a struct to represent a system event
struct SystemEvent {
    char timestamp[20];
    char level[10];
    char message[100];
};

// define a global array to store system events
struct SystemEvent eventLog[MAX_EVENTS];

// define a variable to keep track of number of events logged
int numOfEvents = 0;

// function to log a system event
void logEvent(char* level, char* message) {
    // get current time
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", timeinfo);

    // create the new event
    struct SystemEvent event;
    strcpy(event.timestamp, timestamp);
    strcpy(event.level, level);
    strcpy(event.message, message);

    // add the new event to the event log
    if(numOfEvents < MAX_EVENTS) {
        eventLog[numOfEvents++] = event;
        printf("[%s] %s: %s\n", event.timestamp, event.level, event.message);
    }
}

// function to print all system events in the log
void printEventLog() {
    printf("EVENT LOG:\n");
    for(int i = 0; i < numOfEvents; i++) {
        printf("[%s] %s: %s\n", eventLog[i].timestamp, eventLog[i].level, eventLog[i].message);
    }
}

int main() {
    // log some example events
    logEvent("INFO", "Program started");
    logEvent("WARNING", "Memory usage high");
    logEvent("ERROR", "File not found");
    
    // print the event log
    printEventLog();
    
    return 0;
}