//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    int num_rows;
    int num_cols;
    Record *data;
} Table;

void create_table(Table *table, int num_rows, int num_cols) {
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Record *) malloc(num_rows * num_cols * sizeof(Record));
}

void destroy_table(Table *table) {
    free(table->data);
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i * table->num_cols + j].name);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    Employee emp1 = {"John", 25, 50000};
    Employee emp2 = {"Jane", 30, 60000};
    Employee emp3 = {"Bob", 20, 40000};

    create_table(&table, 3, 3);

    table.data[0] = (Record) {.name = "John",.age = 25,.salary = 50000 };
    table.data[1] = (Record) {.name = "Jane",.age = 30,.salary = 60000 };
    table.data[2] = (Record) {.name = "Bob",.age = 20,.salary = 40000 };

    print_table(&table);

    destroy_table(&table);
    return 0;
}