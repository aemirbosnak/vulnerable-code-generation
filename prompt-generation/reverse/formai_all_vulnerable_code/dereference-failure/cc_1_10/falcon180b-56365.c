//Falcon-180B DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#define MAX_PATH 4096
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    char *path = argv[1];
    int fd;
    char line[MAX_LINE];
    char *token;
    char *delim = " \t\r\n\a";
    int count = 0;

    // Check if path is valid
    if (strlen(path) == 0 || strlen(path) >= MAX_PATH) {
        fprintf(stderr, "Invalid path\n");
        return 1;
    }

    // Open the file
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE, fd)!= NULL) {
        // Count the number of words in the line
        token = strtok(line, delim);
        while (token!= NULL) {
            count++;
            token = strtok(NULL, delim);
        }
    }

    // Close the file
    close(fd);

    // Print the total number of words
    printf("Total number of words: %d\n", count);

    return 0;
}