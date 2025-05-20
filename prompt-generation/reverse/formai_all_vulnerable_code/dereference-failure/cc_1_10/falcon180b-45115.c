//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
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
    char **data;
    int num_rows;
    int num_columns;
} Table;

Table *create_table(int num_rows, int num_columns) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->data = (char **) malloc(num_rows * sizeof(char *));
    table->num_rows = num_rows;
    table->num_columns = num_columns;

    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *) malloc(MAX_DATA_SIZE);
        memset(table->data[i], 0, MAX_DATA_SIZE);
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

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(2, 3);

    strcpy(table->data[0], "John");
    strcpy(table->data[1], "Doe");
    strcpy(table->data[2], "25");
    strcpy(table->data[3], "50000");
    strcpy(table->data[4], "Jane");
    strcpy(table->data[5], "Doe");
    strcpy(table->data[6], "30");
    strcpy(table->data[7], "60000");

    print_table(table);

    destroy_table(table);

    return 0;
}