//FormAI DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[50];
    char log_type[20];
    char message[100];
} LogEntry;

int main() {
    LogEntry logs[MAX_LOG_ENTRIES];
    int num_logs = 0;
    char filename[30] = "sample.log";
    FILE* fp = fopen(filename, "r");

    if (!fp) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        char* timestamp = strtok(line, " ");
        char* log_type = strtok(NULL, " ");
        char* message = strtok(NULL, "\n");

        LogEntry new_entry;
        strcpy(new_entry.timestamp, timestamp);
        strcpy(new_entry.log_type, log_type);
        strcpy(new_entry.message, message);

        logs[num_logs++] = new_entry;
    }

    fclose(fp);

    printf("\nLogs in %s\n", filename);
    printf("==========================\n");
    printf("%-20s%-20s%s\n", "Timestamp", "Log Type", "Message");
    printf("==========================\n");
    for (int i = 0; i < num_logs; i++) {
        printf("%-20s%-20s%s\n", logs[i].timestamp, logs[i].log_type, logs[i].message);
    }
    printf("==========================\n");

    return 0;
}