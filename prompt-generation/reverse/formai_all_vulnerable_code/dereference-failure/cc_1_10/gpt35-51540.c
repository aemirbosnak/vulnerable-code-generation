//FormAI DATASET v1.0 Category: System event logger ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define EVENT_LENGTH 100

// struct to represent a single event
struct Event {
    int id;
    char timestamp[30];
    char message[EVENT_LENGTH];
};

// global variable to keep track of current event ID
int eventId = 0;

// function to get current timestamp as a string
char* getTimestamp() {
    time_t rawtime;
    struct tm * timeinfo;
    char *timestamp = (char*) malloc(30 * sizeof(char));
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, 30, "%Y-%m-%d %H:%M:%S", timeinfo);
    return timestamp;
}

// function to log an event
void logEvent(char* message) {
    struct Event event;
    event.id = ++eventId;
    strcpy(event.timestamp, getTimestamp());
    strncpy(event.message, message, EVENT_LENGTH - 1);
    printf("Event logged: %d %s %s\n", event.id, event.timestamp, event.message);
}

// recursive function to log events in a random fashion
void logEvents(int numEvents, int maxTimeGap, char* messages[]) {
    if(numEvents <= 0) {
        return;
    }
    int idx = rand() % (sizeof(messages)/sizeof(char*)) ; 
    logEvent(messages[idx]);
    int sleepTime = rand() % maxTimeGap;
    printf("Waiting for %d seconds before logging next event\n", sleepTime);
    sleep(sleepTime);
    logEvents(numEvents - 1, maxTimeGap, messages);
}


int main() {
    char* messages[] = {"User logged in", "Transaction completed", "Data updated", "Error occurred", "Server started", "Server stopped"};
    srand(time(NULL));
    logEvents(10, 5, messages);
    return 0;
}