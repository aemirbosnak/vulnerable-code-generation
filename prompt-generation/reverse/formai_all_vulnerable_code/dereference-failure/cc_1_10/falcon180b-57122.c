//Falcon-180B DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} Table;

Table* create_table() {
    Table *table = (Table*)malloc(sizeof(Table));
    table->num_rows = 0;
    table->num_columns = 0;
    table->data = (char**)malloc(MAX_ROWS * sizeof(char*));
    for (int i = 0; i < MAX_ROWS; i++) {
        table->data[i] = (char*)malloc(MAX_COLUMNS * sizeof(char));
        memset(table->data[i], 0, MAX_COLUMNS);
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

void add_row(Table *table, char *data) {
    int len = strlen(data);
    if (len > MAX_COLUMNS) {
        printf("Error: row too long\n");
        return;
    }
    table->data[table->num_rows] = (char*)malloc((len + 1) * sizeof(char));
    strcpy(table->data[table->num_rows], data);
    table->num_rows++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("%s\n", table->data[i]);
    }
}

int main() {
    Table *table = create_table();
    add_row(table, "John");
    add_row(table, "Doe");
    add_row(table, "25");
    add_row(table, "Male");
    print_table(table);
    destroy_table(table);
    return 0;
}