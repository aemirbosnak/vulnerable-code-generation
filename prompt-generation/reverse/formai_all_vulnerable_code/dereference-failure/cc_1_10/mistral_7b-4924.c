//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define LOG_FILE "logs.txt"

typedef struct {
    char ip[16];
    char request[100];
    char status[10];
    char size[15];
    char time[30];
} LogEntry;

void print_log_entry(LogEntry entry) {
    printf("IP: %s\n", entry.ip);
    printf("Request: %s\n", entry.request);
    printf("Status: %s\n", entry.status);
    printf("Size: %s bytes\n", entry.size);
    printf("Time: %s\n", entry.time);
    printf("\n");
}

int parse_log_line(char *line, LogEntry *entry) {
    char *token;
    sscanf(line, "%s %s %s %s %s",
           entry->ip,
           entry->time,
           entry->request,
           entry->status,
           entry->size);

    int len = strlen(entry->ip);
    if (len > 15) {
        entry->ip[15] = '\0';
    }

    int len2 = strlen(entry->request);
    if (len2 > 99) {
        entry->request[99] = '\0';
    }

    int len3 = strlen(entry->size);
    if (len3 > 14) {
        entry->size[14] = '\0';
    }

    return 1;
}

int main() {
    int fd;
    struct stat file_stat;
    char *buffer;
    size_t buffer_size;
    LogEntry entry;

    fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    fstat(fd, &file_stat);
    buffer_size = file_stat.st_size;
    buffer = (char *) malloc(buffer_size);

    read(fd, buffer, buffer_size);
    close(fd);

    char *line = strtok(buffer, "\n");

    printf("------------------------------------\n");
    printf("| Welcome to Loggity, your funny    |\n");
    printf("| log analysis tool! Let's get this  |\n");
    printf("| party started!                |\n");
    printf("------------------------------------\n");

    while (line != NULL) {
        parse_log_line(line, &entry);
        print_log_entry(entry);

        line = strtok(NULL, "\n");
    }

    free(buffer);

    printf("------------------------------------\n");
    printf("| That's all, folks! Your log analysis|\n");
    printf("| is now complete. Come back soon!    |\n");
    printf("------------------------------------\n");

    return 0;
}