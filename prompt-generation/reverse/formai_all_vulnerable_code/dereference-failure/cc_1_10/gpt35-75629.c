//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

struct log_entry {
    char timestamp[20];
    char message[1024];
};

struct log_file {
    struct log_entry entries[MAX_LOG_ENTRIES];
    int count;
};

int main() {
    FILE *fp;
    char filename[1024];
    struct log_file file = {0};

    printf("Enter log file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[1024];
    int i = 0;

    while (fgets(line, 1024, fp) != NULL) {
        char *timestamp = strtok(line, ",");
        char *message = strtok(NULL, "\n");

        strcpy(file.entries[i].timestamp, timestamp);
        strcpy(file.entries[i].message, message);

        i++;

        if (i == MAX_LOG_ENTRIES) {
            break;
        }
    }

    file.count = i;

    fclose(fp);

    printf("Total log entries: %d\n", file.count);

    printf("Enter search keyword: ");
    char search[1024];
    scanf("%s", search);

    int found = 0;

    for (int i = 0; i < file.count; i++) {
        if (strstr(file.entries[i].message, search) != NULL) {
            printf("[%s] %s\n", file.entries[i].timestamp, file.entries[i].message);
            found++;
        }
    }

    if (found == 0) {
        printf("No matching entries found.\n");
    }

    return 0;
}