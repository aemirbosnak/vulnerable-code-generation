//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define LOG_FILE "server.log"
#define BUF_SIZE 4096
#define LINE_SIZE 256
#define SEPARATOR " - "

struct log_entry {
    time_t timestamp;
    int status_code;
    char request[LINE_SIZE];
    char user_agent[LINE_SIZE];
};

void parse_log_line(char *line, struct log_entry *entry) {
    char *token;
    sscanf(line, "%*s %ld %*s %ld %s %s", &entry->timestamp, &entry->status_code, entry->request, entry->user_agent);
}

int main(void) {
    int fd, lines = 0;
    struct stat st;
    struct log_entry entry;
    char *line, *buf;

    if ((fd = open(LOG_FILE, O_RDONLY)) < 0) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &st) < 0) {
        perror("Could not get file statistics");
        exit(EXIT_FAILURE);
    }

    buf = malloc(st.st_size);
    if (!buf) {
        perror("Could not allocate memory for buffer");
        exit(EXIT_FAILURE);
    }

    if (read(fd, buf, st.st_size) < 0) {
        perror("Could not read file into buffer");
        exit(EXIT_FAILURE);
    }

    line = buf;
    while (line && lines < 10) {
        parse_log_line(line, &entry);
        printf("%ld: %d %s %s\n", entry.timestamp, entry.status_code, entry.request, entry.user_agent);
        lines++;
        line = strpbrk(line, "\n");
        if (line) line += strlen(SEPARATOR) + 1;
    }

    free(buf);
    close(fd);
    return EXIT_SUCCESS;
}