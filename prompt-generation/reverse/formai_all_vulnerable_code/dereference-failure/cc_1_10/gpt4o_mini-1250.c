//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define INITIAL_LOG_SIZE 10
#define KEYWORDS_COUNT 3

const char *keywords[KEYWORDS_COUNT] = {
    "failed password",
    "invalid user",
    "authentication failure"
};

typedef struct {
    char **logs;
    size_t count;
    size_t capacity;
} LogList;

void initialize_log_list(LogList *list) {
    list->logs = malloc(INITIAL_LOG_SIZE * sizeof(char *));
    list->count = 0;
    list->capacity = INITIAL_LOG_SIZE;
}

void free_log_list(LogList *list) {
    for (size_t i = 0; i < list->count; i++) {
        free(list->logs[i]);
    }
    free(list->logs);
}

void add_log(LogList *list, const char *log_entry) {
    if (list->count == list->capacity) {
        list->capacity *= 2;
        list->logs = realloc(list->logs, list->capacity * sizeof(char *));
    }
    list->logs[list->count] = strdup(log_entry);
    list->count++;
}

bool contains_keyword(const char *line) {
    for (int i = 0; i < KEYWORDS_COUNT; i++) {
        if (strstr(line, keywords[i]) != NULL) {
            return true;
        }
    }
    return false;
}

void monitor_log_file(const char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    LogList log_entries;
    ssize_t result;

    initialize_log_list(&log_entries);
    
    file = fopen(filename, "r");
    if (!file) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    // Move to the end of the file
    fseek(file, 0, SEEK_END);
    
    while (true) {
        while ((result = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
            buffer[result] = '\0'; // Null-terminate the buffer
            char *line = strtok(buffer, "\n");
            while (line != NULL) {
                if (contains_keyword(line)) {
                    printf("Intrusion detected: %s\n", line);
                    add_log(&log_entries, line);
                }
                line = strtok(NULL, "\n");
            }
        }

        // Wait for new logs to be appended
        sleep(5);
        fflush(stdout);
        fseek(file, 0, SEEK_END); // Move to the end of the file again
    }

    fclose(file);
    free_log_list(&log_entries);
}

int main() {
    monitor_log_file("/var/log/syslog");
    return 0;
}