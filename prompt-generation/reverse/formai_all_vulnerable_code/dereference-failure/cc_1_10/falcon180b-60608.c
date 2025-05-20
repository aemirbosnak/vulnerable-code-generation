//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char *name;
    int num_cols;
    char **data;
} Table;

Table *create_table(char *name, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));

    table->name = strdup(name);
    table->num_cols = num_cols;
    table->data = (char **)malloc(sizeof(char *) * num_cols);

    for (int i = 0; i < num_cols; i++) {
        table->data[i] = NULL;
    }

    return table;
}

void add_row(Table *table, char *row_data) {
    int row_size = strlen(row_data);

    if (row_size > MAX_DATA_SIZE) {
        printf("Error: row data exceeds maximum size\n");
        return;
    }

    for (int i = 0; i < table->num_cols; i++) {
        if (table->data[i] == NULL) {
            table->data[i] = strdup(row_data);
            break;
        }
    }
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);

    for (int i = 0; i < table->num_cols; i++) {
        printf("Column %d: ", i + 1);

        if (table->data[i]!= NULL) {
            printf("%s\n", table->data[i]);
        } else {
            printf("(empty)\n");
        }
    }
}

int main() {
    Table *table = create_table("example_table", 3);
    add_row(table, "John Doe");
    add_row(table, "Jane Smith");
    add_row(table, "Bob Johnson");

    print_table(table);

    for (int i = 0; i < table->num_cols; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);

    return 0;
}