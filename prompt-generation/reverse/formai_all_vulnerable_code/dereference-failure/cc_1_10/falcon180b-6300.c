//Falcon-180B DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 1000
#define MAX_LEN 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->data = malloc(num_rows * sizeof(char*));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(num_cols * sizeof(char));
        memset(table->data[i], 0, num_cols);
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

int read_csv(FILE *file, Table *table) {
    char line[MAX_LEN];
    int num_cols = 0;
    while (fgets(line, MAX_LEN, file)) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            num_cols++;
            token = strtok(NULL, ",");
        }
        if (num_cols > table->num_cols) {
            table->num_cols = num_cols;
            for (int i = 0; i < table->num_rows; i++) {
                table->data[i] = realloc(table->data[i], table->num_cols * sizeof(char));
                memset(table->data[i] + table->num_cols - num_cols, 0, table->num_cols - num_cols);
            }
        }
    }
    return num_cols;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    Table *table = create_table(0, 0);
    int num_cols = read_csv(file, table);
    print_table(table);
    destroy_table(table);
    fclose(file);
    return 0;
}