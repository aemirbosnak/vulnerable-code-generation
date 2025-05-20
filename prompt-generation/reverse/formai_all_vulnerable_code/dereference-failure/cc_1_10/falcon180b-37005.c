//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct field {
    char *name;
    char *value;
} field_t;

typedef struct row {
    int num_fields;
    field_t fields[MAX_FIELDS];
} row_t;

typedef struct csv_reader {
    FILE *file;
    int line_num;
    char line[MAX_LINE_LENGTH];
    int field_num;
    row_t row;
} csv_reader_t;

csv_reader_t *csv_reader_create(const char *filename) {
    csv_reader_t *reader = (csv_reader_t *) malloc(sizeof(csv_reader_t));
    reader->file = fopen(filename, "r");
    reader->line_num = 0;
    reader->field_num = 0;
    return reader;
}

void csv_reader_destroy(csv_reader_t *reader) {
    fclose(reader->file);
    free(reader);
}

int csv_reader_next_row(csv_reader_t *reader) {
    int ret = 0;
    char *p = NULL;
    char delimiter = ',';
    if (fgets(reader->line, MAX_LINE_LENGTH, reader->file) == NULL) {
        ret = -1;
        goto cleanup;
    }
    reader->line_num++;
    reader->field_num = 0;
    p = strtok(reader->line, &delimiter);
    while (p!= NULL) {
        if (reader->field_num >= MAX_FIELDS) {
            fprintf(stderr, "Too many fields in line %d\n", reader->line_num);
            ret = -1;
            goto cleanup;
        }
        field_t *field = &reader->row.fields[reader->field_num];
        field->name = strdup(p);
        field->value = NULL;
        reader->field_num++;
        p = strtok(NULL, &delimiter);
    }
    ret = 0;
cleanup:
    return ret;
}

int main() {
    csv_reader_t *reader = csv_reader_create("data.csv");
    int ret;
    while ((ret = csv_reader_next_row(reader)) == 0) {
        printf("Line %d:\n", reader->line_num);
        for (int i = 0; i < reader->row.num_fields; i++) {
            printf("  %s: %s\n", reader->row.fields[i].name, reader->row.fields[i].value);
        }
    }
    csv_reader_destroy(reader);
    return ret;
}