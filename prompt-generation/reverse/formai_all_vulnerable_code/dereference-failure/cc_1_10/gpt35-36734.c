//FormAI DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <string.h>

// struct to save log data
typedef struct Log {
    char timestamp[50];
    char message[500];
} Log;

// function to parse log line and populate log struct
Log parse_log_line(char* line) {
    Log log;
    char* timestamp = strtok(line, ",");
    char* message = strtok(NULL, "");
    strcpy(log.timestamp, timestamp);
    strcpy(log.message, message);
    return log;
}

int main() {
    FILE* log_file;
    char* filename = "example.log";
    char line[550];
    Log logs[100];
    int num_logs = 0;

    // open log_file and read logs
    log_file = fopen(filename, "r");
    if (log_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    while (fgets(line, sizeof(line), log_file)) {
        Log log = parse_log_line(line);
        logs[num_logs] = log;
        num_logs++;
    }
    fclose(log_file);

    // analyze logs
    int num_warnings = 0;
    int num_errors = 0;
    for (int i = 0; i < num_logs; i++) {
        Log log = logs[i];
        if (strstr(log.message, "WARNING") != NULL) {
            num_warnings++;
        } else if (strstr(log.message, "ERROR") != NULL) {
            num_errors++;
        }
    }

    // print analysis results
    printf("log analysis results:\n");
    printf("number of warnings: %d\n", num_warnings);
    printf("number of errors: %d\n", num_errors);

    return 0;
}