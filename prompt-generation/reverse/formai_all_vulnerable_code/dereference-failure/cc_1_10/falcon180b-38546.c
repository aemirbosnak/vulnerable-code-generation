//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
    float salary;
} Record;

typedef struct {
    char tableName[MAX_DATA_SIZE];
    int numRows;
    int numCols;
    Record *data;
} Table;

void initTable(Table *table) {
    strcpy(table->tableName, "");
    table->numRows = 0;
    table->numCols = 0;
    table->data = NULL;
}

int addRow(Table *table) {
    if (table->numRows >= MAX_ROWS) {
        return -1;
    }
    table->numRows++;
    return 0;
}

int addCol(Table *table) {
    if (table->numCols >= MAX_COLS) {
        return -1;
    }
    table->numCols++;
    return 0;
}

int insertData(Table *table, int row, int col, char *data) {
    if (row >= table->numRows || col >= table->numCols) {
        return -1;
    }
    strcpy(table->data[row].name, data);
    return 0;
}

int searchData(Table *table, char *name) {
    int i;
    for (i = 0; i < table->numRows; i++) {
        if (strcmp(table->data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printTable(Table *table) {
    int i, j;
    printf("Table: %s\n", table->tableName);
    printf("+----+--------------------+--------------------+\n");
    for (j = 0; j < table->numCols; j++) {
        printf("| %s |", table->data[0].name);
    }
    printf("\n+----+--------------------+--------------------+\n");
    for (i = 0; i < table->numRows; i++) {
        printf("| %s | %d | %.2f |\n", table->data[i].name, table->data[i].age, table->data[i].salary);
    }
    printf("+----+--------------------+--------------------+\n");
}

int main() {
    Table table;
    initTable(&table);
    addRow(&table);
    addCol(&table);
    insertData(&table, 0, 0, "John Doe");
    insertData(&table, 0, 1, "25");
    insertData(&table, 0, 2, "50000.00");
    printTable(&table);
    return 0;
}