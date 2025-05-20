//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000000

// The following is a custom data structure to store log records
typedef struct {
    char *timestamp;
    char *message;
} LogRecord;

// The following function parses a log file and stores the log records in an array
LogRecord *parse_log_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the log records
    LogRecord *log_records = malloc(sizeof(LogRecord) * MAX_LOG_SIZE);
    if (log_records == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Parse the log file
    int line_number = 0;
    while (1) {
        char line[1024];
        if (fgets(line, sizeof(line), file) == NULL) {
            break;
        }

        // Parse the timestamp and message from the line
        char *timestamp = strtok(line, " ");
        char *message = strtok(NULL, "\n");

        // Store the log record in the array
        log_records[line_number].timestamp = strdup(timestamp);
        log_records[line_number].message = strdup(message);

        line_number++;
    }

    // Close the file
    fclose(file);

    return log_records;
}

// The following function prints the log records to the console
void print_log_records(LogRecord *log_records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("%s %s\n", log_records[i].timestamp, log_records[i].message);
    }
}

// The following function frees the memory allocated for the log records
void free_log_records(LogRecord *log_records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        free(log_records[i].timestamp);
        free(log_records[i].message);
    }
    free(log_records);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    // Parse the log file
    LogRecord *log_records = parse_log_file(argv[1]);
    if (log_records == NULL) {
        return 1;
    }

    // Print the log records to the console
    int num_records = 0;
    while (log_records[num_records].timestamp != NULL) {
        num_records++;
    }
    print_log_records(log_records, num_records);

    // Free the memory allocated for the log records
    free_log_records(log_records, num_records);

    return 0;
}