//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main() {
    int fd_input, fd_output;
    char line[MAX_LINE_LENGTH];
    size_t len;
    char *token;

    fd_input = open(INPUT_FILE, O_RDONLY);
    if (fd_input < 0) {
        perror("Error opening input file");
        return 1;
    }

    fd_output = open(OUTPUT_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_output < 0) {
        perror("Error opening output file");
        close(fd_input);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fd_input) != NULL) {
        len = strlen(line);
        token = strchr(line, ' ');
        if (token && strcmp(token, "password") == 0) {
            continue;
        }

        if (write(fd_output, line, len) < 0) {
            perror("Error writing to output file");
            close(fd_input);
            close(fd_output);
            return 1;
        }
    }

    close(fd_input);
    close(fd_output);

    return 0;
}