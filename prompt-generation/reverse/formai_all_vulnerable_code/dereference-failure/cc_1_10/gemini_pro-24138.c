//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <regex.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_ENTRIES 1000
#define MAX_REGEXP_LENGTH 256

typedef struct {
    time_t timestamp;
    char *message;
} log_entry;

log_entry log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void parse_log_file(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Extract timestamp
        char *timestamp_str = strtok(line, " ");
        time_t timestamp = strtol(timestamp_str, NULL, 10);

        // Extract message
        char *message = strtok(NULL, "");

        // Add log entry to array
        log_entries[num_log_entries].timestamp = timestamp;
        log_entries[num_log_entries].message = strdup(message);
        num_log_entries++;
    }
}

void print_log_entries() {
    for (int i = 0; i < num_log_entries; i++) {
        printf("%s %s\n", ctime(&log_entries[i].timestamp), log_entries[i].message);
    }
}

void filter_log_entries(const char *regexp) {
    regex_t regex;
    int reti;

    // Compile regular expression
    reti = regcomp(&regex, regexp, REG_EXTENDED);
    if (reti != 0) {
        fprintf(stderr, "Error compiling regular expression: %s\n", regexp);
        exit(EXIT_FAILURE);
    }

    // Filter log entries
    for (int i = 0; i < num_log_entries; i++) {
        if (regexec(&regex, log_entries[i].message, 0, NULL, 0) == 0) {
            printf("%s %s\n", ctime(&log_entries[i].timestamp), log_entries[i].message);
        }
    }

    // Free regular expression
    regfree(&regex);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open log file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Parse log file
    parse_log_file(fp);

    // Close log file
    fclose(fp);

    // Print log entries
    print_log_entries();

    // Filter log entries
    char regexp[MAX_REGEXP_LENGTH];
    printf("Enter regular expression to filter log entries: ");
    scanf("%s", regexp);
    filter_log_entries(regexp);

    return 0;
}