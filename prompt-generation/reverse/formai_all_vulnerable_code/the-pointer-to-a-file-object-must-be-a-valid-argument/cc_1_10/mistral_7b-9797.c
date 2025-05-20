//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 4096
#define LOG_FILE "access.log"

typedef struct {
    char method[8];
    char uri[256];
    char client_ip[16];
    char status[5];
    char timestamp[21];
} log_entry;

log_entry parse_log_line(char* line) {
    log_entry entry;
    sscanf(line, "%s %s %15s %s %s", entry.method, entry.uri, entry.client_ip, entry.status, entry.timestamp);
    for (int i = 0; i < strlen(entry.method); i++) {
        entry.method[i] = toupper(entry.method[i]);
    }
    for (int i = 0; i < strlen(entry.status); i++) {
        entry.status[i] = toupper(entry.status[i]);
    }
    return entry;
}

void print_log_entry(log_entry entry) {
    printf("%s %-25s %-15s %-5s %s\n", entry.timestamp, entry.uri, entry.client_ip, entry.method, entry.status);
}

int main() {
    int log_file_fd = open(LOG_FILE, O_RDONLY);
    if (log_file_fd < 0) {
        perror("Error opening log file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    log_entry current_entry;

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("| %-21s | %-25s | %-15s | %-5s | %-20s |\n", "Timestamp", "URI", "Client IP", "Method", "Status");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    while (fgets(line, MAX_LINE_LENGTH, log_file_fd) != NULL) {
        current_entry = parse_log_line(line);
        print_log_entry(current_entry);
    }

    close(log_file_fd);

    return 0;
}