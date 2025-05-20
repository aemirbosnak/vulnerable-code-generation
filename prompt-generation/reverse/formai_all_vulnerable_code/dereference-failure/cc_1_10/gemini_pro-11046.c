//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct csv_reader {
    FILE *file;
    char *line;
    size_t line_size;
    char *delim;
    size_t delim_size;
    int line_number;
} csv_reader;

csv_reader *csv_reader_init(FILE *file, char *delim) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    reader->file = file;
    reader->line = NULL;
    reader->line_size = 0;
    reader->delim = delim;
    reader->delim_size = strlen(delim);
    reader->line_number = 0;
    return reader;
}

void csv_reader_free(csv_reader *reader) {
    if (reader->line) {
        free(reader->line);
    }
    free(reader);
}

int csv_reader_next(csv_reader *reader, char ***fields, size_t *field_count) {
    if (reader->line) {
        free(reader->line);
    }

    size_t line_size = 0;
    ssize_t line_length = getline(&reader->line, &line_size, reader->file);
    if (line_length == -1) {
        return 0;
    }

    reader->line_number += 1;

    // Split the line into fields.
    *fields = malloc(sizeof(char *) * line_size);
    *field_count = 0;
    char *field = strtok(reader->line, reader->delim);
    while (field) {
        (*fields)[*field_count] = field;
        *field_count += 1;
        field = strtok(NULL, reader->delim);
    }

    return 1;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (!file) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    csv_reader *reader = csv_reader_init(file, ",");

    char **fields;
    size_t field_count;
    while (csv_reader_next(reader, &fields, &field_count)) {
        printf("Line %d: ", reader->line_number);
        for (size_t i = 0; i < field_count; i++) {
            printf("%s%s", fields[i], i < field_count - 1 ? ", " : "\n");
        }
    }

    csv_reader_free(reader);
    fclose(file);

    return EXIT_SUCCESS;
}