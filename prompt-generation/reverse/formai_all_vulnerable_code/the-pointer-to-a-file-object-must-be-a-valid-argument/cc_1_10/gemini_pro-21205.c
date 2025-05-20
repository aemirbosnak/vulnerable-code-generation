//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 10

struct CSVRow {
    char *columns[MAX_NUM_COLUMNS];
    int num_columns;
};

struct CSVReader {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *next_line;
    int line_num;
};

struct CSVReader *CSVReader_create(FILE *file) {
    struct CSVReader *reader = malloc(sizeof(struct CSVReader));
    reader->file = file;
    reader->next_line = NULL;
    reader->line_num = 0;
    return reader;
}

void CSVReader_destroy(struct CSVReader *reader) {
    free(reader);
}

int CSVReader_next_line(struct CSVReader *reader) {
    if (reader->next_line != NULL) {
        strcpy(reader->line, reader->next_line);
        reader->next_line = NULL;
    } else {
        if (fgets(reader->line, MAX_LINE_LENGTH, reader->file) == NULL) {
            return 0;
        }
    }
    reader->line_num++;
    return 1;
}

struct CSVRow *CSVReader_parse_line(struct CSVReader *reader) {
    struct CSVRow *row = malloc(sizeof(struct CSVRow));
    row->num_columns = 0;

    char *line = reader->line;
    char *column = strtok(line, ",");
    while (column != NULL) {
        row->columns[row->num_columns++] = strdup(column);
        column = strtok(NULL, ",");
    }

    return row;
}

void CSVRow_destroy(struct CSVRow *row) {
    for (int i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }
    free(row);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    struct CSVReader *reader = CSVReader_create(file);

    while (CSVReader_next_line(reader)) {
        struct CSVRow *row = CSVReader_parse_line(reader);
        for (int i = 0; i < row->num_columns; i++) {
            printf("%s", row->columns[i]);
            if (i < row->num_columns - 1) {
                printf(", ");
            }
        }
        printf("\n");
        CSVRow_destroy(row);
    }

    CSVReader_destroy(reader);
    fclose(file);

    return 0;
}