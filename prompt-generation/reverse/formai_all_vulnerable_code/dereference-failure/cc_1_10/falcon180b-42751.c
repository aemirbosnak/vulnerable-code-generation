//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 1000
#define DELIMITER ","

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = NULL;
    char line[MAX_LINE_LENGTH];
    char delimiter = DELIMITER[0];
    int num_fields = 0;
    int field_length = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_fields == MAX_NUM_FIELDS) {
            printf("Error: Too many fields in row\n");
            exit(1);
        }

        char *token = strtok(line, &delimiter);
        while (token!= NULL) {
            field_length = strlen(token);
            row->fields[num_fields] = malloc(field_length + 1);
            strcpy(row->fields[num_fields], token);
            num_fields++;
            token = strtok(NULL, &delimiter);
        }
    }

    row->num_fields = num_fields;
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
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    CSVRow *row = read_csv_file(fp);
    print_csv_row(row);

    free_csv_row(row);
    fclose(fp);

    return 0;
}