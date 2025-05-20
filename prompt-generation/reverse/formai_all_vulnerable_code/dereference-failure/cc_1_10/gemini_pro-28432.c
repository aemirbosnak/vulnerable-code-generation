//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 1000

typedef struct {
    char* name;
    int type;
    int size;
} Column;

typedef struct {
    char* data;
    int* indexes;
} Row;

typedef struct {
    char* name;
    Column* columns;
    int num_columns;
    Row* rows;
    int num_rows;
    int* indexes[MAX_COLUMNS];
    int num_indexes[MAX_COLUMNS];
} Table;

Table* create_table(char* name, Column* columns, int num_columns) {
    Table* table = malloc(sizeof(Table));
    table->name = name;
    table->columns = columns;
    table->num_columns = num_columns;
    table->rows = malloc(sizeof(Row) * MAX_ROWS);
    table->num_rows = 0;
    for (int i = 0; i < MAX_COLUMNS; i++) {
        table->indexes[i] = NULL;
        table->num_indexes[i] = 0;
    }
    return table;
}

void insert_row(Table* table, char** data) {
    Row* row = &table->rows[table->num_rows++];
    row->data = malloc(sizeof(char) * MAX_COLUMNS * MAX_ROWS);
    for (int i = 0; i < table->num_columns; i++) {
        strcpy(row->data + i * MAX_ROWS, data[i]);
    }
    for (int i = 0; i < table->num_columns; i++) {
        int index = atoi(data[i]);
        if (table->indexes[i] == NULL) {
            table->indexes[i] = malloc(sizeof(int) * MAX_ROWS);
            table->num_indexes[i] = 0;
        }
        table->indexes[i][table->num_indexes[i]++] = table->num_rows - 1;
    }
}

void print_table(Table* table) {
    printf("Table: %s\n", table->name);
    for (int i = 0; i < table->num_columns; i++) {
        printf("%s", table->columns[i].name);
        if (i < table->num_columns - 1) {
            printf(", ");
        }
    }
    printf("\n");
    for (int i = 0; i < table->num_rows; i++) {
        Row* row = &table->rows[i];
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s", row->data + j * MAX_ROWS);
            if (j < table->num_columns - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main() {
    Column columns[] = {
        {"id", 0, 4},
        {"name", 1, 255},
        {"age", 0, 3},
    };
    Table* table = create_table("people", columns, 3);
    insert_row(table, (char*[]){"1", "John", "25"});
    insert_row(table, (char*[]){"2", "Mary", "23"});
    insert_row(table, (char*[]){"3", "Bob", "21"});
    print_table(table);
    return 0;
}