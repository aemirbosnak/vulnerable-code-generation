//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

typedef struct {
    char *name;
    int age;
    char *address;
} Row;

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->data = (char **)malloc(num_rows * sizeof(char *));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_cols * MAX_FIELD_SIZE);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

int read_csv_file(char *filename, Table *table) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }
    char line[MAX_FIELD_SIZE];
    int num_rows = 0;
    while (fgets(line, MAX_FIELD_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_index = 0;
        while (token!= NULL && col_index < table->num_cols) {
            strcpy(table->data[num_rows][col_index], token);
            col_index++;
            token = strtok(NULL, ",");
        }
        num_rows++;
    }
    fclose(fp);
    return num_rows;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s\t", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(MAX_ROWS, 3);
    int num_rows = read_csv_file("data.csv", table);
    print_table(table);
    destroy_table(table);
    return 0;
}