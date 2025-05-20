//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DIARY_FILE "/.diary/.secret"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void append_entry(const char *entry) {
    int fd;
    off_t file_size;

    fd = open(DIARY_FILE, O_WRONLY | O_APPEND);
    if (fd == -1) error("Failed to open diary file for writing.");

    file_size = lseek(fd, 0, SEEK_END);
    if (write(fd, entry, strlen(entry)) == -1) error("Failed to write to diary file.");

    lseek(fd, file_size + strlen(entry), SEEK_SET);
    if (write(fd, "\n", 1) == -1) error("Failed to write newline character to diary file.");

    close(fd);
}

void print_entries() {
    int fd;
    char buffer[1024];
    off_t file_size;
    ssize_t bytes_read;

    fd = open(DIARY_FILE, O_RDONLY);
    if (fd == -1) error("Failed to open diary file for reading.");

    file_size = lseek(fd, 0, SEEK_END);
    if (lseek(fd, file_size - 1, SEEK_SET) == -1) error("Failed to set file pointer to last character.");

    while (read(fd, buffer, sizeof(buffer) - 1) > 0) {
        printf("%s", buffer);
        bytes_read = read(fd, buffer, sizeof(buffer) - 1);
        if (bytes_read < sizeof(buffer) - 1) break;
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: diary <entry>\n");
        return 1;
    }

    append_entry(argv[1]);
    print_entries();

    return 0;
}

/* This program is invasive by design. It creates a hidden file called ".diary/.secret" in the root directory and writes all entries to it without any form of encryption or access control. */