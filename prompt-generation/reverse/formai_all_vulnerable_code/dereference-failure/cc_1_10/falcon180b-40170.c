//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_ROWS 1000
#define MAX_NUM_COLS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int num_rows;
    int num_cols;
} table_t;

typedef struct {
    table_t *tables;
    int num_tables;
} database_t;

void init_database(database_t *db) {
    db->num_tables = 0;
    db->tables = NULL;
}

void add_table(database_t *db, char *name, int num_rows, int num_cols) {
    table_t *table = malloc(sizeof(table_t));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    db->tables = realloc(db->tables, sizeof(table_t) * (db->num_tables + 1));
    db->tables[db->num_tables++] = *table;
}

void print_tables(database_t *db) {
    printf("Tables:\n");
    for (int i = 0; i < db->num_tables; i++) {
        printf("  %s (%dx%d)\n", db->tables[i].name, db->tables[i].num_rows, db->tables[i].num_cols);
    }
}

int main() {
    database_t db;
    init_database(&db);

    add_table(&db, "employees", 10, 4);
    add_table(&db, "departments", 5, 3);
    add_table(&db, "projects", 8, 6);

    print_tables(&db);

    return 0;
}