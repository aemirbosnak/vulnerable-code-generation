//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_SIZE (1024 * 1024 * 10)

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        printf("Error getting file status\n");
        return 1;
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("File %s is too large\n", filename);
        return 1;
    }

    char *buffer = malloc(MAX_LINE_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int line_count = 0;
    while (fgets(buffer, MAX_LINE_SIZE, fd)!= NULL) {
        line_count++;
    }

    printf("File %s has %d lines\n", filename, line_count);

    free(buffer);
    close(fd);

    return 0;
}