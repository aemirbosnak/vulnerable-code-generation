//FormAI DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random event ID
int generateEventID() {
    srand(time(NULL));
    return rand();
}

// Function to write to the log file
void writeToLog(char* message) {
    FILE *file = fopen("event_log.txt", "a");
    fputs(message, file);
    fclose(file);
}

// Struct to hold information about an event
typedef struct {
    int id;
    char* name;
    char* description;
    time_t timestamp;
} Event;

// Function to create a new event
Event* createEvent(char* name, char* description) {
    Event* e = (Event*) malloc(sizeof(Event));
    e->id = generateEventID();
    e->name = name;
    e->description = description;
    e->timestamp = time(NULL);
    return e;
}

int main() {
    // Create a new event and write it to the log file
    Event* e = createEvent("System Restart", "The system has been restarted");
    char* message = (char*) malloc(sizeof(char) * 100);
    sprintf(message, "Event ID: %d, Name: %s, Description: %s, Timestamp: %ld\n", e->id, e->name, e->description, e->timestamp);
    writeToLog(message);
    
    // Create another event and write it to the log file
    e = createEvent("File Modified", "A file has been modified");
    sprintf(message, "Event ID: %d, Name: %s, Description: %s, Timestamp: %ld\n", e->id, e->name, e->description, e->timestamp);
    writeToLog(message);
    
    // Create a third event and write it to the log file
    e = createEvent("User Login", "A user has logged in");
    sprintf(message, "Event ID: %d, Name: %s, Description: %s, Timestamp: %ld\n", e->id, e->name, e->description, e->timestamp);
    writeToLog(message);
    
    printf("Events logged successfully\n");
    free(message);
    free(e);
    return 0;
}