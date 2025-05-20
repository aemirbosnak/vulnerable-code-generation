//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILE_SIZE 100000

// Structure to store log data
typedef struct {
    int line_number;
    char timestamp[20];
    char client_ip[20];
    char client_agent[50];
    int request_method;
    int request_status;
    int response_status;
    int response_size;
} log_entry_t;

// Function to parse log file and store data in a array
void parse_log_file(char *log_file_path) {
    FILE *file = fopen(log_file_path, "r");
    char line[MAX_LINE_LENGTH];
    log_entry_t *entries = calloc(1, sizeof(log_entry_t));
    int num_entries = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Ignore empty lines and lines starting with "#"
        if (line[0] == '\n' || line[0] == '#') {
            continue;
        }

        // Parse log line and extract fields
        char *token;
        token = strtok(line, "\t ");
        entries[num_entries].line_number = atoi(token);
        token = strtok(NULL, "\t ");
        strcpy(entries[num_entries].timestamp, token);
        token = strtok(NULL, "\t ");
        strcpy(entries[num_entries].client_ip, token);
        token = strtok(NULL, "\t ");
        strcpy(entries[num_entries].client_agent, token);
        token = strtok(NULL, "\t ");
        entries[num_entries].request_method = atoi(token);
        token = strtok(NULL, "\t ");
        entries[num_entries].request_status = atoi(token);
        token = strtok(NULL, "\t ");
        entries[num_entries].response_status = atoi(token);
        token = strtok(NULL, "\t ");
        entries[num_entries].response_size = atoi(token);

        num_entries++;
    }

    fclose(file);

    // Calculate statistics
    int total_requests = 0;
    int total_ok_requests = 0;
    int total_error_requests = 0;
    int total_size = 0;

    for (int i = 0; i < num_entries; i++) {
        if (entries[i].request_status == 200) {
            total_ok_requests++;
            total_size += entries[i].response_size;
        } else {
            total_error_requests++;
        }
        total_requests++;
    }

    // Print statistics
    printf("Log File Statistics:\n");
    printf("Total Requests: %d\n", total_requests);
    printf("OK Requests: %d (%d%% of total)\n", total_ok_requests,
           (total_ok_requests * 100) / total_requests);
    printf("Error Requests: %d (%d%% of total)\n", total_error_requests,
           (total_error_requests * 100) / total_requests);
    printf("Average Response Size: %d bytes\n", total_size / total_ok_requests);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    char *log_file_path = argv[1];
    parse_log_file(log_file_path);

    return 0;
}