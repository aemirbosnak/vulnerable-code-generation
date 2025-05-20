//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_TOKEN_SIZE 64

struct log_entry {
    char ip_address[16];
    char request_type[16];
    char response_code[16];
};

int log_entry_count = 0;
struct log_entry log_entries[MAX_LOG_ENTRIES];

void parse_log_entry(char* log_line) {
    char* token;
    int token_count = 0;

    token = strtok(log_line, " ");
    strncpy(log_entries[log_entry_count].ip_address, token, MAX_TOKEN_SIZE);
    token_count++;

    token = strtok(NULL, " ");
    strncpy(log_entries[log_entry_count].request_type, token, MAX_TOKEN_SIZE);
    token_count++;

    token = strtok(NULL, " ");
    strncpy(log_entries[log_entry_count].response_code, token, MAX_TOKEN_SIZE);
    token_count++;

    if (token_count!= 3) {
        printf("Invalid log entry: %s\n", log_line);
        return;
    }

    log_entry_count++;
}

void print_log_entries() {
    printf("IP Address | Request Type | Response Code\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < log_entry_count; i++) {
        printf("%-16s | %-16s | %-16s\n", log_entries[i].ip_address, log_entries[i].request_type, log_entries[i].response_code);
    }
}

int main() {
    FILE* log_file = fopen("logfile.txt", "r");

    if (log_file == NULL) {
        printf("Error: Unable to open log file.\n");
        return 1;
    }

    char log_line[256];

    while (fgets(log_line, sizeof(log_line), log_file)!= NULL) {
        parse_log_entry(log_line);
    }

    fclose(log_file);

    print_log_entries();

    return 0;
}