//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LINE_LEN 1024
#define MAX_LOG_FILE_SIZE 1048576

struct log_entry {
    char timestamp[20];
    char level[10];
    char message[1024];
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    char *log_file = argv[1];
    int fd = open(log_file, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 2;
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat");
        close(fd);
        return 3;
    }

    off_t file_size = statbuf.st_size;
    if (file_size > MAX_LOG_FILE_SIZE) {
        printf("Log file is too large (%ld bytes)\n", file_size);
        close(fd);
        return 4;
    }

    char *map = mmap(NULL, file_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 5;
    }

    off_t start = 0;
    off_t end = file_size;
    while (start < end) {
        char *line = (char *)(map + start);
        size_t len = strcspn(line, "\n");
        if (len == 0) {
            // Empty line, skip it
            start += len + 1;
            continue;
        }

        struct log_entry entry;
        memcpy(entry.timestamp, line, 20);
        line += 20;
        memcpy(entry.level, line, 10);
        line += 10;
        memcpy(entry.message, line, len - 10);

        // Print the log entry
        printf("%s [%s] %s\n", entry.timestamp, entry.level, entry.message);

        start += len + 1;
    }

    munmap(map, file_size);
    close(fd);
    return 0;
}