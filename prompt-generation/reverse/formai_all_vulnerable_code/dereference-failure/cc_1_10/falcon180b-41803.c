//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

typedef struct {
    char name[MAX_COLS];
    int age;
    char address[MAX_COLS];
} record_t;

typedef struct {
    char table_name[MAX_COLS];
    int num_rows;
    int num_cols;
    record_t *data;
} table_t;

table_t *create_table(char *table_name, int num_rows, int num_cols) {
    table_t *table = (table_t *)malloc(sizeof(table_t));
    strcpy(table->table_name, table_name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (record_t *)malloc(sizeof(record_t) * num_rows);
    return table;
}

void destroy_table(table_t *table) {
    free(table->data);
    free(table);
}

void add_record(table_t *table, int row, char *name, int age, char *address) {
    sprintf(table->data[row].name, "%s", name);
    table->data[row].age = age;
    strcpy(table->data[row].address, address);
}

void display_record(record_t record) {
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Address: %s\n", record.address);
}

void display_table(table_t *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i].name);
        }
        printf("\n");
        printf("Age: %d\n", table->data[i].age);
        printf("Address: %s\n\n", table->data[i].address);
    }
}

int main() {
    table_t *table = create_table("Employees", 3, 3);
    add_record(table, 0, "John", 25, "New York");
    add_record(table, 1, "Jane", 30, "Los Angeles");
    add_record(table, 2, "Bob", 40, "Chicago");
    display_table(table);
    destroy_table(table);
    return 0;
}