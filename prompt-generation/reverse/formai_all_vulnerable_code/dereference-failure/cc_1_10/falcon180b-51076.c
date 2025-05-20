//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_NUMBER 1000
#define MAX_FIELD_LENGTH 1024

typedef struct {
    char **fields;
    int field_count;
} CSVRow;

CSVRow *read_csv_file(FILE *file) {
    CSVRow *row = NULL;
    char buffer[MAX_LINE_LENGTH];
    char *line = NULL;
    size_t line_size = 0;
    int field_count = 0;

    while ((getline(&line, &line_size, file))!= -1) {
        if (line_size == 0) {
            continue;
        }

        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        CSVRow *new_row = malloc(sizeof(CSVRow));
        new_row->field_count = 0;
        new_row->fields = malloc(MAX_FIELD_NUMBER * sizeof(char*));

        while (token!= NULL && field_count < MAX_FIELD_NUMBER) {
            new_row->fields[field_count] = strdup(token);
            token = strtok(NULL, ",");
            field_count++;
        }

        new_row->field_count = field_count;
        row = new_row;
    }

    free(line);
    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    CSVRow *row = read_csv_file(file);
    if (row == NULL) {
        printf("Error: could not read file\n");
        return 1;
    }

    print_csv_row(row);

    free_csv_row(row);
    fclose(file);

    return 0;
}