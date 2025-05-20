//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int age;
    float salary;
} Data;

typedef struct {
    int num_rows;
    int num_cols;
    Data *data;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Data *)malloc(num_rows * sizeof(Data));
    for (int i = 0; i < num_rows; i++) {
        table->data[i].name = (char *)malloc(MAX_DATA_SIZE);
        table->data[i].age = 0;
        table->data[i].salary = 0.0;
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i].name);
    }
    free(table->data);
    free(table);
}

void insert_row(Table *table, int row_index, char *name, int age, float salary) {
    table->data[row_index].name = strdup(name);
    table->data[row_index].age = age;
    table->data[row_index].salary = salary;
}

void delete_row(Table *table, int row_index) {
    free(table->data[row_index].name);
    table->data[row_index] = table->data[table->num_rows - 1];
    table->num_rows--;
}

void print_table(Table *table) {
    printf("+----+------------------+-----+\n");
    printf("| %10s | %30s | %10s |\n", "Name", "Age", "Salary");
    printf("+----+------------------+-----+\n");
    for (int i = 0; i < table->num_rows; i++) {
        printf("| %10s | %10d | %10.2f |\n", table->data[i].name, table->data[i].age, table->data[i].salary);
    }
    printf("+----+------------------+-----+\n");
}

int main() {
    Table *table = create_table(3, 3);
    insert_row(table, 0, "John Doe", 25, 50000.0);
    insert_row(table, 1, "Jane Smith", 30, 60000.0);
    insert_row(table, 2, "Bob Johnson", 35, 70000.0);
    print_table(table);

    delete_row(table, 1);
    insert_row(table, 1, "Alice Green", 28, 55000.0);
    print_table(table);

    destroy_table(table);
    return 0;
}