//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a log entry
typedef struct {
    char *timestamp;
    char *source;
    char *message;
} log_entry;

// Define a function to parse a log line into a log entry struct
log_entry *parse_log_line(char *line) {
    log_entry *entry = malloc(sizeof(log_entry));

    // Extract the timestamp
    char *timestamp = strtok(line, " ");
    entry->timestamp = malloc(strlen(timestamp) + 1);
    strcpy(entry->timestamp, timestamp);

    // Extract the source
    char *source = strtok(NULL, " ");
    entry->source = malloc(strlen(source) + 1);
    strcpy(entry->source, source);

    // Extract the message
    char *message = strtok(NULL, "\n");
    entry->message = malloc(strlen(message) + 1);
    strcpy(entry->message, message);

    return entry;
}

// Define a function to print a log entry
void print_log_entry(log_entry *entry) {
    printf("%s %s: %s\n", entry->timestamp, entry->source, entry->message);
}

// Define a function to analyze a log file and print the most frequently occurring source
void analyze_log_file(char *filename) {
    // Open the log file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    // Create a hash table to store the source counts
    char **sources = malloc(100 * sizeof(char *));
    int source_count = 0;

    // Read each line of the log file
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        // Parse the log line into a log entry struct
        log_entry *entry = parse_log_line(line);

        int found = 0;
        for (int i = 0; i < source_count; i++) {
            if (strcmp(entry->source, sources[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            sources[source_count] = entry->source;
            source_count++;
        }
    }

    // Close the log file
    fclose(file);

    // Find the source with the highest count
    int max_count = 0;
    char *max_source = NULL;
    for (int i = 0; i < source_count; i++) {
        int count = 0;
        for (int j = 0; j < source_count; j++) {
            if (strcmp(sources[i], sources[j]) == 0) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            max_source = sources[i];
        }
    }

    // Print the source with the highest count
    printf("The most frequently occurring source is: %s (%d occurrences)\n", max_source, max_count);
}

int main(int argc, char *argv[]) {
    // Check if the user has specified a log file
    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Analyze the log file and print the most frequently occurring source
    analyze_log_file(argv[1]);

    return EXIT_SUCCESS;
}