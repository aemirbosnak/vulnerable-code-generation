//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 512

typedef struct {
    char delimiter;
    FILE *file;
    int num_fields;
    char **fields;
} CSVReader;

CSVReader *CSVReader_create(FILE *file, char delimiter) {
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    if (reader == NULL) {
        return NULL;
    }
    reader->delimiter = delimiter;
    reader->file = file;
    reader->num_fields = 0;
    reader->fields = NULL;
    return reader;
}

void CSVReader_destroy(CSVReader *reader) {
    if (reader == NULL) {
        return;
    }
    if (reader->fields!= NULL) {
        for (int i = 0; i < reader->num_fields; i++) {
            free(reader->fields[i]);
        }
        free(reader->fields);
    }
    free(reader);
}

int CSVReader_read_line(CSVReader *reader) {
    char line[MAX_LINE_SIZE];
    if (fgets(line, MAX_LINE_SIZE, reader->file) == NULL) {
        return 0;
    }
    char *token = strtok(line, reader->delimiter);
    while (token!= NULL) {
        reader->num_fields++;
    }
    reader->fields = (char **)realloc(reader->fields, sizeof(char *) * reader->num_fields);
    if (reader->fields == NULL) {
        return 0;
    }
    rewind(reader->file);
    token = strtok(line, reader->delimiter);
    int i = 0;
    while (token!= NULL) {
        reader->fields[i] = strdup(token);
        i++;
        token = strtok(NULL, reader->delimiter);
    }
    return 1;
}

int CSVReader_get_num_fields(CSVReader *reader) {
    return reader->num_fields;
}

char *CSVReader_get_field(CSVReader *reader, int field_index) {
    if (field_index >= reader->num_fields) {
        return NULL;
    }
    return reader->fields[field_index];
}

void CSVReader_print_fields(CSVReader *reader) {
    for (int i = 0; i < reader->num_fields; i++) {
        printf("%s ", reader->fields[i]);
    }
    printf("\n");
}

#include <assert.h>

int main() {
    CSVReader *reader = CSVReader_create(stdin, ',');
    assert(reader!= NULL);
    while (CSVReader_read_line(reader)) {
        CSVReader_print_fields(reader);
    }
    CSVReader_destroy(reader);
    return 0;
}