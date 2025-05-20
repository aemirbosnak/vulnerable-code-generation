//Falcon-180B DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

char *read_line(FILE *stream) {
    char *line = NULL;
    size_t length = 0;
    ssize_t bytes_read;

    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Failed to allocate memory for line\n");
        exit(1);
    }

    while ((bytes_read = getline(&line, &length, stream))!= -1) {
        if (bytes_read == 0) {
            fprintf(stderr, "Empty line found\n");
            exit(1);
        }
        if (bytes_read >= MAX_LINE_LENGTH) {
            fprintf(stderr, "Line exceeds maximum length\n");
            exit(1);
        }
    }

    if (ferror(stream)) {
        fprintf(stderr, "Error reading from stream: %s\n", strerror(errno));
        exit(1);
    }

    return line;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", argv[1]);
        exit(1);
    }

    line = read_line(file);
    printf("Line read from file: %s\n", line);

    fclose(file);
    free(line);

    return 0;
}