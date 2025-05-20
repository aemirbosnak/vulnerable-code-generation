//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_table;

csv_table *csv_read_file(FILE *fp) {
    csv_table *table = malloc(sizeof(csv_table));
    table->num_rows = 0;
    table->num_cols = 0;
    table->data = malloc(MAX_ROWS * sizeof(char*));
    for (int i = 0; i < MAX_ROWS; i++) {
        table->data[i] = malloc(MAX_COLS * sizeof(char));
    }

    char line[MAX_CELL_SIZE];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            int row = table->num_rows;
            int col = table->num_cols;
            if (row >= MAX_ROWS || col >= MAX_COLS) {
                printf("Error: Table is too large for memory.\n");
                exit(1);
            }
            strcpy(table->data[row], token);
            table->num_cols++;
            token = strtok(NULL, ",");
            row++;
        }
        table->num_rows++;
    }

    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            if (table->data[i][j] == '\0') {
                strcpy(table->data[i][j], "");
            }
        }
    }

    return table;
}

void csv_print_table(csv_table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

void csv_free_table(csv_table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    csv_table *table = csv_read_file(fp);
    csv_print_table(table);

    csv_free_table(table);
    fclose(fp);

    return 0;
}