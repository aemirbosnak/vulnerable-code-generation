//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FILE_NAME 256

void read_file(const char *filename, char **lines) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    size_t buffer_len = 0;

    while (read(fd, buffer, MAX_BUFFER_SIZE) > 0) {
        buffer_len = strlen(buffer);
        buffer[buffer_len] = '\0';
        *lines = realloc(*lines, (buffer_len + 1) * sizeof(char));
        strcat(*lines, buffer);
    }

    close(fd);
}

void write_file(const char *filename, char *lines) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }

    char *p = lines;
    while (*p != '\0') {
        write(fd, p, strlen(p));
        p += strlen(p) + 1;
    }

    close(fd);
}

int main() {
    char *lines = NULL;

    // Example usage: read a file and print its contents
    read_file("example.txt", &lines);
    printf("%s\n", lines);

    // Example usage: write a file with some contents
    char buffer[] = "This is a test file";
    write_file("new_file.txt", buffer);

    return 0;
}