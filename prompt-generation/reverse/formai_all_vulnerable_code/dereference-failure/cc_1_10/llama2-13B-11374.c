//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10
#define MAX_BUFFER_SIZE 1024 * 1024

void read_file(const char* filename, char** buffer) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    struct stat file_stat;
    fstat(fd, &file_stat);
    long file_size = file_stat.st_size;

    *buffer = (char*) malloc(file_size + 1);
    if (*buffer == NULL) {
        perror("Memory allocation failed");
        close(fd);
        return;
    }

    ssize_t bytes_read = read(fd, *buffer, file_size);
    if (bytes_read < 0) {
        perror("Error reading file");
        free(*buffer);
        close(fd);
        return;
    }

    *buffer[file_size] = '\0';

    close(fd);
}

void write_file(const char* filename, const char* buffer) {
    int fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    size_t buffer_size = strlen(buffer);
    ssize_t bytes_written = write(fd, buffer, buffer_size);
    if (bytes_written < 0) {
        perror("Error writing file");
        close(fd);
        return;
    }

    close(fd);
}

int main() {
    char* buffer = NULL;
    read_file("example.txt", &buffer);
    printf("Buffer contents: %s\n", buffer);

    char* new_buffer = "New contents";
    write_file("example.txt", new_buffer);

    char* contents = NULL;
    read_file("example.txt", &contents);
    printf("New contents: %s\n", contents);

    free(buffer);
    free(new_buffer);
    free(contents);

    return 0;
}