//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LEN 1024
#define MAX_LINE_LEN 256

// Structure to store log data
typedef struct {
    char timestamp[20];
    char client_ip[20];
    char client_agent[128];
    int request_method;
    int request_uri_len;
    char request_uri[MAX_LINE_LEN];
    char response_status;
    char response_reason;
    int response_body_len;
    char response_body[MAX_LINE_LEN];
} log_entry_t;

// Function to parse log file and extract data
void parse_log(char *log_file_path) {
    FILE *log_file = fopen(log_file_path, "r");
    if (!log_file) {
        perror("Failed to open log file");
        return;
    }

    // Skip header lines
    char line[MAX_LINE_LEN];
    int header_lines = 0;
    while (fgets(line, MAX_LINE_LEN, log_file)) {
        if (strstr(line, "Date:") || strstr(line, "Time:") || strstr(line, "Client IP:") ||
            strstr(line, "Client Agent:")) {
            header_lines++;
        } else {
            break;
        }
    }

    // Extract log data
    log_entry_t log_entry;
    char *token;
    int i = 0;
    while (fgets(line, MAX_LINE_LEN, log_file)) {
        if (i >= header_lines) {
            // Extract timestamp
            token = strtok(line, " ");
            strcpy(log_entry.timestamp, token);

            // Extract client IP
            token = strtok(NULL, " ");
            strcpy(log_entry.client_ip, token);

            // Extract client agent
            token = strtok(NULL, " ");
            strcpy(log_entry.client_agent, token);

            // Extract request method and URI
            token = strtok(NULL, " ");
            log_entry.request_method = atoi(token);
            token = strtok(NULL, " ");
            strcpy(log_entry.request_uri, token);

            // Extract response status and reason
            token = strtok(NULL, " ");
            log_entry.response_status = atoi(token);
            token = strtok(NULL, " ");
            strcpy(log_entry.response_reason, token);

            // Extract response body
            token = strtok(NULL, "\n");
            strcpy(log_entry.response_body, token);

            // Print log entry
            printf("%s %s %s %d %d %s %s\n", log_entry.timestamp, log_entry.client_ip, log_entry.client_agent,
                   log_entry.request_method, log_entry.request_uri_len, log_entry.response_status, log_entry.response_reason);
        }
        i++;
    }

    fclose(log_file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    char *log_file_path = argv[1];
    parse_log(log_file_path);

    return 0;
}