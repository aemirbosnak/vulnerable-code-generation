//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LOG_SIZE 1024 * 1024 // 1 MB
#define MAX_LOG_FILES 10

// Structure to hold log data
typedef struct {
    char *message;
    time_t timestamp;
} log_entry_t;

// Function to parse log files and print summary
void print_summary(const char *log_file) {
    int files_processed = 0;
    int total_messages = 0;
    int total_messages_today = 0;
    int total_messages_this_week = 0;
    int total_messages_this_month = 0;
    int total_messages_last_month = 0;
    int total_messages_last_week = 0;
    int total_messages_last_year = 0;

    // Open log file and read lines
    FILE *file = fopen(log_file, "r");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Extract timestamp and message from line
        log_entry_t entry;
        char *timestamp = strtok(line, " ");
        char *message = strtok(NULL, "\n");
        entry.timestamp = strtol(timestamp, NULL, 10);
        entry.message = message;

        // Update statistics based on timestamp
        if (entry.timestamp >= time(NULL)) {
            total_messages_today++;
        } else if (entry.timestamp >= (time(NULL) - 7 * 24 * 60 * 60) && entry.timestamp < time(NULL)) {
            total_messages_this_week++;
        } else if (entry.timestamp >= (time(NULL) - 30 * 24 * 60 * 60) && entry.timestamp < (time(NULL) - 7 * 24 * 60 * 60)) {
            total_messages_this_month++;
        } else if (entry.timestamp >= (time(NULL) - 365 * 24 * 60 * 60) && entry.timestamp < (time(NULL) - 30 * 24 * 60 * 60)) {
            total_messages_last_month++;
        } else {
            total_messages_last_year++;
        }

        // Print summary statistics
        if (files_processed == 0) {
            printf("Log Analysis Summary:\n");
        }
        printf("Total Messages:\t%d\n", total_messages);
        printf("Today Messages:\t%d\n", total_messages_today);
        printf("This Week Messages:\t%d\n", total_messages_this_week);
        printf("This Month Messages:\t%d\n", total_messages_this_month);
        printf("Last Month Messages:\t%d\n", total_messages_last_month);
        printf("Last Year Messages:\t%d\n", total_messages_last_year);

        // Increment files processed
        files_processed++;
    }

    // Close log file
    fclose(file);
}

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    // Open log file and print summary
    print_summary(argv[1]);

    return 0;
}