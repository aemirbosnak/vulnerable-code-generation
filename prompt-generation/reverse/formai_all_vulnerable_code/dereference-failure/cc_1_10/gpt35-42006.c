//FormAI DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* eventDescription);

int main() {
    srand(time(NULL));
    char* eventTypes[] = {"Success", "Warning", "Error"};
    char* successDescriptions[] = {"User logged in", "File uploaded successfully", "Task completed"};
    char* warningDescriptions[] = {"Password expiration warning", "Low disk space warning", "Network connectivity issue"};
    char* errorDescriptions[] = {"Server error 500", "Database connection failed", "File not found"};

    int i;
    for(i = 0; i < 10; i++){
        int eventTypeIndex = rand() % 3;
        char* eventType = eventTypes[eventTypeIndex];
        char* eventDescription;

        switch(eventTypeIndex){
            case 0:
                eventDescription = successDescriptions[rand() % 3];
                break;
            case 1:
                eventDescription = warningDescriptions[rand() % 3];
                break;
            case 2:
                eventDescription = errorDescriptions[rand() % 3];
                break;
        }

        logEvent(eventType, eventDescription);
    }

    return 0;
}

void logEvent(char* eventType, char* eventDescription){
    time_t currentTime;
    time(&currentTime);
    char* timeString = ctime(&currentTime);
    timeString[strlen(timeString) - 1] = '\0';

    FILE* filePtr = fopen("event_log.txt", "a");
    if(filePtr == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(filePtr, "[%s] %s: %s\n", eventType, timeString, eventDescription);
    fclose(filePtr);

    printf("Event logged successfully: [%s] %s: %s\n", eventType, timeString, eventDescription);
}