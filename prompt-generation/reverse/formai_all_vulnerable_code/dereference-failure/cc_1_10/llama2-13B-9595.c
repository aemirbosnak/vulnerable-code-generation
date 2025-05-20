//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_LENGTH 256

struct log_entry {
    char timestamp[20];
    char client_ip[15];
    char request_method[10];
    char request_url[100];
    int response_code;
    char response_reason[100];
};

typedef struct log_entry log_entry_t;

void log_entry_print(log_entry_t *entry);
void log_file_open(const char *filename, int mode);
void log_file_close(void);
void log_parse_line(char *line, log_entry_t *entry);

int main(void) {
    char *filename = "access.log";
    char buffer[MAX_LOG_SIZE];
    log_entry_t *entries = NULL;
    int entries_count = 0;

    // Open log file
    log_file_open(filename, "r");

    // Read log entries
    while (fgets(buffer, MAX_LOG_SIZE, stdin) != NULL) {
        log_parse_line(buffer, &entries[entries_count]);
        entries_count++;
    }

    // Close log file
    log_file_close();

    // Print log entries
    for (int i = 0; i < entries_count; i++) {
        log_entry_print(&entries[i]);
    }

    return 0;
}

void log_entry_print(log_entry_t *entry) {
    printf("[%s] %s %s %d %s\n", entry->timestamp, entry->client_ip, entry->request_method, entry->response_code, entry->response_reason);
}

void log_file_open(const char *filename, int mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error opening log file");
        exit(1);
    }
}

void log_file_close(void) {
    fclose(stdin);
}

void log_parse_line(char *line, log_entry_t *entry) {
    // Parse timestamp
    strcpy(entry->timestamp, line);
    // Parse client IP
    char *ip_ptr = strtok(line, " ");
    strcpy(entry->client_ip, ip_ptr);
    // Parse request method
    ip_ptr = strtok(NULL, " ");
    strcpy(entry->request_method, ip_ptr);
    // Parse request URL
    ip_ptr = strtok(NULL, " ");
    strcpy(entry->request_url, ip_ptr);
    // Parse response code
    ip_ptr = strtok(NULL, " ");
    entry->response_code = atoi(ip_ptr);
    // Parse response reason
    ip_ptr = strtok(NULL, "\n");
    strcpy(entry->response_reason, ip_ptr);
}