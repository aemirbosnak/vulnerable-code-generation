//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *event, char *message) {
    time_t currTime;
    char* timeStr;

    currTime = time(NULL);
    timeStr = ctime(&currTime);
    timeStr[strlen(timeStr) - 1] = '\0';
    
    FILE *file = fopen("event_log.txt", "a");
    
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    fprintf(file, "[%s] %s: %s\n", timeStr, event, message);
    
    fclose(file);
}

int main() {
    // simulate application events
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int eventNum = rand() % 4;
        char* eventStr;
        char* message;
        
        switch(eventNum) {
            case 0:
                eventStr = "INFO";
                message = "Application started";
                break;
            case 1:
                eventStr = "ERROR";
                message = "Division by zero";
                break;
            case 2:
                eventStr = "WARNING";
                message = "Memory allocation failed";
                break;
            case 3:
                eventStr = "DEBUG";
                message = "Program exited";
                break;
        }
        
        logEvent(eventStr, message);
    }
    
    return 0;
}