//Falcon-180B DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_ROWS 1000
#define MAX_COLS 10

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float salary;
} Record;

typedef struct {
    int rows;
    int cols;
    Record *data;
} Table;

void init_table(Table *table) {
    table->rows = 0;
    table->cols = 0;
    table->data = NULL;
}

void add_record(Table *table, Record *record) {
    table->data = realloc(table->data, sizeof(Record) * (table->rows + 1));
    memcpy(&table->data[table->rows], record, sizeof(Record));
    table->rows++;
}

void print_table(Table *table) {
    printf("+----+-----+--------+\n");
    printf("| %s | %s | %s     |\n", "Name", "Age", "Salary");
    printf("+----+-----+--------+\n");
    for (int i = 0; i < table->rows; i++) {
        printf("| %s | %d | %.2f |\n", table->data[i].name, table->data[i].age, table->data[i].salary);
    }
    printf("+----+-----+--------+\n");
}

int main() {
    Table table;
    init_table(&table);

    Record record1 = {"John Doe", 25, 50000.00};
    Record record2 = {"Jane Smith", 30, 60000.00};
    Record record3 = {"Jim Brown", 35, 70000.00};

    add_record(&table, &record1);
    add_record(&table, &record2);
    add_record(&table, &record3);

    print_table(&table);

    return 0;
}