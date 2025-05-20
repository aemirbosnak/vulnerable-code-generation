//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 256

typedef struct {
    char *fields[MAX_NUM_FIELDS];
    int num_fields;
} CsvRow;

typedef struct {
    char delimiter;
    FILE *file;
} CsvReader;

CsvRow *CsvRow_new(int num_fields) {
    CsvRow *row = (CsvRow *)malloc(sizeof(CsvRow));
    row->num_fields = num_fields;
    int i;
    for (i = 0; i < num_fields; i++) {
        row->fields[i] = NULL;
    }
    return row;
}

void CsvRow_delete(CsvRow *row) {
    int i;
    for (i = 0; i < row->num_fields; i++) {
        if (row->fields[i] != NULL) {
            free(row->fields[i]);
        }
    }
    free(row);
}

char *CsvRow_get(CsvRow *row, int index) {
    if (index < 0 || index >= row->num_fields) {
        return NULL;
    }
    return row->fields[index];
}

CsvReader *CsvReader_new(char delimiter, const char *filename) {
    CsvReader *reader = (CsvReader *)malloc(sizeof(CsvReader));
    reader->delimiter = delimiter;
    reader->file = fopen(filename, "r");
    return reader;
}

void CsvReader_delete(CsvReader *reader) {
    fclose(reader->file);
    free(reader);
}

CsvRow *CsvReader_getNextRow(CsvReader *reader) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, reader->file) == NULL) {
        return NULL;
    }
    CsvRow *row = CsvRow_new(MAX_NUM_FIELDS);
    int i = 0;
    char *token;
    token = strtok(line, &(reader->delimiter));
    while (token != NULL) {
        row->fields[i] = (char *)malloc(strlen(token) + 1);
        strcpy(row->fields[i], token);
        i++;
        token = strtok(NULL, &(reader->delimiter));
    }
    row->num_fields = i;
    return row;
}

int main() {
    CsvReader *reader = CsvReader_new(',', "test.csv");
    CsvRow *row;
    while ((row = CsvReader_getNextRow(reader)) != NULL) {
        int i;
        for (i = 0; i < row->num_fields; i++) {
            printf("%s ", CsvRow_get(row, i));
        }
        printf("\n");
        CsvRow_delete(row);
    }
    CsvReader_delete(reader);
    return 0;
}