//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Row;

typedef struct {
    int num_rows;
    int num_cols;
    Row rows[MAX_ROWS][MAX_COLS];
} Table;

Table* create_table() {
    Table* table = (Table*)malloc(sizeof(Table));
    table->num_rows = 0;
    table->num_cols = 0;
    return table;
}

void add_row(Table* table, const char* name, const char* value) {
    Row row;
    strncpy(row.name, name, MAX_NAME_LEN);
    strncpy(row.value, value, MAX_VALUE_LEN);
    table->rows[table->num_rows][table->num_cols++] = row;
    table->num_rows++;
}

void print_table(Table* table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s\t%s\n", table->rows[i][j].name, table->rows[i][j].value);
        }
    }
}

int main() {
    Table* table = create_table();

    add_row(table, "Name", "John Doe");
    add_row(table, "Age", "30");
    add_row(table, "Occupation", "Hacker");
    add_row(table, "Skills", "Programming, Cyber Security, Hacking");

    print_table(table);

    return 0;
}