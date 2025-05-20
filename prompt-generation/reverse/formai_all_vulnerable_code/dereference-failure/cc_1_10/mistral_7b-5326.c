//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("Error getting file size");
        close(fd);
        return 1;
    }

    char *file_content = malloc(st.st_size);
    if (!file_content) {
        perror("Error allocating memory");
        close(fd);
        return 1;
    }

    ssize_t bytes_read = read(fd, file_content, st.st_size);
    if (bytes_read < 0) {
        perror("Error reading file");
        free(file_content);
        close(fd);
        return 1;
    }

    char *line_start = file_content;
    char *line_end;
    int line_number = 1;

    while ((line_end = strchr(line_start, '\n')) != NULL) {
        int number = atoi(line_start);
        number += 1;

        size_t length = line_end - line_start;
        memmove(line_start, &number, sizeof(number));
        memset(line_start + sizeof(number), '\0', length - sizeof(number));

        line_start = line_end + 1;
        line_number++;
    }

    ssize_t bytes_written = write(fd, file_content, st.st_size);
    if (bytes_written < 0) {
        perror("Error writing to file");
        free(file_content);
        close(fd);
        return 1;
    }

    free(file_content);
    close(fd);

    printf("File '%s' modified successfully.\n", argv[1]);

    return 0;
}