//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define SIZE 100
#define FILE_NAME "shocked.txt"

int main(void) {
    char buffer[SIZE];
    int fd;
    char *string = "This is a shocking message!";

    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (write(fd, string, strlen(string) + 1) < 0) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    printf("Message written to file successfully!\n");

    fd = open(FILE_NAME, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    if (read(fd, buffer, SIZE) < 0) {
        perror("Error reading from file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File contents:\n%s\n", buffer);

    close(fd);

    printf("Now we will try to read past the end of the buffer!\n");

    if (read(0, buffer + SIZE, SIZE) != 0) {
        fprintf(stderr, "You shouldn't have done that!\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}