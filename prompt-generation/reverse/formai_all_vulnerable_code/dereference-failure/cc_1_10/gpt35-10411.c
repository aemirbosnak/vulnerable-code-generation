//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 1000
#define MAX_ERROR_CODE_LEN 10
#define MAX_ERROR_MSG_LEN 100

typedef struct {
    char* timestamp;
    char* error_code;
    char* error_msg;
} log_entry;

int num_logs = 0;
log_entry logs[MAX_LOGS];

int error_count[MAX_LOGS] = {0};

void parse_log_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Cannot open log file %s\n", filename);
        exit(1);
    }
    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while((read = getline(&line, &len, fp)) != -1) {
        if(num_logs >= MAX_LOGS) {
            printf("Error: Maximum number of logs exceeded.");
            exit(1);
        }

        // Split the log line into timestamp, error code and error message
        char* tok = strtok(line, ",");
        char* timestamp = strdup(tok);
        tok = strtok(NULL, ",");
        char* error_code = strdup(tok);
        tok = strtok(NULL, ",");
        char* error_msg = strdup(tok);

        logs[num_logs].timestamp = timestamp;
        logs[num_logs].error_code = error_code;
        logs[num_logs].error_msg = error_msg;

        num_logs++;
    }
    fclose(fp);
    if(line) {
        free(line);
    }
}

void count_errors() {
    for(int i = 0; i < num_logs; i++) {
        for(int j = 0; j < num_logs; j++) {

            // Ignore the same log entry
            if(i == j) {
                continue;
            }

            if(strcmp(logs[i].error_code, logs[j].error_code) == 0 && 
                    strcmp(logs[i].error_msg, logs[j].error_msg) == 0) {
                error_count[i]++;
            }
        }
    }
}

void print_logs() {
    printf("%-30s %-20s %s\n", "Timestamp", "Error Code", "Error Message");
    for(int i = 0; i < num_logs; i++) {
        printf("%-30s %-20s %s\n", logs[i].timestamp, logs[i].error_code, logs[i].error_msg);
    }
}

void print_error_count() {
    printf("%-30s %-20s %s\n", "Timestamp", "Error Code", "Error Message");
    for(int i = 0; i < num_logs; i++) {
        printf("%-30s %-20s %s %d\n", logs[i].timestamp, logs[i].error_code, 
                logs[i].error_msg, error_count[i]);
    }
}

int main() {
    char* filename = "server.log";
    parse_log_file(filename);
    count_errors();
    print_logs();
    print_error_count();
    return 0;
}