//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct csv_reader {
    FILE *file;
    char *line;
    size_t line_len;
    char *field;
    size_t field_len;
    int field_count;
    int eof;
} csv_reader;

csv_reader *csv_reader_new(FILE *file) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    reader->file = file;
    reader->line = NULL;
    reader->line_len = 0;
    reader->field = NULL;
    reader->field_len = 0;
    reader->field_count = 0;
    reader->eof = 0;
    return reader;
}

void csv_reader_free(csv_reader *reader) {
    free(reader->line);
    free(reader->field);
    free(reader);
}

int csv_reader_next(csv_reader *reader) {
    if (reader->eof) {
        return 0;
    }

    if (getline(&reader->line, &reader->line_len, reader->file) == -1) {
        reader->eof = 1;
        return 0;
    }

    reader->field_count = 0;
    reader->field = reader->line;
    reader->field_len = 0;

    while (*reader->field != '\0') {
        if (*reader->field == ',') {
            *reader->field = '\0';
            reader->field_count++;
            reader->field = reader->field + 1;
            reader->field_len = 0;
        } else {
            reader->field_len++;
            reader->field++;
        }
    }

    reader->field_count++;

    return 1;
}

char *csv_reader_get_field(csv_reader *reader, int index) {
    char *start = reader->line;
    char *end = reader->line;

    for (int i = 0; i < index; i++) {
        while (*end != ',' && *end != '\0') {
            end++;
        }

        if (*end == ',') {
            end++;
        } else {
            break;
        }
    }

    if (index == reader->field_count - 1) {
        end = reader->line + strlen(reader->line) - 1;
    }

    return strndup(start, end - start);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    csv_reader *reader = csv_reader_new(file);

    while (csv_reader_next(reader)) {
        for (int i = 0; i < reader->field_count; i++) {
            printf("%s\t", csv_reader_get_field(reader, i));
        }
        printf("\n");
    }

    csv_reader_free(reader);
    fclose(file);

    return 0;
}