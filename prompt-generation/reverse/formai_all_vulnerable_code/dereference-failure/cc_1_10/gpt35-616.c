//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 1000

void checkLogs(char **logs, int numLogs);
int isSuspicious(char *log);

int main(void) {
    char *logs[MAX_LOGS];
    int numLogs = 0;

    // Open log file
    FILE *file = fopen("logs.txt", "r");
    if (file == NULL) {
        printf("Error opening log file.");
        return 1;
    }

    // Read logs from file into array
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, file)) != -1 && numLogs < MAX_LOGS) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        // Allocate memory for log and copy line into it
        char *log = malloc(strlen(line) + 1);
        strcpy(log, line);

        // Add log to logs array and increment counter
        logs[numLogs] = log;
        numLogs++;
    }

    // Close file and free memory for line
    fclose(file);
    if (line) {
        free(line);
    }

    // Check logs for suspicious activity
    checkLogs(logs, numLogs);

    // Free memory for logs
    for (int i = 0; i < numLogs; i++) {
        free(logs[i]);
    }

    return 0;
}

void checkLogs(char **logs, int numLogs) {
    for (int i = 0; i < numLogs; i++) {
        if (isSuspicious(logs[i])) {
            printf("Suspicious activity detected! Log: %s\n", logs[i]);
        }
    }
}

int isSuspicious(char *log) {
    // Check for keywords indicating suspicious activity
    if (strstr(log, "root") != NULL && strstr(log, "login") != NULL) {
        return 1;
    }
    if (strstr(log, "sudo") != NULL && strstr(log, "rm") != NULL) {
        return 1;
    }
    if (strstr(log, "ssh") != NULL && strstr(log, "invalid user") != NULL) {
        return 1;
    }

    return 0;
}