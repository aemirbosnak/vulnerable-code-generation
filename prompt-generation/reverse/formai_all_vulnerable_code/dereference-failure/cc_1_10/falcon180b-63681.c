//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 1000
#define MAX_ROWS 1000000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    if (csv == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    int i;
    if (csv == NULL) {
        return;
    }
    for (i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read(CSV *csv, FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char *token;
    char **row;
    int i, j;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        csv->num_rows++;
        row = (char **) realloc(csv->data, sizeof(char *) * csv->num_rows);
        if (row == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
        csv->data = row;
        token = strtok(line, ",");
        i = 0;
        while (token!= NULL) {
            csv->num_columns = i + 1;
            row[csv->num_rows - 1] = (char *) malloc(strlen(token) + 1);
            if (row[csv->num_rows - 1] == NULL) {
                printf("Error: Memory allocation failed.\n");
                exit(1);
            }
            strcpy(row[csv->num_rows - 1], token);
            i++;
            token = strtok(NULL, ",");
        }
    }
}

void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    CSV *csv;
    FILE *fp;
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    csv = csv_create();
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        csv_destroy(csv);
        return 1;
    }
    csv_read(csv, fp);
    csv_print(csv);
    csv_destroy(csv);
    fclose(fp);
    return 0;
}