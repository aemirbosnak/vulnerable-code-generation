//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

struct log_entry {
    char ip_address[16];
    char date_time[32];
    char request_type[16];
    char resource_path[256];
};

int main(int argc, char *argv[]) {
    FILE *log_file;
    char log_line[MAX_LINE_SIZE];
    struct log_entry log_entry;

    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    log_file = fopen(argv[1], "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while (fgets(log_line, MAX_LINE_SIZE, log_file)!= NULL) {
        int i = 0;
        char *token;

        // Extract IP address
        token = strtok(log_line, " ");
        strncpy(log_entry.ip_address, token, 16);

        // Extract date and time
        token = strtok(NULL, " ");
        strncpy(log_entry.date_time, token, 32);

        // Extract request type
        token = strtok(NULL, " ");
        strncpy(log_entry.request_type, token, 16);

        // Extract resource path
        token = strtok(NULL, " ");
        strncpy(log_entry.resource_path, token, 256);

        printf("IP Address: %s\n", log_entry.ip_address);
        printf("Date and Time: %s\n", log_entry.date_time);
        printf("Request Type: %s\n", log_entry.request_type);
        printf("Resource Path: %s\n\n", log_entry.resource_path);
    }

    fclose(log_file);

    return 0;
}