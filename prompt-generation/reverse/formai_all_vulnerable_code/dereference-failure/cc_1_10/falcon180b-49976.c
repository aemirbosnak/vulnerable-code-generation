//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_VAL_LEN 1000

typedef struct {
    char *name;
    int type;
    int length;
    char *value;
} Column;

typedef struct {
    Column *columns;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->columns = malloc(num_cols * sizeof(Column));
    table->num_cols = num_cols;
    table->num_rows = 0;
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        free(table->columns[i].value);
    }
    free(table->columns);
    free(table);
}

void add_column(Table *table, char *name, int type, char *value) {
    Column *column = malloc(sizeof(Column));
    column->name = strdup(name);
    column->type = type;
    column->length = strlen(value);
    column->value = strdup(value);
    table->columns[table->num_cols - 1] = *column;
    table->num_cols++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        printf("%s | ", table->columns[i].name);
    }
    printf("\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s | ", table->columns[j].value);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3);
    add_column(table, "ID", 1, "1");
    add_column(table, "Name", 2, "Alan Turing");
    add_column(table, "Occupation", 2, "Mathematician and Computer Scientist");

    print_table(table);

    destroy_table(table);

    return 0;
}