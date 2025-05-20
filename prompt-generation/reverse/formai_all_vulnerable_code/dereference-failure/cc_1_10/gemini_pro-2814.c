//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
    int capacity;
} line_buffer;

line_buffer *line_buffer_create() {
    line_buffer *buffer = malloc(sizeof(line_buffer));
    buffer->line = malloc(MAX_LINE_LENGTH);
    buffer->length = 0;
    buffer->capacity = MAX_LINE_LENGTH;
    return buffer;
}

void line_buffer_destroy(line_buffer *buffer) {
    free(buffer->line);
    free(buffer);
}

void line_buffer_append(line_buffer *buffer, char *string) {
    int new_length = buffer->length + strlen(string);
    if (new_length > buffer->capacity) {
        buffer->capacity *= 2;
        buffer->line = realloc(buffer->line, buffer->capacity);
    }
    strcpy(buffer->line + buffer->length, string);
    buffer->length = new_length;
}

char *line_buffer_get_line(line_buffer *buffer) {
    char *line = malloc(buffer->length + 1);
    strcpy(line, buffer->line);
    return line;
}

int main() {
    line_buffer *buffer = line_buffer_create();
    char *line;
    while ((line = line_buffer_get_line(buffer)) != NULL) {
        printf("%s", line);
        free(line);
    }
    line_buffer_destroy(buffer);
    return 0;
}