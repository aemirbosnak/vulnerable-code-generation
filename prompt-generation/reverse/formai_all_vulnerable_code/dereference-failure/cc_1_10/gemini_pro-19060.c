//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *line;
    int length;
} LineBuffer;

void read_line(LineBuffer *buffer, FILE *stream) {
    buffer->line = malloc(BUFFER_SIZE);
    buffer->length = 0;

    while (1) {
        char c = fgetc(stream);

        if (c == EOF || c == '\n') {
            break;
        }

        buffer->line[buffer->length++] = c;
    }

    buffer->line[buffer->length] = '\0';
}

void free_line(LineBuffer *buffer) {
    free(buffer->line);
}

int main() {
    FILE *stream = fopen("input.csv", "r");

    if (stream == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    LineBuffer buffer;

    while (1) {
        read_line(&buffer, stream);

        if (buffer.length == 0) {
            break;
        }

        char *token = strtok(buffer.line, ",");

        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }

        free_line(&buffer);
    }

    fclose(stream);

    return EXIT_SUCCESS;
}