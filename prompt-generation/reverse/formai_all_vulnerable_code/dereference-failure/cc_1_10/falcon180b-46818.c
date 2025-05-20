//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **values;
    int num_columns;
} Row;

Row *read_csv_file(FILE *fp) {
    Row *row = NULL;
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_columns = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (row == NULL) {
            row = malloc(sizeof(Row));
            row->values = NULL;
            row->num_columns = 0;
        }

        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (num_columns >= MAX_COLUMNS) {
                fprintf(stderr, "Error: Too many columns in row.\n");
                exit(EXIT_FAILURE);
            }

            row->values = realloc(row->values, sizeof(char *) * ++num_columns);
            row->values[num_columns - 1] = strdup(token);

            token = strtok(NULL, DELIMITER);
        }

        if (num_columns == 0) {
            fprintf(stderr, "Error: Empty row.\n");
            exit(EXIT_FAILURE);
        }
    }

    return row;
}

void print_row(Row *row) {
    int i;

    for (i = 0; i < row->num_columns; i++) {
        printf("%s%c", row->values[i], i < row->num_columns - 1? DELIMITER : '\n');
    }
}

void free_row(Row *row) {
    int i;

    for (i = 0; i < row->num_columns; i++) {
        free(row->values[i]);
    }

    free(row->values);
    free(row);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Row *row;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file.\n");
        return 1;
    }

    row = read_csv_file(fp);
    if (row == NULL) {
        fclose(fp);
        return 1;
    }

    print_row(row);
    free_row(row);

    fclose(fp);
    return 0;
}