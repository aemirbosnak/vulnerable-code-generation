//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct csv_reader {
    FILE *fp;
    char *line;
    size_t line_size;
    size_t line_len;
    char *field;
    size_t field_size;
    size_t field_len;
    int field_count;
    int eof;
} csv_reader;

csv_reader *csv_reader_new(FILE *fp) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    if (!reader) {
        return NULL;
    }

    reader->fp = fp;
    reader->line = NULL;
    reader->line_size = 0;
    reader->line_len = 0;
    reader->field = NULL;
    reader->field_size = 0;
    reader->field_len = 0;
    reader->field_count = 0;
    reader->eof = 0;

    return reader;
}

void csv_reader_free(csv_reader *reader) {
    if (!reader) {
        return;
    }

    if (reader->line) {
        free(reader->line);
    }

    if (reader->field) {
        free(reader->field);
    }

    free(reader);
}

int csv_reader_next(csv_reader *reader) {
    if (reader->eof) {
        return 0;
    }

    if (reader->line_len == 0) {
        if (getline(&reader->line, &reader->line_size, reader->fp) == -1) {
            reader->eof = 1;
            return 0;
        }

        reader->line_len = strlen(reader->line);
    }

    reader->field_len = 0;
    reader->field_count = 0;

    for (int i = 0; i < reader->line_len; i++) {
        if (reader->line[i] == ',') {
            if (reader->field_len > 0) {
                reader->field[reader->field_len] = '\0';
                reader->field_count++;
            }

            reader->field_len = 0;
        } else {
            if (reader->field_len >= reader->field_size) {
                reader->field_size *= 2;
                reader->field = realloc(reader->field, reader->field_size);
            }

            reader->field[reader->field_len++] = reader->line[i];
        }
    }

    if (reader->field_len > 0) {
        reader->field[reader->field_len] = '\0';
        reader->field_count++;
    }

    reader->line_len = 0;

    return 1;
}

const char *csv_reader_get_field(csv_reader *reader, int index) {
    if (index < 0 || index >= reader->field_count) {
        return NULL;
    }

    return reader->field + index;
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    csv_reader *reader = csv_reader_new(fp);
    if (!reader) {
        perror("csv_reader_new");
        fclose(fp);
        return EXIT_FAILURE;
    }

    while (csv_reader_next(reader)) {
        for (int i = 0; i < reader->field_count; i++) {
            printf("%s ", csv_reader_get_field(reader, i));
        }

        printf("\n");
    }

    csv_reader_free(reader);
    fclose(fp);

    return EXIT_SUCCESS;
}