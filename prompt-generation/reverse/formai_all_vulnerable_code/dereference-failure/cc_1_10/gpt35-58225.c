//FormAI DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define LINE_SIZE 1024
#define IP_SIZE 16
#define MAX_REQUESTS 1000

/* Struct to hold log data */
typedef struct {
    char ip[IP_SIZE];
    char date[LINE_SIZE];
    char request[LINE_SIZE];
    int response_code;
} LogData;

/* Function to parse log data from a line of text */
LogData parse_log_line(char *line) {
    LogData data;
    char *token;

    // Parse IP address
    token = strtok(line, " -");
    strncpy(data.ip, token, IP_SIZE);

    // Parse date
    token = strtok(NULL, "]");
    strncpy(data.date, token, LINE_SIZE);

    // Parse request
    token = strtok(NULL, "\"");
    token = strtok(NULL, "\"");
    strncpy(data.request, token, LINE_SIZE);

    // Parse response code
    sscanf(token, "%*s %d", &data.response_code);

    return data;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("Unable to open file: %s\n", file_name);
        return 1;
    }

    LogData logs[MAX_REQUESTS];
    int num_logs = 0;

    // Parse log file
    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, file)) {
        logs[num_logs++] = parse_log_line(line);
    }
    fclose(file);

    // Find requests with response code 404
    printf("Requests with response code 404:\n");
    for (int i = 0; i < num_logs; i++) {
        if (logs[i].response_code == 404) {
            printf("%s %s %s\n", logs[i].ip, logs[i].date, logs[i].request);
        }
    }

    // Find unique IP addresses
    printf("\nUnique IP addresses:\n");
    for (int i = 0; i < num_logs; i++) {
        char *ip = logs[i].ip;
        int unique = 1;
        for (int j = 0; j < num_logs; j++) {
            if (i != j && strcmp(ip, logs[j].ip) == 0) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            printf("%s\n", ip);
        }
    }

    return 0;
}