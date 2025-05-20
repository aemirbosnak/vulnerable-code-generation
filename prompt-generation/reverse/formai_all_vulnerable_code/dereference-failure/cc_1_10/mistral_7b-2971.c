//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    char *filename = "nonexistentfile.txt";
    char buffer[MAX_BUFFER_SIZE];
    int fd;
    ssize_t nread;

    printf("*** Welcome to the Shocking Error Handling Program! ***\n");
    printf("*                                                *\n");
    printf("* This program demonstrates a unique approach to   *\n");
    printf("* error handling using unexpected print statements.*\n");
    printf("*                                                *\n");
    printf("*                                                *\n");

    fd = open(filename, O_RDONLY);

    if (fd == -1) {
        printf("*** OH NO! File opening failed! ***\n");
        printf("* Error message: %s\n", strerror(errno));
        printf("* Please check the filename and try again.\n");
        printf("*                                                *\n");
        printf("*                                                *\n");
        die("open");
    }

    printf("*** File opened successfully! ***\n");
    printf("* Reading file content now...\n");
    printf("*                                                *\n");
    printf("*                                                *\n");

    nread = read(fd, buffer, MAX_BUFFER_SIZE);

    if (nread == -1) {
        printf("*** OH DEAR! Reading failed! ***\n");
        printf("* Error message: %s\n", strerror(errno));
        printf("* Please check the file and try again.\n");
        printf("*                                                *\n");
        printf("*                                                *\n");
        close(fd);
        die("read");
    }

    printf("*** File content read successfully! ***\n");
    printf("* Content: %s\n", buffer);
    printf("*                                                *\n");
    printf("*                                                *\n");

    close(fd);
    printf("*** File closed successfully! ***\n");
    printf("* Program execution ended normally.\n");
    printf("*                                                *\n");
    printf("*                                                *\n");

    return EXIT_SUCCESS;
}