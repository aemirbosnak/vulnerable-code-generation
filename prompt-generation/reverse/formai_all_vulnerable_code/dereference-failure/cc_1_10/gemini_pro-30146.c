//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char city[MAX_LENGTH];
} Person;

typedef struct {
    char name[MAX_LENGTH];
    int num_columns;
    int num_rows;
    Person data[MAX_ROWS][MAX_COLUMNS];
} Table;

Table* create_table(char* name) {
    Table* table = (Table*)malloc(sizeof(Table));
    strcpy(table->name, name);
    table->num_columns = 0;
    table->num_rows = 0;
    return table;
}

void add_column(Table* table, char* name) {
    if (table->num_columns < MAX_COLUMNS) {
        strcpy(table->data[0][table->num_columns].name, name);
        table->num_columns++;
    } else {
        printf("Error: Maximum number of columns reached.\n");
    }
}

void add_row(Table* table, Person person) {
    if (table->num_rows < MAX_ROWS) {
        table->data[table->num_rows][0] = person;
        table->num_rows++;
    } else {
        printf("Error: Maximum number of rows reached.\n");
    }
}

void print_table(Table* table) {
    printf("Table: %s\n", table->name);
    printf("Number of columns: %d\n", table->num_columns);
    printf("Number of rows: %d\n", table->num_rows);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s ", table->data[i][j].name);
        }
        printf("\n");
    }
}

int main() {
    Table* table = create_table("People");

    add_column(table, "Name");
    add_column(table, "Age");
    add_column(table, "City");

    Person person1 = {"John Doe", 30, "New York City"};
    Person person2 = {"Jane Doe", 25, "Los Angeles"};

    add_row(table, person1);
    add_row(table, person2);

    print_table(table);

    return 0;
}