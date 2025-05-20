//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    Record *data;
    int num_records;
    int num_cols;
} Table;

void init_table(Table *table, int num_cols) {
    table->data = (Record *)malloc(MAX_ROWS * sizeof(Record));
    table->num_records = 0;
    table->num_cols = num_cols;
}

void add_record(Table *table, char *name, int age, float salary) {
    Record *record = (Record *)malloc(sizeof(Record));
    record->name = strdup(name);
    record->age = age;
    record->salary = salary;

    table->data[table->num_records++] = *record;
}

void print_table(Table *table) {
    printf("+----+----------------+--------------+\n");
    for (int i = 0; i < table->num_cols; i++) {
        printf("| %s |", table->data[0].name);
        for (int j = 1; j < table->num_records; j++) {
            printf(" %s |", table->data[j].name);
        }
        printf("\n");
    }
    printf("+----+----------------+--------------+\n");
}

int main() {
    Table employee_table;
    init_table(&employee_table, 3);

    add_record(&employee_table, "John Doe", 30, 50000.0);
    add_record(&employee_table, "Jane Smith", 28, 60000.0);
    add_record(&employee_table, "Jim Brown", 25, 40000.0);

    print_table(&employee_table);

    return 0;
}