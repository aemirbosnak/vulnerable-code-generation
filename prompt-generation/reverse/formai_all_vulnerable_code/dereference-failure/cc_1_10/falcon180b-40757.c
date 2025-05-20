//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELDS 100
#define DELIMITER ','

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *file) {
    CSVRow *row = NULL;
    char line[MAX_LINE_LENGTH];
    char *token = NULL;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (row == NULL) {
            row = malloc(sizeof(CSVRow));
            row->num_fields = 0;
            row->fields = malloc(MAX_FIELDS * sizeof(char*));
        }

        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (num_fields >= MAX_FIELDS) {
                printf("Error: Too many fields in a row.\n");
                exit(1);
            }

            row->fields[num_fields] = strdup(token);
            num_fields++;

            token = strtok(NULL, DELIMITER);
        }

        if (num_fields == 0) {
            printf("Warning: Empty row.\n");
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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file '%s'.\n", argv[1]);
        return 1;
    }

    CSVRow *row = read_csv_file(file);
    if (row == NULL) {
        printf("Error: Cannot read CSV file.\n");
        return 1;
    }

    print_csv_row(row);

    free_csv_row(row);
    fclose(file);

    return 0;
}