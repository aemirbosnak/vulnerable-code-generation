//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 100

typedef struct {
    char **data;
    int num_columns;
} CSVRow;

CSVRow *read_csv_row(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char *token;
    CSVRow *row = malloc(sizeof(CSVRow));

    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        return NULL;
    }

    // tokenize the line
    token = strtok(line, ",");
    row->num_columns = 0;
    while (token != NULL) {
        row->data[row->num_columns] = malloc(strlen(token) + 1);
        strcpy(row->data[row->num_columns], token);
        row->num_columns++;
        token = strtok(NULL, ",");
    }

    return row;
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_columns; i++) {
        free(row->data[i]);
    }
    free(row->data);
    free(row);
}

int main(int argc, char **argv) {
    FILE *fp;
    CSVRow *row;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    while ((row = read_csv_row(fp)) != NULL) {
        for (int i = 0; i < row->num_columns; i++) {
            printf("%s ", row->data[i]);
        }
        printf("\n");
        free_csv_row(row);
    }

    fclose(fp);
    return 0;
}