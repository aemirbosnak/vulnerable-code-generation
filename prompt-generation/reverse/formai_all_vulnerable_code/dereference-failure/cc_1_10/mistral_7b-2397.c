//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define FILE_MODE 0644

int main(int argc, char *argv[]) {
    int fd;
    char input[MAX_INPUT_SIZE];
    char *filename;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];

    fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        exit(2);
    }

    if (read(fd, input, MAX_INPUT_SIZE) < 0) {
        perror("Error reading file");
        close(fd);
        exit(3);
    }

    close(fd);

    if (strlen(input) > MAX_INPUT_SIZE) {
        fprintf(stderr, "Input too large\n");
        exit(4);
    }

    printf("File contents:\n%s\n", input);

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);

    if (fd < 0) {
        perror("Error creating output file");
        exit(5);
    }

    if (write(fd, input, strlen(input)) < 0) {
        perror("Error writing to output file");
        close(fd);
        exit(6);
    }

    close(fd);

    printf("File contents written to output.txt\n");

    return 0;
}