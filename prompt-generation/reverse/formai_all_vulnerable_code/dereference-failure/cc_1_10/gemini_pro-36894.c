//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Structure to store a single log entry
typedef struct {
    char *timestamp;
    char *level;
    char *message;
} log_entry;

// Function to parse a log line into a log entry struct
log_entry *parse_log_line(char *line) {
    log_entry *entry = malloc(sizeof(log_entry));
    if (!entry) {
        fprintf(stderr, "Failed to allocate memory for log entry\n");
        return NULL;
    }

    // Regex to match a log line
    regex_t regex;
    int rc = regcomp(&regex, "^\\[([0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2})\\] \\[([A-Z]+)\\] (.*)", REG_EXTENDED);
    if (rc != 0) {
        fprintf(stderr, "Failed to compile regex: %s\n", regerror(rc, &regex, NULL, 0));
        regfree(&regex);
        free(entry);
        return NULL;
    }

    // Match the log line against the regex
    regmatch_t matches[4];
    rc = regexec(&regex, line, 4, matches, 0);
    regfree(&regex);
    if (rc != 0) {
        fprintf(stderr, "Failed to match log line: %s\n", line);
        free(entry);
        return NULL;
    }

    // Extract the timestamp, level, and message from the matches
    entry->timestamp = strndup(line + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
    entry->level = strndup(line + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so);
    entry->message = strndup(line + matches[3].rm_so, matches[3].rm_eo - matches[3].rm_so);

    return entry;
}

// Function to free a log entry struct
void free_log_entry(log_entry *entry) {
    free(entry->timestamp);
    free(entry->level);
    free(entry->message);
    free(entry);
}

// Main function
int main() {
    // Open the log file
    FILE *fp = fopen("log.txt", "r");
    if (!fp) {
        fprintf(stderr, "Failed to open log file\n");
        return EXIT_FAILURE;
    }

    // Read the log file line by line
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the log line into a log entry struct
        log_entry *entry = parse_log_line(line);
        if (!entry) {
            fprintf(stderr, "Failed to parse log line: %s\n", line);
            continue;
        }

        // Print the log entry to the console
        printf("[%s] [%s] %s\n", entry->timestamp, entry->level, entry->message);

        // Free the log entry struct
        free_log_entry(entry);
    }

    // Close the log file
    fclose(fp);

    return EXIT_SUCCESS;
}