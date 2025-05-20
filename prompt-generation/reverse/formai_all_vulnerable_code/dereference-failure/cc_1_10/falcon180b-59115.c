//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **values;
    int num_columns;
} Row;

Row *read_csv_file(FILE *file) {
    char line[MAX_LINE_SIZE];
    char *token;
    Row *row = malloc(sizeof(Row));
    row->values = malloc(MAX_COLUMNS * sizeof(char*));
    row->num_columns = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            row->values[row->num_columns] = strdup(token);
            row->num_columns++;
            token = strtok(NULL, DELIMITER);
        }
    }

    return row;
}

void print_row(Row *row) {
    int i;

    for (i = 0; i < row->num_columns; i++) {
        printf("%s ", row->values[i]);
    }
    printf("\n");
}

int main() {
    FILE *file;
    Row *row;

    file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    row = read_csv_file(file);

    print_row(row);

    fclose(file);

    return 0;
}