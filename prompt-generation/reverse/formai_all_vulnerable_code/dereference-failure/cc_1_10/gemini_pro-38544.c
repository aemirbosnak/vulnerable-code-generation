//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int capacity;
} TextBuffer;

TextBuffer *create_text_buffer(int initial_capacity) {
    TextBuffer *buffer = malloc(sizeof(TextBuffer));
    buffer->lines = malloc(sizeof(Line) * initial_capacity);
    buffer->num_lines = 0;
    buffer->capacity = initial_capacity;
    return buffer;
}

void destroy_text_buffer(TextBuffer *buffer) {
    for (int i = 0; i < buffer->num_lines; i++) {
        free(buffer->lines[i].line);
    }
    free(buffer->lines);
    free(buffer);
}

void add_line_to_text_buffer(TextBuffer *buffer, char *line) {
    if (buffer->num_lines == buffer->capacity) {
        // Reallocate the lines array to double the capacity.
        buffer->lines = realloc(buffer->lines, sizeof(Line) * buffer->capacity * 2);
        buffer->capacity *= 2;
    }
    buffer->lines[buffer->num_lines].line = strdup(line);
    buffer->lines[buffer->num_lines].length = strlen(line);
    buffer->num_lines++;
}

void print_text_buffer(TextBuffer *buffer) {
    for (int i = 0; i < buffer->num_lines; i++) {
        printf("%s", buffer->lines[i].line);
    }
}

int main() {
    TextBuffer *buffer = create_text_buffer(10);
    add_line_to_text_buffer(buffer, "This is line 1.");
    add_line_to_text_buffer(buffer, "This is line 2.");
    add_line_to_text_buffer(buffer, "This is line 3.");
    print_text_buffer(buffer);
    destroy_text_buffer(buffer);
    return 0;
}