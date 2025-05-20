//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 1000
#define DELIMITER ','

typedef struct {
    char **fields;
    int num_fields;
    int max_fields;
} CSVRow;

CSVRow *CSVReader(FILE *file) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->fields = NULL;
    row->num_fields = 0;
    row->max_fields = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (row->num_fields >= row->max_fields) {
                row->max_fields += 100;
                row->fields = realloc(row->fields, row->max_fields * sizeof(char *));
            }
            row->fields[row->num_fields] = strdup(token);
            row->num_fields++;
            token = strtok(NULL, DELIMITER);
        }
    }

    return row;
}

void CSVDestroy(CSVRow *row) {
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
        return 1;
    }

    CSVRow *row = CSVReader(file);

    if (row == NULL) {
        printf("Error: Could not read file.\n");
        fclose(file);
        return 2;
    }

    for (int i = 0; i < row->num_fields; i++) {
        printf("%s\n", row->fields[i]);
    }

    CSVDestroy(row);

    fclose(file);
    return 0;
}