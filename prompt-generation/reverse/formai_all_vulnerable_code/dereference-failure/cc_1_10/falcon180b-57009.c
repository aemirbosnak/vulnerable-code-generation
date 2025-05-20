//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: protected
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
    Table *table = malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_cols = num_cols;
    table->data = malloc(num_cols * sizeof(char*));
    for (int i = 0; i < num_cols; i++) {
        table->data[i] = NULL;
    }
    return table;
}

void add_row(Table *table, char **data) {
    for (int i = 0; i < table->num_cols; i++) {
        if (data[i]!= NULL) {
            table->data[i] = realloc(table->data[i], strlen(data[i]) + 1);
            strcpy(table->data[i], data[i]);
        }
    }
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    printf("Columns:\n");
    for (int i = 0; i < table->num_cols; i++) {
        printf("Column %d: %s\n", i+1, table->data[i]);
    }
    printf("\n");
}

void delete_table(Table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

int main() {
    Table *table = create_table("Employees", 3);
    char **data = malloc(3 * sizeof(char*));
    data[0] = strdup("John Doe");
    data[1] = strdup("Software Engineer");
    data[2] = strdup("50000");
    add_row(table, data);

    data[0] = strdup("Jane Smith");
    data[1] = strdup("Project Manager");
    data[2] = strdup("60000");
    add_row(table, data);

    data[0] = strdup("Bob Johnson");
    data[1] = strdup("Data Analyst");
    data[2] = strdup("55000");
    add_row(table, data);

    print_table(table);

    delete_table(table);

    return 0;
}