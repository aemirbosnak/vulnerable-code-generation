//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 1024

typedef struct {
    char *message;
    int timestamp;
    char *level;
} log_entry;

log_entry log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void read_log_file(char *filename) {
    FILE *fp;
    char line[MAX_LOG_ENTRY_SIZE];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LOG_ENTRY_SIZE, fp) != NULL) {
        char *message = strdup(line);
        int timestamp = strtol(strtok(line, " "), NULL, 10);
        char *level = strdup(strtok(NULL, " "));

        if (num_log_entries < MAX_LOG_ENTRIES) {
            log_entries[num_log_entries].message = message;
            log_entries[num_log_entries].timestamp = timestamp;
            log_entries[num_log_entries].level = level;
            num_log_entries++;
        } else {
            free(message);
            free(level);
        }
    }

    fclose(fp);
}

void print_log_entries() {
    int i;

    for (i = 0; i < num_log_entries; i++) {
        printf("%d %s %s\n",
            log_entries[i].timestamp,
            log_entries[i].level,
            log_entries[i].message
        );
    }
}

void free_log_entries() {
    int i;

    for (i = 0; i < num_log_entries; i++) {
        free(log_entries[i].message);
        free(log_entries[i].level);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_log_file(argv[1]);
    print_log_entries();
    free_log_entries();

    return EXIT_SUCCESS;
}