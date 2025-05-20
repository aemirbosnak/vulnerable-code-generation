//FormAI DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a database table row
typedef struct {
    int id;
    char name[20];
    int age;
} Row;

// Definition of a database table
typedef struct {
    Row *data;
    int num_rows;
} Table;

// Print a single row of the table
void print_row(Row *row) {
    printf("%d\t%s\t%d\n", row->id, row->name, row->age);
}

// Print the entire table
void print_table(Table *table) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < table->num_rows; i++) {
        print_row(&table->data[i]);
    }
}

// Add a new row to the table
void insert_row(Table *table, Row *row) {
    table->data = realloc(table->data, (table->num_rows + 1) * sizeof(Row));
    table->data[table->num_rows] = *row;
    table->num_rows++;
}

int main() {
    Table my_table = {NULL, 0};
    Row r1 = {1, "John", 25};
    Row r2 = {2, "Jane", 30};

    printf("Initial table:\n");
    print_table(&my_table);

    insert_row(&my_table, &r1);
    insert_row(&my_table, &r2);

    printf("After adding rows:\n");
    print_table(&my_table);

    return 0;
}