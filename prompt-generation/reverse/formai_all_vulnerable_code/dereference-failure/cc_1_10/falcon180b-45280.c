//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv(FILE *file) {
    CSVRow *row = NULL;
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (row == NULL) {
            row = (CSVRow *) malloc(sizeof(CSVRow));
            row->fields = (char **) malloc(MAX_FIELDS * sizeof(char *));
            row->num_fields = 0;
        }

        token = strtok(line, ",");
        while (token!= NULL) {
            row->fields[num_fields] = strdup(token);
            num_fields++;

            if (num_fields >= MAX_FIELDS) {
                printf("Error: Too many fields in row\n");
                exit(1);
            }

            token = strtok(NULL, ",");
        }

        num_fields++;
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    int i;

    for (i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }

    printf("\n");
}

void free_csv_row(CSVRow *row) {
    int i;

    for (i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }

    free(row->fields);
    free(row);
}

int main() {
    FILE *file;
    CSVRow *row;

    file = fopen("example.csv", "r");

    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    row = read_csv(file);

    if (row == NULL) {
        printf("Error: Invalid CSV format\n");
        exit(1);
    }

    print_csv_row(row);

    free_csv_row(row);

    fclose(file);

    return 0;
}