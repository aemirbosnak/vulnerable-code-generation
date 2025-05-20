//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 128
#define WORD_DELIMITER " \t\r\n\f,\";:!?(){}[]<>"

typedef struct {
    char *buffer;
    size_t size;
    size_t position;
} LineBuffer;

LineBuffer line_buffer;
bool is_delimiter(char c) {
    size_t index;
    for (index = 0; WORD_DELIMITER[index]; ++index) {
        if (c == WORD_DELIMITER[index]) {
            return true;
        }
    }
    return false;
}

size_t read_line(FILE *file, LineBuffer *buffer) {
    size_t buffer_size = BUFFER_SIZE;
    size_t bytes_read = 0;

    buffer->position = 0;
    buffer->size = buffer_size;
    buffer->buffer = malloc(buffer_size);

    while (!feof(file) && buffer->position < buffer_size) {
        char c = fgetc(file);

        if (c == '\n' || c == EOF) {
            if (c == '\n') {
                buffer->buffer[buffer->position] = '\0';
                ++bytes_read;
            }
            break;
        }

        buffer->buffer[buffer->position++] = c;
    }

    if (bytes_read > 0) {
        return bytes_read;
    }

    free(buffer->buffer);
    return 0;
}

size_t count_words(const char *line) {
    size_t word_count = 0;
    size_t position = 0;

    while (*line != '\0') {
        while (is_delimiter(*line)) {
            ++line;
        }

        if (*line != '\0') {
            ++word_count;
            do {
                ++line;
            } while (!is_delimiter(*line));
        }
    }

    return word_count;
}

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    input_file = fopen(argv[1], "r");
    output_file = fopen(argv[2], "w");

    if (!input_file || !output_file) {
        perror("Error opening file");
        if (input_file) {
            fclose(input_file);
        }
        if (output_file) {
            fclose(output_file);
        }
        return EXIT_FAILURE;
    }

    while (read_line(input_file, &line_buffer)) {
        size_t word_count = count_words(line_buffer.buffer);
        fprintf(output_file, "%s %lu\n", line_buffer.buffer, word_count);
    }

    fclose(input_file);
    fclose(output_file);

    free(line_buffer.buffer);

    return EXIT_SUCCESS;
}