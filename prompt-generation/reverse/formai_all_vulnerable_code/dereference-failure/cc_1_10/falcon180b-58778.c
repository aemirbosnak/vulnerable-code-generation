//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define DELIMITER ","

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv(FILE *file) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = malloc(MAX_FIELDS * sizeof(char *));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            row->fields[row->num_fields++] = strdup(token);
            token = strtok(NULL, DELIMITER);
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    CSVRow *row = read_csv(file);
    print_csv_row(row);

    free_csv_row(row);
    fclose(file);

    return 0;
}