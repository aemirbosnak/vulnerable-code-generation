//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *data;
    size_t length;
} TextBuffer;

void append_to_buffer(TextBuffer *buffer, const char *data, size_t length) {
    if (buffer->length + length >= MAX_LINE_LENGTH) {
        buffer->length = MAX_LINE_LENGTH - 1;
        buffer->data[buffer->length] = '\0';
    } else {
        buffer->length += length;
    }

    strncat(buffer->data, data, length);
}

void print_buffer(const TextBuffer *buffer) {
    printf("%s", buffer->data);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    TextBuffer buffer = {0};

    char c;
    while ((c = fgetc(file))!= EOF) {
        if (c == '<') {
            append_to_buffer(&buffer, "&lt;", 4);
        } else if (c == '>') {
            append_to_buffer(&buffer, "&gt;", 4);
        } else if (c == '&') {
            append_to_buffer(&buffer, "&amp;", 5);
        } else {
            append_to_buffer(&buffer, &c, 1);
        }
    }

    fclose(file);

    print_buffer(&buffer);

    return 0;
}