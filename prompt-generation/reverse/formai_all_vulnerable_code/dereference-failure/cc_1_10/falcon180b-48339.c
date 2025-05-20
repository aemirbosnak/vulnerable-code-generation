//Falcon-180B DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

char *read_line(int fd) {
    char *buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
    char *line = NULL;
    int count = 0;
    int i = 0;

    while ((count = read(fd, &buffer[i], MAX_LINE_LENGTH - i - 1)) > 0) {
        buffer[i + count] = '\0';
        i += count;
        if (i >= MAX_LINE_LENGTH - 1) {
            break;
        }
    }

    if (count < 0) {
        printf("Error reading line: %s\n", strerror(errno));
        exit(1);
    }

    line = buffer;
    return line;
}

void write_line(int fd, const char *line) {
    int count = strlen(line);
    write(fd, line, count);
    write(fd, "\n", 1);
}

int main() {
    int fd;
    char *filename = "example.txt";
    char *mode = "w";

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    printf("Enter lines of text (end with an empty line):\n");
    char *line = read_line(0);
    while (line!= NULL) {
        write_line(fd, line);
        line = read_line(0);
    }

    close(fd);
    printf("File written successfully.\n");

    return 0;
}