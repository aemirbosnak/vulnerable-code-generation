//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024

struct csv_reader {
    FILE *fp;
    char *line;
    size_t line_len;
    int line_num;
    int field_num;
    char **fields;
};

struct csv_reader *csv_reader_new(FILE *fp) {
    struct csv_reader *reader = malloc(sizeof(struct csv_reader));
    assert(reader != NULL);

    reader->fp = fp;
    reader->line = NULL;
    reader->line_len = 0;
    reader->line_num = 0;
    reader->field_num = 0;
    reader->fields = NULL;

    return reader;
}

void csv_reader_delete(struct csv_reader *reader) {
    if (reader->line != NULL) {
        free(reader->line);
    }

    if (reader->fields != NULL) {
        for (int i = 0; i < reader->field_num; i++) {
            free(reader->fields[i]);
        }

        free(reader->fields);
    }

    fclose(reader->fp);
    free(reader);
}

int csv_reader_next(struct csv_reader *reader) {
    // Read the next line.

    size_t len = MAX_LINE_LEN;
    char *line = malloc(len);
    assert(line != NULL);

    if (fgets(line, len, reader->fp) == NULL) {
        free(line);
        return 0;
    }

    // Parse the line into fields.

    reader->line = line;
    reader->line_len = strlen(line);
    reader->line_num++;

    int field_num = 0;
    char **fields = malloc(field_num * sizeof(char *));
    assert(fields != NULL);

    char *field_start = line;
    char *field_end = NULL;

    while ((field_end = strchr(field_start, ',')) != NULL) {
        *field_end = '\0';
        fields = realloc(fields, (field_num + 1) * sizeof(char *));
        assert(fields != NULL);
        fields[field_num] = field_start;
        field_num++;
        field_start = field_end + 1;
    }

    fields = realloc(fields, (field_num + 1) * sizeof(char *));
    assert(fields != NULL);
    fields[field_num] = field_start;
    field_num++;

    reader->field_num = field_num;
    reader->fields = fields;

    return 1;
}

char *csv_reader_get_field(struct csv_reader *reader, int field_index) {
    assert(field_index >= 0 && field_index < reader->field_num);

    return reader->fields[field_index];
}

int main(void) {
    FILE *fp = fopen("data.csv", "r");
    assert(fp != NULL);

    struct csv_reader *reader = csv_reader_new(fp);
    assert(reader != NULL);

    while (csv_reader_next(reader) != 0) {
        for (int i = 0; i < reader->field_num; i++) {
            printf("%s ", csv_reader_get_field(reader, i));
        }

        printf("\n");
    }

    csv_reader_delete(reader);
    fclose(fp);

    return 0;
}