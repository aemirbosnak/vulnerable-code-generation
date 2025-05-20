//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct log_entry {
    char timestamp[25];
    char message[200];
} log_entry;

int main() {
    char filepath[100];
    printf("Enter the path of the log file: ");
    scanf("%s", filepath);

    FILE* log_file = fopen(filepath, "r");
    if (log_file == NULL) {
        printf("Error! Could not open the log file.");
        exit(1);
    }

    log_entry entries[1000];
    char line[225];
    int num_entries = 0;

    while (fgets(line, 225, log_file) != NULL) {
        char* timestamp = strtok(line, ",");
        char* message = strtok(NULL, "\n");
        strcpy(entries[num_entries].timestamp, timestamp);
        strcpy(entries[num_entries].message, message);
        num_entries++;
    }

    fclose(log_file);

    printf("Total number of log entries: %d\n", num_entries);
    printf("==============================\n");
    printf("Timestamp\t|\tMessage\n");
    printf("==============================\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t|\t%s\n", entries[i].timestamp, entries[i].message);
    }

    printf("==============================\n");

    char search_string[200];
    printf("Enter the search string: ");
    scanf("%s", search_string);

    printf("==============================\n");
    printf("Timestamp\t|\tMessage\n");
    printf("==============================\n");

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].message, search_string) != NULL) {
            printf("%s\t|\t%s\n", entries[i].timestamp, entries[i].message);
        }
    }
    printf("==============================\n");

    return 0;
}