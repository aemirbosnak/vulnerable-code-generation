//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 1024
#define LOG_FILE "logs.txt"

struct log_entry {
    time_t timestamp;
    char ip[32];
    char method[8];
    char path[128];
    int status_code;
};

void parse_log_line(const char *line, struct log_entry *entry) {
    sscanf(line, "%ld %[^ ] %s %s %d", &entry->timestamp, entry->ip, entry->method, &entry->status_code);
    strncpy(entry->path, strchr(line, ' ') + 1, sizeof(entry->path));
    entry->path[sizeof(entry->path) - 1] = '\0';
}

int main() {
    int fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    struct log_entry entry;
    char line[MAX_LINE_LENGTH];
    int total_entries = 0;

    while (fgets(line, sizeof(line), fd) != NULL) {
        parse_log_line(line, &entry);

        if (strcasecmp(entry.method, "GET") != 0) {
            continue;
        }

        if (strstr(entry.path, "/api/v1/user") != NULL) {
            printf("User accessed API at %s\n", ctime(&entry.timestamp));
            printf("IP address: %s\n", entry.ip);
            total_entries++;
        }
    }

    close(fd);

    printf("Total number of GET requests to /api/v1/user: %d\n", total_entries);

    return EXIT_SUCCESS;
}