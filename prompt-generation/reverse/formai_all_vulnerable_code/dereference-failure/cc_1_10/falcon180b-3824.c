//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100
#define DELIMITER ","

typedef struct {
    char **fields;
    int num_fields;
} Row;

Row *read_csv_file(FILE *fp) {
    char line[MAX_LINE_SIZE];
    char *token;
    Row *row = malloc(sizeof(Row));
    row->fields = NULL;
    row->num_fields = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (row->num_fields >= MAX_FIELDS) {
            printf("Error: Too many fields in row.\n");
            exit(1);
        }
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            row->fields = realloc(row->fields, sizeof(char *) * ++row->num_fields);
            row->fields[row->num_fields - 1] = strdup(token);
            token = strtok(NULL, DELIMITER);
        }
    }

    return row;
}

void print_row(Row *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_row(Row *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    Row *row = read_csv_file(fp);
    if (row == NULL) {
        exit(1);
    }

    print_row(row);

    free_row(row);
    fclose(fp);

    return 0;
}