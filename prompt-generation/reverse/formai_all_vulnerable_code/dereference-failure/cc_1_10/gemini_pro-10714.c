//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

typedef struct {
    int num_rows;
    int num_columns;
    char **data;
} Table;

Table *create_table(int num_rows, int num_columns) {
    Table *table = malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(sizeof(char) * num_columns);
    }
    return table;
}

void free_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void insert_into_table(Table *table, int row, int column, char *value) {
    strcpy(table->data[row], value);
}

char *get_from_table(Table *table, int row, int column) {
    return table->data[row];
}

int main() {
    Table *table = create_table(10, 3);

    insert_into_table(table, 0, 0, "John");
    insert_into_table(table, 0, 1, "20");
    insert_into_table(table, 0, 2, "123 Main Street");

    insert_into_table(table, 1, 0, "Jane");
    insert_into_table(table, 1, 1, "21");
    insert_into_table(table, 1, 2, "456 Elm Street");

    printf("%s is %s years old and lives at %s.\n", get_from_table(table, 0, 0), get_from_table(table, 0, 1), get_from_table(table, 0, 2));
    printf("%s is %s years old and lives at %s.\n", get_from_table(table, 1, 0), get_from_table(table, 1, 1), get_from_table(table, 1, 2));

    free_table(table);

    return 0;
}