//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 50
#define MAX_LINE_SIZE 1024

struct csv_record {
    char **fields;
    size_t num_fields;
};

struct csv_reader {
    char *filename;
    FILE *file;
    char *line;
    size_t line_size;
};

void init_csv_reader(struct csv_reader *reader, const char *filename) {
    reader->filename = (char *) malloc(strlen(filename) + 1);
    strcpy(reader->filename, filename);

    reader->file = fopen(filename, "r");
    if (!reader->file) {
        fprintf(stderr, "Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    reader->line = (char *) malloc(MAX_LINE_SIZE);
    reader->line_size = MAX_LINE_SIZE;
}

void destroy_csv_reader(struct csv_reader *reader) {
    fclose(reader->file);
    free(reader->filename);
    free(reader->line);
}

void resize_csv_record(struct csv_record *record) {
    record->fields = (char **) realloc(record->fields, (record->num_fields + 1) * sizeof(char *));
}

void parse_csv_record(struct csv_record *record, char *line) {
    char *field;
    size_t len;

    while ((field = strsep(&line, ","))) {
        len = strlen(field);
        if (len > 0 && field[len - 1] == '\n') {
            field[len - 1] = '\0';
        }
        record->fields[record->num_fields++] = field;
        resize_csv_record(record);
    }
}

struct csv_record *read_csv_record(struct csv_reader *reader) {
    if (fgets(reader->line, reader->line_size, reader->file)) {
        struct csv_record *record = (struct csv_record *) malloc(sizeof(struct csv_record));
        record->fields = (char **) malloc(sizeof(char *));
        record->fields[0] = NULL;
        record->num_fields = 0;
        parse_csv_record(record, reader->line);
        return record;
    } else {
        return NULL;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename.csv\n", argv[0]);
        exit(1);
    }

    struct csv_reader reader;
    struct csv_record *record;

    init_csv_reader(&reader, argv[1]);

    while ((record = read_csv_record(&reader))) {
        for (size_t i = 0; i < record->num_fields; i++) {
            printf("%s\n", record->fields[i]);
        }
        free(record->fields);
        free(record);
    }

    destroy_csv_reader(&reader);

    return 0;
}