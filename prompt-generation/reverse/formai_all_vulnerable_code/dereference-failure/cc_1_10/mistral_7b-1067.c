//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct LogEntry {
    char timestamp[20];
    char thread_name[20];
    char function_name[50];
    char level[10];
    char message[256];
} LogEntry;

void parse_log_entry(char* line, LogEntry* entry) {
    sscanf(line, "%s %s %s %s %s",
           entry->timestamp, entry->thread_name, entry->function_name, entry->level, entry->message);
}

int main(int argc, char** argv) {
    int fd;
    char filename[50];
    char line[1024];
    LogEntry log_entry;

    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    while (read(fd, line, sizeof(line)) > 0) {
        parse_log_entry(line, &log_entry);

        printf("Once upon a time, in a forest of code,\n");
        printf("A thread named %s was born,\n", log_entry.thread_name);
        printf("With a function named %s in its heart,\n", log_entry.function_name);
        printf("It leveled up to %s,\n", log_entry.level);
        printf("And then, it whispered:\n");
        printf("%s\n", log_entry.message);
        printf("\n");
    }

    close(fd);
    return 0;
}