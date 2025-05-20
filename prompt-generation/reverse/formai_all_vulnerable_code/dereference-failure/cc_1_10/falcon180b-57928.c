//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_ROWS 1000
#define MAX_NUM_COLS 1000
#define MAX_NUM_CHARS 1000

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table() {
    Table *table = (Table *)malloc(sizeof(Table));
    table->num_rows = 0;
    table->num_cols = 0;
    table->data = (char **)malloc(MAX_NUM_ROWS * sizeof(char *));
    for (int i = 0; i < MAX_NUM_ROWS; i++) {
        table->data[i] = (char *)malloc(MAX_NUM_COLS * sizeof(char));
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

void add_row(Table *table, char *row) {
    table->data[table->num_rows] = strdup(row);
    table->num_rows++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("%s\n", table->data[i]);
    }
}

int main() {
    Table *table = create_table();
    char input[MAX_NUM_CHARS];
    while (fgets(input, MAX_NUM_CHARS, stdin)!= NULL) {
        if (strcmp(input, "ADD ROW") == 0) {
            char row[MAX_NUM_CHARS];
            fgets(row, MAX_NUM_CHARS, stdin);
            add_row(table, row);
        } else if (strcmp(input, "PRINT TABLE") == 0) {
            print_table(table);
        }
    }
    destroy_table(table);
    return 0;
}