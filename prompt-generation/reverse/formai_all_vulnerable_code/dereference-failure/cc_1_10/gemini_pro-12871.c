//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CSV_Reader {
    FILE *file;
    char *buffer;
    int buffer_size;
    int current_line;
    int current_column;
};

struct CSV_Reader *CSV_Reader_new(FILE *file) {
    struct CSV_Reader *reader = malloc(sizeof(struct CSV_Reader));
    reader->file = file;
    reader->buffer = NULL;
    reader->buffer_size = 0;
    reader->current_line = 0;
    reader->current_column = 0;
    return reader;
}

void CSV_Reader_free(struct CSV_Reader *reader) {
    if (reader->buffer != NULL) {
        free(reader->buffer);
    }
    free(reader);
}

int CSV_Reader_read(struct CSV_Reader *reader, char *buffer, int buffer_size) {
    int bytes_read = fread(buffer, 1, buffer_size, reader->file);
    reader->buffer = buffer;
    reader->buffer_size = bytes_read;
    return bytes_read;
}

int CSV_Reader_next_line(struct CSV_Reader *reader) {
    while (reader->current_line < reader->buffer_size) {
        if (reader->buffer[reader->current_line] == '\n') {
            reader->current_line++;
            return 1;
        }
        reader->current_line++;
    }
    return 0;
}

int CSV_Reader_next_column(struct CSV_Reader *reader) {
    while (reader->current_column < reader->buffer_size) {
        if (reader->buffer[reader->current_column] == ',') {
            reader->current_column++;
            return 1;
        }
        reader->current_column++;
    }
    return 0;
}

char *CSV_Reader_get_value(struct CSV_Reader *reader) {
    int start = reader->current_column;
    int end = reader->current_column;
    while (end < reader->buffer_size) {
        if (reader->buffer[end] == ',' || reader->buffer[end] == '\n') {
            break;
        }
        end++;
    }
    int length = end - start;
    char *value = malloc(length + 1);
    memcpy(value, reader->buffer + start, length);
    value[length] = '\0';
    return value;
}

int main() {
    FILE *file = fopen("test.csv", "r");
    struct CSV_Reader *reader = CSV_Reader_new(file);
    while (CSV_Reader_next_line(reader)) {
        while (CSV_Reader_next_column(reader)) {
            char *value = CSV_Reader_get_value(reader);
            printf("%s", value);
            free(value);
        }
        printf("\n");
    }
    CSV_Reader_free(reader);
    fclose(file);
    return 0;
}