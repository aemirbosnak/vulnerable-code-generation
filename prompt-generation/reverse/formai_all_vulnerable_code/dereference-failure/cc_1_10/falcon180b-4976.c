//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int num_cols;
    char **data;
} Table;

Table *create_table(char *name, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_cols = num_cols;
    table->data = (char **)malloc(num_cols * sizeof(char *));
    for (int i = 0; i < num_cols; i++) {
        table->data[i] = NULL;
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

void add_row(Table *table, char **data) {
    for (int i = 0; i < table->num_cols; i++) {
        table->data[i] = (char *)realloc(table->data[i], strlen(data[i]) + 1);
        strcpy(table->data[i], data[i]);
    }
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    for (int i = 0; i < table->num_cols; i++) {
        printf("Column %d: %s\n", i+1, table->data[i]);
    }
}

int main() {
    Table *table1 = create_table("Table 1", 3);
    Table *table2 = create_table("Table 2", 2);

    char **data1 = (char **)malloc(3 * sizeof(char *));
    data1[0] = strdup("John");
    data1[1] = strdup("25");
    data1[2] = strdup("USA");
    add_row(table1, data1);

    char **data2 = (char **)malloc(2 * sizeof(char *));
    data2[0] = strdup("Alice");
    data2[1] = strdup("30");
    add_row(table2, data2);

    print_table(table1);
    print_table(table2);

    destroy_table(table1);
    destroy_table(table2);

    return 0;
}