//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LOG_LEN 1024
#define MIN_LOG_LEN 10

struct log_entry {
    char timestamp[20];
    char level[10];
    char message[100];
};

void parse_log_line(char *line, struct log_entry *entry) {
    char *tok;
    char *time_str;
    char *level_str;
    char *message_str;

    tok = strtok(line, ":");
    time_str = strtok(NULL, ":");
    level_str = strtok(NULL, ":");
    message_str = strtok(NULL, "\n");

    strcpy(entry->timestamp, time_str);
    strcpy(entry->level, level_str);
    strcpy(entry->message, message_str);
}

void print_log_entry(struct log_entry *entry) {
    printf("%s %s %s\n", entry->timestamp, entry->level, entry->message);
}

int main() {
    char log_file[] = "example_log.txt";
    char line[MAX_LOG_LEN];
    struct log_entry entry;

    // Open the log file
    FILE *file = fopen(log_file, "r");
    if (file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    // Read the log file line by line
    while (fgets(line, MAX_LOG_LEN, file) != NULL) {
        // Parse the log line
        parse_log_line(line, &entry);

        // Print the log entry
        print_log_entry(&entry);
    }

    // Close the log file
    fclose(file);

    return 0;
}