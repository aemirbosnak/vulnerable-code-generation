//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef enum {
    STATE_OUTSIDE_TAG,
    STATE_INSIDE_TAG,
    STATE_INSIDE_TAG_ATTRIBUTE,
    STATE_INSIDE_TAG_ATTRIBUTE_VALUE
} State;

typedef struct {
    char *buffer;
    int length;
    int capacity;
} Buffer;

void buffer_init(Buffer *buffer) {
    buffer->buffer = NULL;
    buffer->length = 0;
    buffer->capacity = 0;
}

void buffer_free(Buffer *buffer) {
    if (buffer->buffer != NULL) {
        free(buffer->buffer);
        buffer->buffer = NULL;
    }
    buffer->length = 0;
    buffer->capacity = 0;
}

int buffer_append(Buffer *buffer, const char *string, int length) {
    if (buffer->length + length > buffer->capacity) {
        int new_capacity = buffer->capacity * 2;
        if (new_capacity < buffer->length + length) {
            new_capacity = buffer->length + length;
        }
        char *new_buffer = realloc(buffer->buffer, new_capacity);
        if (new_buffer == NULL) {
            return -1;
        }
        buffer->buffer = new_buffer;
        buffer->capacity = new_capacity;
    }
    memcpy(buffer->buffer + buffer->length, string, length);
    buffer->length += length;
    return 0;
}

int html_beautify(const char *input, char **output) {
    Buffer buffer;
    buffer_init(&buffer);

    State state = STATE_OUTSIDE_TAG;
    int indent_level = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        char c = input[i];

        switch (state) {
        case STATE_OUTSIDE_TAG:
            if (c == '<') {
                state = STATE_INSIDE_TAG;
            } else {
                buffer_append(&buffer, &c, 1);
            }
            break;
        case STATE_INSIDE_TAG:
            if (c == '>') {
                buffer_append(&buffer, "\n", 1);
                for (int j = 0; j < indent_level; ++j) {
                    buffer_append(&buffer, "  ", 2);
                }
                state = STATE_OUTSIDE_TAG;
            } else if (c == '/') {
                state = STATE_INSIDE_TAG;
            } else if (c == ' ') {
                state = STATE_INSIDE_TAG_ATTRIBUTE;
            } else {
                buffer_append(&buffer, &c, 1);
                state = STATE_INSIDE_TAG_ATTRIBUTE;
            }
            break;
        case STATE_INSIDE_TAG_ATTRIBUTE:
            if (c == ' ') {
                state = STATE_INSIDE_TAG_ATTRIBUTE;
            } else if (c == '=') {
                state = STATE_INSIDE_TAG_ATTRIBUTE_VALUE;
            } else {
                buffer_append(&buffer, &c, 1);
                state = STATE_INSIDE_TAG_ATTRIBUTE;
            }
            break;
        case STATE_INSIDE_TAG_ATTRIBUTE_VALUE:
            if (c == '"') {
                state = STATE_INSIDE_TAG_ATTRIBUTE;
            } else {
                buffer_append(&buffer, &c, 1);
                state = STATE_INSIDE_TAG_ATTRIBUTE_VALUE;
            }
            break;
        }

        if (c == '\n') {
            indent_level++;
        }
    }

    *output = buffer.buffer;
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *input = NULL;
    int input_length = 0;

    while (!feof(input_file)) {
        char buffer[MAX_LINE_LENGTH];
        int length = fread(buffer, 1, MAX_LINE_LENGTH, input_file);
        if (length <= 0) {
            break;
        }
        input_length += length;
        input = realloc(input, input_length);
        memcpy(input + input_length - length, buffer, length);
    }

    fclose(input_file);

    char *output = NULL;
    html_beautify(input, &output);

    printf("%s", output);

    free(input);
    free(output);

    return EXIT_SUCCESS;
}