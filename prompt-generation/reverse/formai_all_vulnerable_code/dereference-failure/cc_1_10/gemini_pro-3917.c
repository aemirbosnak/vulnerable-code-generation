//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} Buffer;

void buffer_init(Buffer *buffer, size_t capacity) {
    buffer->data = malloc(capacity);
    buffer->size = 0;
    buffer->capacity = capacity;
}

void buffer_free(Buffer *buffer) {
    free(buffer->data);
}

void buffer_append(Buffer *buffer, const char *data, size_t size) {
    if (buffer->size + size > buffer->capacity) {
        buffer->capacity *= 2;
        buffer->data = realloc(buffer->data, buffer->capacity);
    }
    memcpy(buffer->data + buffer->size, data, size);
    buffer->size += size;
}

void buffer_clear(Buffer *buffer) {
    buffer->size = 0;
}

typedef struct {
    FILE *file;
    Buffer buffer;
} CSVReader;

void csv_reader_init(CSVReader *reader, const char *filename) {
    reader->file = fopen(filename, "r");
    buffer_init(&reader->buffer, 1024);
}

void csv_reader_free(CSVReader *reader) {
    fclose(reader->file);
    buffer_free(&reader->buffer);
}

int csv_reader_next_row(CSVReader *reader, Buffer *row) {
    buffer_clear(row);
    int c;
    while ((c = fgetc(reader->file)) != EOF) {
        if (c == '\n') {
            return 1;
        } else if (c == ',') {
            return 0;
        } else {
            buffer_append(row, &c, 1);
        }
    }
    return -1;
}

int main() {
    CSVReader reader;
    csv_reader_init(&reader, "data.csv");
    Buffer row;
    buffer_init(&row, 1024);
    while (csv_reader_next_row(&reader, &row)) {
        printf("%s\n", row.data);
    }
    buffer_free(&row);
    csv_reader_free(&reader);
    return 0;
}