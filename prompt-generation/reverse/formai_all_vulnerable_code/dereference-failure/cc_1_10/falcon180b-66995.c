//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

/* Define the structure of a database */
typedef struct {
    char name[50];
    int age;
    float income;
} Record;

/* Define the structure of a table */
typedef struct {
    Record records[MAX_ROWS][MAX_COLS];
    int num_rows;
    int num_cols;
} Table;

/* Function to create a new empty table */
Table* create_table(int rows, int cols) {
    Table* table = (Table*)malloc(sizeof(Table));
    if (table == NULL) {
        printf("Error: Unable to allocate memory for the table.\n");
        exit(1);
    }
    table->num_rows = rows;
    table->num_cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            strcpy(table->records[i][j].name, "");
            table->records[i][j].age = 0;
            table->records[i][j].income = 0.0;
        }
    }
    return table;
}

/* Function to add a new record to the table */
void add_record(Table* table, int row, int col, const char* name, int age, float income) {
    if (row >= table->num_rows || col >= table->num_cols) {
        printf("Error: Invalid row or column index.\n");
        return;
    }
    strcpy(table->records[row][col].name, name);
    table->records[row][col].age = age;
    table->records[row][col].income = income;
}

/* Function to print the contents of the table */
void print_table(Table* table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s %d %.2f\n", table->records[i][j].name, table->records[i][j].age, table->records[i][j].income);
        }
    }
}

int main() {
    Table* table = create_table(3, 3);
    add_record(table, 0, 0, "John", 25, 50000.00);
    add_record(table, 1, 1, "Jane", 30, 60000.00);
    add_record(table, 2, 2, "Bob", 40, 70000.00);
    print_table(table);
    return 0;
}