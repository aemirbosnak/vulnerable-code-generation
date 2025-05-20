//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    int age;
    char gender;
} Record;

typedef struct {
    Record *data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table() {
    Table *table = (Table *)malloc(sizeof(Table));
    table->data = (Record *)malloc(MAX_ROW * sizeof(Record));
    table->num_rows = 0;
    table->num_cols = 3;
    return table;
}

void add_record(Table *table, char *name, int id, int age, char gender) {
    Record *record = &table->data[table->num_rows];
    strcpy(record->name, name);
    record->id = id;
    record->age = age;
    record->gender = gender;
    table->num_rows++;
}

void print_table(Table *table) {
    printf("+----+-----+-----+--------+\n");
    printf("| ID | Name | Age | Gender |\n");
    printf("+----+-----+-----+--------+\n");
    for (int i = 0; i < table->num_rows; i++) {
        printf("| %d | %s | %d | %c |\n", table->data[i].id, table->data[i].name, table->data[i].age, table->data[i].gender);
    }
    printf("+----+-----+-----+--------+\n");
}

int main() {
    Table *table = create_table();

    add_record(table, "John Doe", 1, 25, 'M');
    add_record(table, "Jane Doe", 2, 30, 'F');
    add_record(table, "Bob Smith", 3, 40, 'M');

    print_table(table);

    return 0;
}