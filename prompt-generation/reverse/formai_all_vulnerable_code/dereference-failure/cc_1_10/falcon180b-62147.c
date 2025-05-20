//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table() {
    Table *table = malloc(sizeof(Table));
    table->num_rows = 0;
    table->num_cols = 0;
    table->data = NULL;
    return table;
}

void add_row(Table *table, char *row_data) {
    int row_len = strlen(row_data);
    if (table->num_cols == 0) {
        table->num_cols = row_len;
    } else if (row_len!= table->num_cols) {
        printf("Error: row length does not match table column length.\n");
        exit(1);
    }
    char **new_data = realloc(table->data, sizeof(char *) * table->num_rows * table->num_cols);
    if (new_data == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }
    table->data = new_data;
    for (int i = 0; i < table->num_rows; i++) {
        table->data[i * table->num_cols + row_len - 1] = '\0';
    }
    strcpy(table->data[table->num_rows * table->num_cols - row_len], row_data);
    table->num_rows++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i * table->num_cols + j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table();
    add_row(table, "Name Age Gender");
    add_row(table, "John 25 M");
    add_row(table, "Jane 30 F");
    add_row(table, "Bob 40 M");
    print_table(table);
    free(table->data);
    free(table);
    return 0;
}