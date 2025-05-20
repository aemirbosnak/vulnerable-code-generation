//FormAI DATASET v1.0 Category: System event logger ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Defining constants
#define MAX_EVENTS 100
#define MAX_EVENT_NAME 30
#define MAX_DESCRIPTION 200

// Defining structs
typedef struct {
    char name[MAX_EVENT_NAME];
    char description[MAX_DESCRIPTION];
    time_t timestamp;
} Event;

// Function to generate a random name for an event
char* generateName() {
    char* names[] = {"Hackathon", "Cyberwarfare", "Neural Network Conference", "Virtual Reality Expo", 
                     "Quantum Computing Seminar", "AI Symposium", "Data Mining Summit", "Robotics Expo"};
    int index = rand() % 8;
    char* name = malloc(sizeof(names[index]));
    strcpy(name, names[index]);
    return name;
}

// Function to generate a random description for an event
char* generateDescription() {
    char* descriptions[] = {"A gathering of the top minds in cyber security", "An exhibition of the latest in virtual reality technology", 
                            "An exploration of the possibilities of artificial intelligence", "A showcase of robotics advancements", 
                            "A conference on the development of quantum computing", "A forum for the discussion of data mining techniques", 
                            "A seminar on neural network theory", "A battle for cyber dominance"};
    int index = rand() % 8;
    char* description = malloc(sizeof(descriptions[index]));
    strcpy(description, descriptions[index]);
    return description;
}

// Function to log an event
void logEvent(Event* event, int index) {
    FILE* fp = fopen("event_log.txt", "a");
    char* timeStr = ctime(&event->timestamp);
    // Removing the newline character from the time string
    timeStr[strlen(timeStr) - 1] = '\0';
    fprintf(fp, "Event %d: %s - %s (%s)\n", index, event->name, event->description, timeStr);
    fclose(fp);
}

int main() {
    srand(time(NULL));
    Event events[MAX_EVENTS];
    int numEvents = rand() % MAX_EVENTS + 1;
    printf("Generating %d events...\n", numEvents);
    for (int i = 0; i < numEvents; i++) {
        // Generating a random timestamp between 24 hours ago and now
        time_t timeStamp = time(NULL) - (rand() % 86400);
        Event event = {generateName(), generateDescription(), timeStamp};
        events[i] = event;
        logEvent(&event, i+1);
    }
    printf("Events have been logged to event_log.txt\n");
    return 0;
}