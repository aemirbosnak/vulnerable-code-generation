//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_ROWS 1000
#define MAX_NUM_COLS 1000

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
} Table;

Table *tables = NULL;
int num_tables = 0;

void add_table(char *name, int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->name = malloc(MAX_NAME_LENGTH * sizeof(char));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    tables = realloc(tables, sizeof(Table) * ++num_tables);
    tables[num_tables - 1] = *table;
    free(table);
}

void print_tables() {
    for (int i = 0; i < num_tables; i++) {
        printf("Table %d:\n", i + 1);
        printf("Name: %s\n", tables[i].name);
        printf("Number of Rows: %d\n", tables[i].num_rows);
        printf("Number of Columns: %d\n\n", tables[i].num_cols);
    }
}

int main() {
    char input[MAX_NAME_LENGTH];
    int rows, cols;

    while (1) {
        printf("Enter table name (or type 'exit' to quit):\n");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;

        printf("Enter number of rows:\n");
        scanf("%d", &rows);

        printf("Enter number of columns:\n");
        scanf("%d", &cols);

        add_table(input, rows, cols);
    }

    print_tables();

    return 0;
}