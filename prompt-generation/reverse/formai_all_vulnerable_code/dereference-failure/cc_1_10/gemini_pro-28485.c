//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Custom data structure to store log entry information
typedef struct {
    char *timestamp;
    char *level;
    char *message;
} LogEntry;

// Function to parse a log line and populate a LogEntry struct
LogEntry parse_log_line(char *line) {
    LogEntry entry;
    entry.timestamp = NULL;
    entry.level = NULL;
    entry.message = NULL;

    // Regex patterns for parsing
    char *timestamp_pattern = "^[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}";
    char *level_pattern = "\\b[A-Z]{1,4}\\b";

    // Allocate memory for timestamp, level, and message
    entry.timestamp = malloc(strlen(line) + 1);
    entry.level = malloc(strlen(line) + 1);
    entry.message = malloc(strlen(line) + 1);

    // Extract timestamp using regex
    regex_t timestamp_regex;
    regcomp(&timestamp_regex, timestamp_pattern, REG_EXTENDED);
    regexec(&timestamp_regex, line, 0, NULL, 0);
    size_t timestamp_start = regexec(&timestamp_regex, line, 0, NULL, 0);
    size_t timestamp_end = regexec(&timestamp_regex, line, 0, NULL, 0);
    strncpy(entry.timestamp, line + timestamp_start, timestamp_end - timestamp_start);

    // Extract level using regex
    regex_t level_regex;
    regcomp(&level_regex, level_pattern, REG_EXTENDED);
    regexec(&level_regex, line, 0, NULL, 0);
    size_t level_start = regexec(&level_regex, line, 0, NULL, 0);
    size_t level_end = regexec(&level_regex, line, 0, NULL, 0);
    strncpy(entry.level, line + level_start, level_end - level_start);

    // Extract message (remainder of the line)
    strncpy(entry.message, line + level_end, strlen(line) - level_end);

    // Clean up regex objects
    regfree(&timestamp_regex);
    regfree(&level_regex);

    return entry;
}

// Function to print a LogEntry
void print_log_entry(LogEntry entry) {
    printf("[%s] %s: %s\n", entry.timestamp, entry.level, entry.message);
}

// Main function
int main() {
    // Open the log file
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }

    // Read each line from the file and parse it
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        LogEntry entry = parse_log_line(line);
        print_log_entry(entry);

        // Free the allocated memory for the LogEntry
        free(entry.timestamp);
        free(entry.level);
        free(entry.message);
    }

    // Close the log file
    fclose(fp);

    return EXIT_SUCCESS;
}