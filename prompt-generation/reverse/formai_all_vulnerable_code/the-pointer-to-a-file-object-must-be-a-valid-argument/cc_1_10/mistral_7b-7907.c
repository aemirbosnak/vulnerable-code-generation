//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024
#define FILENAME "input.txt"

void reverse_line(char *line) {
    int i = 0, j = strlen(line) - 1;
    char temp;

    while (i < j) {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int fd;
    char line[MAX_LINE_LENGTH];
    char *lines[128];
    int lines_count = 0;

    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fd) != NULL) {
        lines[lines_count] = (char*) malloc(strlen(line) + 1);
        strcpy(lines[lines_count], line);
        reverse_line(lines[lines_count]);
        lines_count++;
    }

    close(fd);

    for (int i = 0; i < lines_count; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    free(lines);

    return EXIT_SUCCESS;
}