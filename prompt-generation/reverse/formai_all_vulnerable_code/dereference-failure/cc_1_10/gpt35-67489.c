//FormAI DATASET v1.0 Category: Log analysis ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* date;
    char* time;
    char* level;
    char* message;
} Log;

int main() {

    Log* logs = malloc(sizeof(Log) * 1000); // assuming there are at most 1000 logs
    int count = 0;
    char input[100];

    // Read log data from standard input
    while (fgets(input, 100, stdin) != NULL) {
        char* token = strtok(input, " ");
        int tokenCount = 0;
        Log log;
        
        // Parse each token into the corresponding log field
        while (token != NULL) {
            tokenCount++;
            switch (tokenCount) {
            case 1:
                log.date = malloc(strlen(token) + 1);
                strcpy(log.date, token);
                break;
            case 2:
                log.time = malloc(strlen(token) + 1);
                strcpy(log.time, token);
                break;
            case 3:
                log.level = malloc(strlen(token) + 1);
                strcpy(log.level, token);
                break;
            default:
                if (log.message == NULL) {
                    log.message = malloc(strlen(token) + 1);
                    strcpy(log.message, token);
                } else {
                    char* newMessage = malloc(strlen(log.message) + strlen(token) + 2);
                    strcpy(newMessage, log.message);
                    strcat(newMessage, " ");
                    strcat(newMessage, token);
                    free(log.message);
                    log.message = newMessage;
                }
                break;
            }
            token = strtok(NULL, " ");
        }
        logs[count] = log;
        count++;
    }

    // Print out each log in a decentralized way
    for (int i = 0; i < count; i++) {
        printf("Date: %s\n", logs[i].date);
        printf("Time: %s\n", logs[i].time);
        printf("Level: %s\n", logs[i].level);
        printf("Message: %s\n\n", logs[i].message);

        free(logs[i].date);
        free(logs[i].time);
        free(logs[i].level);
        free(logs[i].message);
    }

    free(logs);
    return 0;
}