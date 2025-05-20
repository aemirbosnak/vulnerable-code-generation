//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char *data;
    int length;
} String;

typedef struct {
    String **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_row(FILE *fp) {
    CSVRow *row = (CSVRow *) malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = (String **) malloc(MAX_FIELDS * sizeof(String *));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        String *field = (String *) malloc(sizeof(String));
        field->data = line;
        field->length = strlen(line);
        row->fields[row->num_fields++] = field;
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s", row->fields[i]->data);
        if (i!= row->num_fields - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]->data);
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSVRow *row = read_csv_row(fp);

    while (row!= NULL) {
        print_csv_row(row);
        free_csv_row(row);
        row = read_csv_row(fp);
    }

    fclose(fp);
    return 0;
}