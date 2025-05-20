//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_CHARACTERS 100

typedef struct {
    char* name;
    int id;
} Record;

typedef struct {
    Record* rows;
    int num_rows;
    int num_columns;
} Table;

Table* create_table(int num_rows, int num_columns) {
    Table* table = (Table*)malloc(sizeof(Table));

    table->rows = (Record*)malloc(sizeof(Record) * num_rows);
    table->num_rows = num_rows;
    table->num_columns = num_columns;

    for (int i = 0; i < num_rows; i++) {
        table->rows[i].name = (char*)malloc(MAX_CHARACTERS * sizeof(char));
        table->rows[i].id = i;
    }

    return table;
}

void add_record(Table* table, char* name) {
    table->rows[table->num_rows - 1].name = strdup(name);
}

void print_table(Table* table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("%d: %s\n", table->rows[i].id, table->rows[i].name);
    }
}

int main() {
    Table* table = create_table(10, 2);

    add_record(table, "John");
    add_record(table, "Jane");
    add_record(table, "Doe");

    print_table(table);

    return 0;
}