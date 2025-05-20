//Gemma-7B DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Define the event logger structure
typedef struct EventLogger {
    char *name;
    int capacity;
    char **events;
    int currentEventIndex;
} EventLogger;

// Create an event logger
EventLogger *createEventLogger(char *name, int capacity) {
    EventLogger *logger = malloc(sizeof(EventLogger));
    logger->name = name;
    logger->capacity = capacity;
    logger->events = malloc(capacity * sizeof(char *));
    logger->currentEventIndex = 0;

    return logger;
}

// Log an event
void logEvent(EventLogger *logger, char *event) {
    logger->events[logger->currentEventIndex] = event;
    logger->currentEventIndex++;

    if (logger->currentEventIndex == logger->capacity) {
        logger->currentEventIndex = 0;
    }
}

int main() {
    // Create two event loggers, one for each side
    EventLogger *loggerA = createEventLogger("Team A", 10);
    EventLogger *loggerB = createEventLogger("Team B", 10);

    // Log events
    logEvent(loggerA, "Team A scored a goal!");
    logEvent(loggerB, "Team B scored a goal!");
    logEvent(loggerA, "Team A won the game!");

    // Print events
    for (int i = 0; i < loggerA->currentEventIndex; i++) {
        printf("%s\n", loggerA->events[i]);
    }

    for (int i = 0; i < loggerB->currentEventIndex; i++) {
        printf("%s\n", loggerB->events[i]);
    }

    return 0;
}