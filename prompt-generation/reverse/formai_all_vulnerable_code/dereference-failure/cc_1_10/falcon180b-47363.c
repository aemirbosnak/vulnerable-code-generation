//Falcon-180B DATASET v1.0 Category: Database querying ; Style: scientific
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
    Row *data;
} Table;

void create_table(Table *tbl, int num_rows, int num_cols) {
    tbl->num_rows = num_rows;
    tbl->num_cols = num_cols;
    tbl->data = malloc(sizeof(Row) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            tbl->data[i].name[j] = '\0';
            tbl->data[i].value[j] = '\0';
        }
    }
}

void add_row(Table *tbl, char *name, char *value) {
    int row_num = tbl->num_rows - 1;
    strcpy(tbl->data[row_num].name, name);
    strcpy(tbl->data[row_num].value, value);
}

void print_table(Table *tbl) {
    for (int i = 0; i < tbl->num_rows; i++) {
        for (int j = 0; j < tbl->num_cols; j++) {
            printf("%s ", tbl->data[i].name[j]);
        }
        printf("\n");
        for (int j = 0; j < tbl->num_cols; j++) {
            printf("%s ", tbl->data[i].value[j]);
        }
        printf("\n\n");
    }
}

int main() {
    Table tbl;
    create_table(&tbl, 3, 3);
    add_row(&tbl, "Name", "John");
    add_row(&tbl, "Age", "25");
    add_row(&tbl, "Gender", "Male");
    print_table(&tbl);
    return 0;
}