//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA 1000

typedef struct {
    char *name;
    int id;
    float balance;
} row_t;

row_t *rows;
int num_rows;
int num_cols;
char *col_names[MAX_COLS];

void init_database() {
    rows = (row_t *)malloc(MAX_ROWS * sizeof(row_t));
    num_rows = 0;
    num_cols = 0;
    for (int i = 0; i < MAX_COLS; i++) {
        col_names[i] = (char *)malloc(MAX_DATA * sizeof(char));
        strcpy(col_names[i], "");
    }
}

void add_row(char *name, int id, float balance) {
    row_t *row = (row_t *)malloc(sizeof(row_t));
    row->name = (char *)malloc(MAX_DATA * sizeof(char));
    strcpy(row->name, name);
    row->id = id;
    row->balance = balance;
    rows[num_rows++] = *row;
}

void add_column(char *name) {
    col_names[num_cols++] = (char *)malloc(MAX_DATA * sizeof(char));
    strcpy(col_names[num_cols - 1], name);
}

void print_row(row_t *row) {
    printf("Name: %s\n", row->name);
    printf("ID: %d\n", row->id);
    printf("Balance: $%.2f\n", row->balance);
}

void print_table() {
    printf("+----+--------------------------------------------------------------------------------------------------+\n");
    for (int i = 0; i < num_cols; i++) {
        printf("| %s |", col_names[i]);
    }
    printf("|\n");
    for (int i = 0; i < num_rows; i++) {
        printf("+----+--------------------------------------------------------------------------------------------------+\n");
        print_row(&rows[i]);
    }
}

int main() {
    init_database();
    add_column("Name");
    add_column("ID");
    add_column("Balance");
    add_row("John Doe", 1, 1000.00);
    add_row("Jane Smith", 2, 2000.00);
    add_row("Bob Johnson", 3, 3000.00);
    print_table();
    return 0;
}