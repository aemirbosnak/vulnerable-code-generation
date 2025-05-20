//Falcon-180B DATASET v1.0 Category: Database querying ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char *name;
    int age;
    float salary;
} Person;

typedef struct {
    int rows;
    int cols;
    Person *data;
} Table;

void init_table(Table *table) {
    table->rows = 0;
    table->cols = 0;
    table->data = NULL;
}

int add_row(Table *table) {
    table->rows++;
    table->data = realloc(table->data, sizeof(Person) * table->rows);
    return table->rows - 1;
}

int add_col(Table *table, char *name) {
    table->cols++;
    Person *row = table->data + (table->rows - 1);
    row->name = strdup(name);
    return table->cols - 1;
}

void set_data(Table *table, int row, int col, float value) {
    Person *person = table->data + row;
    person->salary = value;
}

float get_data(Table *table, int row, int col) {
    Person *person = table->data + row;
    return person->salary;
}

void print_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%s ", table->data[i].name);
            printf("%d ", table->data[i].age);
            printf("%f ", table->data[i].salary);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    init_table(&table);

    add_row(&table);
    add_col(&table, "John");
    set_data(&table, 0, 0, 50000.0);

    add_row(&table);
    add_col(&table, "Jane");
    set_data(&table, 1, 0, 60000.0);

    print_table(&table);

    return 0;
}