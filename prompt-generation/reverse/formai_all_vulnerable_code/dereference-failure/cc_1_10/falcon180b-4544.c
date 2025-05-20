//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000000
#define MAX_LINE_SIZE 1024

typedef struct {
    char *ip;
    int status_code;
    int bytes_sent;
} LogEntry;

char *read_log_file(FILE *fp, int *size) {
    char *buffer = malloc(MAX_LOG_SIZE);
    char *cur_pos = buffer;
    *size = 0;

    while (fgets(cur_pos, MAX_LINE_SIZE, fp)!= NULL) {
        cur_pos += strlen(cur_pos);
        *size += strlen(cur_pos);
    }

    cur_pos = realloc(buffer, *size + 1);
    cur_pos[*size] = '\0';

    return cur_pos;
}

void parse_log_entry(char *line, LogEntry *entry) {
    char *ip_start = strstr(line, " ");
    ip_start += 1;
    entry->ip = malloc(strlen(ip_start) + 1);
    strcpy(entry->ip, ip_start);

    char *status_code_start = strstr(line, " ");
    status_code_start += 1;
    entry->status_code = atoi(status_code_start);

    char *bytes_sent_start = strstr(line, " ");
    bytes_sent_start += 1;
    entry->bytes_sent = atoi(bytes_sent_start);
}

void print_log_entry(LogEntry *entry) {
    printf("IP: %s\n", entry->ip);
    printf("Status Code: %d\n", entry->status_code);
    printf("Bytes Sent: %d\n\n", entry->bytes_sent);
}

int main() {
    FILE *fp;
    char *log_buffer;
    int log_size;

    fp = fopen("access.log", "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    log_buffer = read_log_file(fp, &log_size);
    fclose(fp);

    int num_entries = log_size / MAX_LINE_SIZE;

    LogEntry *entries = malloc(num_entries * sizeof(LogEntry));

    char *cur_pos = log_buffer;
    for (int i = 0; i < num_entries; i++) {
        parse_log_entry(cur_pos, &entries[i]);
        cur_pos += MAX_LINE_SIZE;
    }

    for (int i = 0; i < num_entries; i++) {
        print_log_entry(&entries[i]);
    }

    free(log_buffer);
    free(entries);

    return 0;
}