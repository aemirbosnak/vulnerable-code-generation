//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Row;

typedef struct {
    int numRows;
    int numCols;
    Row *data;
} Table;

void createTable(Table *table) {
    table->numRows = 0;
    table->numCols = 0;
    table->data = NULL;
}

void addRow(Table *table, const char *name, const char *value) {
    if (table->numRows >= MAX_ROWS) {
        printf("Error: Table is full.\n");
        return;
    }
    if (table->numCols == 0) {
        table->numCols = strlen(name);
    } else if (strlen(name)!= table->numCols) {
        printf("Error: Columns must be of equal length.\n");
        return;
    }
    Row row;
    strcpy(row.name, name);
    strcpy(row.value, value);
    table->data = realloc(table->data, sizeof(Row) * (table->numRows + 1));
    table->data[table->numRows] = row;
    table->numRows++;
}

void printTable(const Table *table) {
    if (table->numRows == 0) {
        printf("Table is empty.\n");
        return;
    }
    int maxNameLen = table->numCols;
    for (int i = 0; i < table->numRows; i++) {
        printf("%-*s | %s\n", maxNameLen, table->data[i].name, table->data[i].value);
    }
}

void freeTable(Table *table) {
    for (int i = 0; i < table->numRows; i++) {
        free(table->data[i].name);
        free(table->data[i].value);
    }
    free(table->data);
    table->numRows = 0;
    table->numCols = 0;
}

int main() {
    Table table;
    createTable(&table);
    addRow(&table, "Name", "John");
    addRow(&table, "Age", "30");
    addRow(&table, "Gender", "Male");
    printTable(&table);
    freeTable(&table);
    return 0;
}