//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>

#define FILE_NAME "example.txt"
#define BUFFER_SIZE 100

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(void) {
    int fd;
    char buffer[BUFFER_SIZE];
    size_t n;

    fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0) die("open failed");

    n = read(fd, buffer, BUFFER_SIZE);
    if (n < 0) {
        close(fd);
        die("read failed");
    }

    printf("Read %ld bytes:\n", n);
    fputs(buffer, stdout);

    close(fd);

    fd = open("non_existent_file.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) die("open failed");

    write(fd, "Hello, World!\n", strlen("Hello, World!\n") + 1);

    printf("Wrote to file successfully.\n");
    close(fd);

    mkdir("new_directory", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (errno != EEXIST) die("mkdir failed");

    fd = open("new_directory/file.txt", O_RDONLY);
    if (fd < 0) die("open failed");

    n = read(fd, buffer, BUFFER_SIZE);
    if (n < 0) {
        close(fd);
        die("read failed");
    }

    printf("Read from newly created file:\n");
    fputs(buffer, stdout);

    close(fd);
    rmdir("new_directory");
    if (errno != ENOTEMPTY) die("rmdir failed");

    printf("Successfully deleted directory.\n");

    return 0;
}