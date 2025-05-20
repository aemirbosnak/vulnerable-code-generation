//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 8000
#define MAX_FIELD_LEN 128
#define MAX_FIELDS 1000

typedef struct {
    char fields[MAX_FIELDS][MAX_FIELD_LEN];
    int num_fields;
} CSVRow;

int num_rows;
CSVRow *rows;

void parse_csv(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *token;
    int row_num = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        rows = realloc(rows, sizeof(CSVRow) * (row_num + 1));
        if (rows == NULL) {
            perror("Error allocating memory");
            exit(EXIT_FAILURE);
        }

        rows[row_num].num_fields = 0;

        token = strtok(line, ",");
        while (token != NULL) {
            token[strcspn(token, "\r\n")] = 0; // remove trailing newlines
            strncpy(rows[row_num].fields[rows[row_num].num_fields], token, MAX_FIELD_LEN);
            rows[row_num].num_fields++;

            token = strtok(NULL, ",");
        }

        row_num++;
    }

    num_rows = row_num;

    fclose(fp);
}

void print_csv() {
    int i, j;

    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < rows[i].num_fields; j++) {
            printf("%s ", rows[i].fields[j]);
        }
        printf("\n");
    }
}

int main() {
    rows = NULL;
    num_rows = 0;

    parse_csv("example.csv");

    print_csv();

    free(rows);

    return 0;
}