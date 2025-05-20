//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LEN 1024
#define MAX_LOG_FILE_SIZE 1000000

struct log_entry {
    int time;
    char *message;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    char *log_file_path = argv[1];
    struct stat stat_info;
    if (stat(log_file_path, &stat_info) == -1) {
        perror("Stat failed");
        return 1;
    }

    if (stat_info.st_size > MAX_LOG_FILE_SIZE) {
        printf("Log file is too large (%ld MB)\n", stat_info.st_size / 1024 / 1024);
        return 1;
    }

    int fd = open(log_file_path, O_RDONLY);
    if (fd == -1) {
        perror("Open failed");
        return 1;
    }

    char *log_data = mmap(NULL, stat_info.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (log_data == MAP_FAILED) {
        perror("Mmap failed");
        close(fd);
        return 1;
    }

    struct log_entry *log_ents = (struct log_entry *)log_data;
    int num_log_ents = stat_info.st_size / sizeof(struct log_entry);

    int i;
    for (i = 0; i < num_log_ents; i++) {
        struct log_entry *cur_log_ent = log_ents + i;
        char *cur_message = cur_log_ent->message;
        if (strlen(cur_message) > 0) {
            printf("[%04d] %s\n", cur_log_ent->time, cur_message);
        }
    }

    munmap(log_data, stat_info.st_size);
    close(fd);

    return 0;
}