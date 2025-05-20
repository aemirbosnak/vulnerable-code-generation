//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table(char *name, int num_rows, int num_cols) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **) malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *) malloc(sizeof(char) * num_cols);
        memset(table->data[i], '\0', num_cols);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    printf("Number of Rows: %d\n", table->num_rows);
    printf("Number of Columns: %d\n", table->num_cols);
    printf("Data:\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%c ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table("example", 3, 3);
    table->data[0] = strdup("1");
    table->data[1] = strdup("2");
    table->data[2] = strdup("3");
    print_table(table);
    destroy_table(table);
    return 0;
}