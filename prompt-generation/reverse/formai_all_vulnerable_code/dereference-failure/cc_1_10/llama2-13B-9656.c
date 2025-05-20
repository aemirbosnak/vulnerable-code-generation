//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LOG_LEN 1024
#define MAX_LINE_LEN 512
#define MAX_NUM_ENTRIES 1000

typedef struct {
    char *message;
    int severity;
    time_t timestamp;
} log_entry_t;

static void parse_log_line(char *line, log_entry_t *entry);
static void print_log_entry(log_entry_t *entry);

int main(void) {
    char log_buffer[MAX_LOG_LEN];
    char line[MAX_LINE_LEN];
    log_entry_t entries[MAX_NUM_ENTRIES];
    int num_entries = 0;

    // Open the log file
    FILE *log_file = fopen("example.log", "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    // Read the log file into a buffer
    fgets(log_buffer, MAX_LOG_LEN, log_file);
    log_buffer[strcspn(log_buffer, "\n")] = 0; // Remove the newline

    // Tokenize the log buffer into individual lines
    char *token = strtok(log_buffer, "\n");
    while (token != NULL) {
        // Parse each line and add it to the list of entries
        parse_log_line(token, entries + num_entries);
        num_entries++;

        // Check if we've reached the maximum number of entries
        if (num_entries >= MAX_NUM_ENTRIES) {
            break;
        }

        // Get the next line
        token = strtok(NULL, "\n");
    }

    // Print the list of entries
    for (int i = 0; i < num_entries; i++) {
        print_log_entry(entries + i);
    }

    // Close the log file
    fclose(log_file);

    return 0;
}

static void parse_log_line(char *line, log_entry_t *entry) {
    // Tokenize the line into the message and severity
    char *message = strtok(line, ":");
    char *severity = strtok(NULL, " ");

    // Extract the timestamp
    time_t timestamp = strtol(strtok(NULL, "\n"), NULL, 10);

    // Initialize the entry struct
    entry->message = message;
    entry->severity = atoi(severity);
    entry->timestamp = timestamp;
}

static void print_log_entry(log_entry_t *entry) {
    printf("%s [%d] %s\n", ctime(entry->timestamp), entry->severity, entry->message);
}