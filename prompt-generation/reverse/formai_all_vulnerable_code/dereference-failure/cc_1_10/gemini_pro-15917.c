//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Structure to store log entry data
typedef struct log_entry {
    time_t timestamp;
    char *message;
} log_entry;

// Function to parse a log line and extract data into a log_entry struct
log_entry *parse_log_line(char *line) {
    // Allocate memory for the log_entry struct
    log_entry *entry = malloc(sizeof(log_entry));

    // Parse the timestamp
    char *timestamp_str = strtok(line, " ");
    struct tm timestamp_tm;
    strptime(timestamp_str, "%Y-%m-%d %H:%M:%S", &timestamp_tm);
    entry->timestamp = mktime(&timestamp_tm);

    // Parse the message
    char *message = strtok(NULL, "\n");
    entry->message = malloc(strlen(message) + 1);
    strcpy(entry->message, message);

    // Return the log_entry struct
    return entry;
}

// Function to print a log_entry struct
void print_log_entry(log_entry *entry) {
    printf("%s %s\n", ctime(&entry->timestamp), entry->message);
}

// Main function
int main() {
    // Open the log file for reading
    FILE *log_file = fopen("log.txt", "r");

    // Check if the file was opened successfully
    if (log_file == NULL) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }

    // Read each line from the log file and parse it
    char line[1024];
    while (fgets(line, sizeof(line), log_file)) {
        log_entry *entry = parse_log_line(line);

        // Print the log_entry struct
        print_log_entry(entry);

        // Free the memory allocated for the log_entry struct
        free(entry->message);
        free(entry);
    }

    // Close the log file
    fclose(log_file);

    // Return success
    return EXIT_SUCCESS;
}