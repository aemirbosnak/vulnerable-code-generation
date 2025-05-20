//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **values;
    int num_cols;
} Row;

Row *read_csv_file(FILE *fp) {
    Row *row = NULL;
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_cols = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        num_cols = 0;
        row = (Row *) realloc(row, sizeof(Row) + sizeof(char *) * num_cols);

        token = strtok(line, ",");
        while (token!= NULL) {
            row->values[num_cols] = strdup(token);
            num_cols++;
            token = strtok(NULL, ",");
        }

        row->num_cols = num_cols;
    }

    return row;
}

void print_row(Row *row) {
    int i;

    for (i = 0; i < row->num_cols; i++) {
        printf("%s ", row->values[i]);
    }

    printf("\n");
}

void free_row(Row *row) {
    int i;

    for (i = 0; i < row->num_cols; i++) {
        free(row->values[i]);
    }

    free(row);
}

int main() {
    FILE *fp;
    Row *row;

    fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    row = read_csv_file(fp);

    if (row == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }

    printf("CSV Data:\n");
    while (row!= NULL) {
        print_row(row);
        row = read_csv_file(fp);
    }

    fclose(fp);

    return 0;
}