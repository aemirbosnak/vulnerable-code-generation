//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <time.h> // for timestamp
#include <stdlib.h> // for rand()
#include <string.h> // for string functions

int main() {

    // define variables
    char eventName[50];
    char eventMessage[200];
    char eventType[10];
    int eventCode;
    time_t now;
    struct tm *local;

    // prompt user to input event details
    printf("Enter event name: ");
    fgets(eventName, 50, stdin);
    printf("Enter event message: ");
    fgets(eventMessage, 200, stdin);
    printf("Enter event code (integer between 0-999): ");
    scanf("%d", &eventCode);
    getchar(); // to clear stdin buffer
    printf("Enter event type (ERROR, WARNING, INFO): ");
    fgets(eventType, 10, stdin);

    // get current timestamp
    now = time(NULL);
    local = localtime(&now);

    // generate log file name based on date and time
    char logFileName[30];
    sprintf(logFileName, "log_%02d%02d%02d_%02d%02d%02d.txt", 
            local->tm_year+1900, local->tm_mon+1, local->tm_mday,
            local->tm_hour, local->tm_min, local->tm_sec);

    // open log file
    FILE *logFile = fopen(logFileName, "a");
    if(logFile == NULL) {
        printf("Error opening log file!");
        exit(1);
    }

    // generate random event ID
    srand(time(NULL));
    int eventID = rand() % 10000;

    // print event details to log file
    fprintf(logFile, "Event ID: %d\n", eventID);
    fprintf(logFile, "Event Name: %s", eventName);
    fprintf(logFile, "Event Message: %s", eventMessage);
    fprintf(logFile, "Event Code: %03d\n", eventCode);
    fprintf(logFile, "Event Type: %s", eventType);
    fprintf(logFile, "Timestamp: %02d/%02d/%02d %02d:%02d:%02d\n\n",
            local->tm_year+1900, local->tm_mon+1, local->tm_mday,
            local->tm_hour, local->tm_min, local->tm_sec);

    // close log file
    fclose(logFile);

    // display success message to console
    printf("Event logged successfully to file %s!\n", logFileName);

    return 0;
}