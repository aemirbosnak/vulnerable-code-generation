//FormAI DATASET v1.0 Category: System event logger ; Style: recursive
#include <stdio.h>
#include <time.h>

void logEvent(char* eventType, char* eventName, char* eventTime) {
    FILE* file = fopen("eventLog.txt", "a+");
    fprintf(file, "[%s][%s]: %s\n", eventTime, eventType, eventName);
    fclose(file);
}

void logMessage(char* message) {
    time_t currTime;
    currTime = time(NULL);
    char* eventTime = ctime(&currTime);
    eventTime[strlen(eventTime) - 1] = '\0'; //Removing the newline character from timestamp

    logEvent("INFO", message, eventTime);
}

void logError(char* errorMessage) {
    time_t currTime;
    currTime = time(NULL);
    char* eventTime = ctime(&currTime);
    eventTime[strlen(eventTime) - 1] = '\0'; //Removing the newline character from timestamp

    logEvent("ERROR", errorMessage, eventTime);
}

void logWarning(char* warningMessage) {
    time_t currTime;
    currTime = time(NULL);
    char* eventTime = ctime(&currTime);
    eventTime[strlen(eventTime) - 1] = '\0'; //Removing the newline character from timestamp

    logEvent("WARNING", warningMessage, eventTime);
}

void recursiveFunction(int i) {
    if (i == 10) {
        logMessage("Recursive function completed successfully");
        return;
    }

    if (i % 2 == 0) {
        logWarning("Even number encountered in recursive function");
    }

    char message[100];
    sprintf(message, "Iteration %d in recursive function", i);
    logMessage(message);

    recursiveFunction(i + 1);
}

int main() {
    logMessage("Program started");

    recursiveFunction(1);

    logMessage("Program ended");

    return 0;
}