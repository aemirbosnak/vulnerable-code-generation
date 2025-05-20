//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LogEntry {
    char action[20];
    char username[20];
    char timestamp[20];
};

int main() {
    struct LogEntry log[100]; // assuming max 100 log entries
    int index = 0;
    
    // read log file
    FILE *logFile = fopen("system.log", "r");
    char line[100];
    
    while(fgets(line, 100, logFile) != NULL) {
        char *token = strtok(line, ",");
        
        strcpy(log[index].action, token);
        
        token = strtok(NULL, ",");
        strcpy(log[index].username, token);
        
        token = strtok(NULL, ",");
        strcpy(log[index].timestamp, token);
        
        index++;
    }
    fclose(logFile);
    
    // check for intrusion
    // assumption: an intrusion is detected if there are more than 3 failed login attempts by the same username within 5 minutes
    char currentUsername[20];
    int failedAttempts = 0;
    char *lastFailedAttempt = NULL;
    
    for(int i = 0; i < index; i++) {
        if(strcmp(log[i].action, "login") == 0 && strcmp(log[i].username, currentUsername) != 0) {
            strcpy(currentUsername, log[i].username);
            failedAttempts = 0;
            lastFailedAttempt = NULL;
        } else if(strcmp(log[i].action, "login") == 0 && strcmp(log[i].username, currentUsername) == 0) {
            if(lastFailedAttempt && strcmp(log[i].timestamp, lastFailedAttempt) <= 300) { // timestamp difference <= 5 minutes
                failedAttempts++;
            } else {
                failedAttempts = 1;
                lastFailedAttempt = log[i].timestamp;
            }
            
            if(failedAttempts >= 3) {
                printf("Intrusion detected for username %s\n", currentUsername);
                // add code to handle intrusion (e.g. send email notification, terminate session, etc.)
            }
        }
    }
    
    return 0;
}