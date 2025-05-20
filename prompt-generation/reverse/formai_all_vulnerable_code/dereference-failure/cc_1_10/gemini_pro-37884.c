//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_LINE_LEN 1024

struct csv_reader {
    FILE *fp;
    char *line;
    size_t line_len;
    char *fields[MAX_FIELDS];
    int num_fields;
};

struct csv_reader *csv_reader_init(FILE *fp)
{
    struct csv_reader *reader = malloc(sizeof(struct csv_reader));
    if (!reader) {
        return NULL;
    }

    reader->fp = fp;
    reader->line = NULL;
    reader->line_len = 0;
    reader->num_fields = 0;

    return reader;
}

void csv_reader_free(struct csv_reader *reader)
{
    if (!reader) {
        return;
    }

    if (reader->line) {
        free(reader->line);
    }

    free(reader);
}

int csv_reader_next_line(struct csv_reader *reader)
{
    ssize_t len;
    char *line;

    if (!reader->fp) {
        return 0;
    }

    len = getline(&line, &reader->line_len, reader->fp);
    if (len < 0) {
        return 0;
    }

    reader->line = line;
    reader->num_fields = 0;

    return 1;
}

char *csv_reader_get_field(struct csv_reader *reader, int index)
{
    char *start, *end;

    if (index < 0 || index >= reader->num_fields) {
        return NULL;
    }

    start = reader->line;
    while (index > 0) {
        start = strchr(start, ',') + 1;
        if (!start) {
            return NULL;
        }
        index--;
    }

    end = strchr(start, ',');
    if (!end) {
        end = reader->line + strlen(reader->line);
    }

    reader->fields[index] = strndup(start, end - start);
    reader->num_fields++;

    return reader->fields[index];
}

int main(int argc, char **argv)
{
    struct csv_reader *reader;
    char *field;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    reader = csv_reader_init(fp);
    if (!reader) {
        fprintf(stderr, "csv_reader_init failed\n");
        return 1;
    }

    while (csv_reader_next_line(reader)) {
        for (i = 0; i < reader->num_fields; i++) {
            field = csv_reader_get_field(reader, i);
            if (!field) {
                fprintf(stderr, "csv_reader_get_field failed\n");
                return 1;
            }

            printf("%s\t", field);
        }

        printf("\n");
    }

    csv_reader_free(reader);
    fclose(fp);

    return 0;
}