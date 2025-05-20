//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 4096 // Maximum length of a log line
#define MAX_IP_LENGTH 16    // Maximum length of an IP address string
#define MAX_PORT_LENGTH 6   // Maximum length of a port number string

/*
 * Define a structure to hold log data, which includes the type,
 * IP address, port, and the raw log message.
 */
typedef struct LogData {
    char type[5];
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    char message[MAX_LOG_LENGTH];
} LogData;

/*
 * Read a log line from the specified file pointer and parse the type,
 * IP address, port, and raw log message. Store these values in a LogData
 * structure and return it.
 */
LogData parse_log_line(FILE *fp) {
    LogData data;
    char line[MAX_LOG_LENGTH];
    fgets(line, MAX_LOG_LENGTH, fp);
    sscanf(line, "%s %s %s %[^\n]", data.type, data.ip, data.port, data.message);
    return data;
}

/*
 * Check if the IP address and port of the specified LogData structure
 * match an IP and port combination in the specified whitelist. If a match
 * is found, return 1. Otherwise, return 0.
 */
int is_whitelisted(LogData data, char **whitelist, int whitelist_size) {
    for (int i = 0; i < whitelist_size; i++) {
        char* ip = strtok(whitelist[i], ":");
        char* port = strtok(NULL, ":");
        if (strcmp(data.ip, ip) == 0 && strcmp(data.port, port) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <log_file> <whitelist_file>\n", argv[0]);
        exit(1);
    }

    char **whitelist = NULL; // Array of whitelisted IP:port strings
    int whitelist_size = 0;  // Size of the whitelist array

    // Read the whitelist file and store each line in the whitelist array
    FILE *whitelist_fp = fopen(argv[2], "r");
    if (whitelist_fp == NULL) {
        perror("Could not open whitelist file");
        exit(1);
    }
    char line[MAX_LOG_LENGTH];
    while (fgets(line, MAX_LOG_LENGTH, whitelist_fp)) {
        whitelist_size++;
        whitelist = realloc(whitelist, whitelist_size * sizeof(char *));
        whitelist[whitelist_size-1] = strdup(line);
    }
    fclose(whitelist_fp);

    // Read the log file and parse each line, checking if the IP:port is whitelisted
    FILE *log_fp = fopen(argv[1], "r");
    if (log_fp == NULL) {
        perror("Could not open log file");
        exit(1);
    }
    LogData data;
    while (!feof(log_fp)) {
        data = parse_log_line(log_fp);
        if (!is_whitelisted(data, whitelist, whitelist_size)) {
            printf("%s\n", data.message); // Output the raw log message if not whitelisted
        }
    }
    fclose(log_fp);

    // Free the memory allocated for the whitelist array and its strings
    for (int i = 0; i < whitelist_size; i++) {
        free(whitelist[i]);
    }
    free(whitelist);

    return 0;
}