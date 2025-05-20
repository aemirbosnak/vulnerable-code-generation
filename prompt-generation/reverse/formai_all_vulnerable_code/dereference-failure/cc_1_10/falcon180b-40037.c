//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Row;

typedef struct {
    int num_rows;
    int num_cols;
    Row **data;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Row **)malloc(sizeof(Row *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (Row *)malloc(sizeof(Row) * num_cols);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            free(table->data[i][j].name);
            free(table->data[i][j].value);
        }
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

int read_csv_file(const char *filename, Table *table) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    char line[MAX_VALUE_LEN];
    int row = 0;
    int col = 0;
    while (fgets(line, MAX_VALUE_LEN, fp)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }
        strcpy(table->data[row][col].name, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: missing value for row %d, column %d\n", row, col);
            destroy_table(table);
            fclose(fp);
            return -1;
        }
        strcpy(table->data[row][col].value, token);
        col++;
        if (col >= table->num_cols) {
            row++;
            col = 0;
        }
    }

    fclose(fp);
    return 0;
}

int write_csv_file(const char *filename, Table *table) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            fprintf(fp, "%s,%s\n", table->data[i][j].name, table->data[i][j].value);
        }
    }

    fclose(fp);
    return 0;
}

int main() {
    Table *table = create_table(3, 3);
    read_csv_file("example.csv", table);
    write_csv_file("output.csv", table);
    destroy_table(table);
    return 0;
}