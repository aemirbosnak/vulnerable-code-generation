//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL_LEN 100

typedef struct {
    char *name;
    int num_cols;
    char **col_names;
    char **col_values;
} Table;

Table *create_table(char *name, int num_cols, char **col_names) {
    Table *table = malloc(sizeof(Table));
    table->name = name;
    table->num_cols = num_cols;
    table->col_names = col_names;
    table->col_values = malloc(sizeof(char *) * num_cols);
    for (int i = 0; i < num_cols; i++) {
        table->col_values[i] = malloc(sizeof(char) * MAX_VAL_LEN);
        memset(table->col_values[i], 0, MAX_VAL_LEN);
    }
    return table;
}

void add_row(Table *table, char **values) {
    for (int i = 0; i < table->num_cols; i++) {
        strncpy(table->col_values[i], values[i], MAX_VAL_LEN);
    }
}

void print_table(Table *table) {
    printf("Table %s:\n", table->name);
    printf("---------------------------------\n");
    for (int i = 0; i < table->num_cols; i++) {
        printf("%s | %s\n", table->col_names[i], table->col_values[i]);
    }
}

int main() {
    Table *table = create_table("example_table", 3, (char **) {"ID", "Name", "Age"});
    add_row(table, (char **) {"1", "John", "25"});
    add_row(table, (char **) {"2", "Jane", "30"});
    add_row(table, (char **) {"3", "Bob", "20"});
    print_table(table);
    return 0;
}