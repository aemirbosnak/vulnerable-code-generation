//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define MAX_LOG_FILES 10

// Structure to hold log data
typedef struct {
    char *file_name;
    char *message;
} log_data_t;

// Function to parse log files and store data in a array
void parse_log_files(char *const *log_files) {
    int i;
    log_data_t *log_data = calloc(MAX_LOG_FILES, sizeof(log_data_t));

    for (i = 0; i < MAX_LOG_FILES; i++) {
        FILE *file = fopen(log_files[i], "r");
        char line[MAX_LINE_LEN];

        while (fgets(line, MAX_LINE_LEN, file)) {
            // Check if line is a log message
            if (strlen(line) > 0 && line[0] != '#') {
                log_data[i].message = line;
                log_data[i].file_name = log_files[i];
                break;
            }
        }
        fclose(file);
    }
}

// Function to print log data
void print_log_data(log_data_t *log_data, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%s: %s\n", log_data[i].file_name, log_data[i].message);
    }
}

int main() {
    char *log_files[] = {"example1.log", "example2.log", "example3.log"};
    log_data_t log_data[MAX_LOG_FILES];

    // Parse log files
    parse_log_files(log_files);

    // Print log data
    print_log_data(log_data, sizeof(log_data) / sizeof(log_data_t));

    return 0;
}