//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100
#define BUFFER_SIZE 4096

void print_line(char *line) {
    int i;
    for (i = 0; i < strlen(line); i++) {
        putchar(isalnum(line[i]) ? line[i] : ' ');
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    int file_fd;
    char file_path[MAX_LINE_LENGTH];
    char buffer[BUFFER_SIZE];
    char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
    char *token;

    if (argc != 2) {
        printf("Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    strcpy(file_path, argv[1]);

    file_fd = open(file_path, O_RDONLY);
    if (file_fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while (read(file_fd, buffer, BUFFER_SIZE) > 0) {
        char *line_start = buffer;
        char *line_end = line_start;

        while ((line_end = strchr(line_start, '\n')) != NULL) {
            size_t line_length = line_end - line_start;
            memmove(line, line_start, line_length);
            line[line_length] = '\0';
            print_line(line);
            line_start = line_end + 1;
        }
    }

    if (line) free(line);
    close(file_fd);

    return 0;
}