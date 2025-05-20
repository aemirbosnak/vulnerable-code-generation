//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define MAX_FIELD_LENGTH 256

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *csv_read_row(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char *token;
    CSVRow *row = (CSVRow *)malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = (char **)malloc(sizeof(char *) * MAX_FIELDS);

    fgets(line, MAX_LINE_LENGTH, fp);
    token = strtok(line, ",");
    while (token!= NULL) {
        if (row->num_fields >= MAX_FIELDS) {
            printf("Error: too many fields in row.\n");
            exit(1);
        }
        row->fields[row->num_fields] = strdup(token);
        row->num_fields++;
        token = strtok(NULL, ",");
    }

    return row;
}

void csv_print_row(CSVRow *row) {
    int i;
    for (i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void csv_free_row(CSVRow *row) {
    int i;
    for (i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp;
    CSVRow *row;

    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while ((row = csv_read_row(fp))!= NULL) {
        csv_print_row(row);
        csv_free_row(row);
    }

    fclose(fp);
    return 0;
}