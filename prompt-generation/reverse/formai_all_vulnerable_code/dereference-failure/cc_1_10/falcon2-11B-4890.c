//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: artistic
// Artistic C Database Indexing System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 100
#define MAX_COLUMN_SIZE 20

typedef struct table {
    char name[MAX_COLUMN_SIZE];
    int id;
} table;

typedef struct database {
    int count;
    table* tables;
} database;

database create_database() {
    database db;
    db.count = 0;
    db.tables = NULL;
    return db;
}

void add_table(database* db, const char* name) {
    table new_table = {name, -1};
    if (db->count == MAX_TABLE_SIZE) {
        printf("Database is full.\n");
        return;
    }
    db->tables[db->count] = new_table;
    db->count++;
}

void print_database(database* db) {
    for (int i = 0; i < db->count; i++) {
        printf("Table %d: %s\n", i + 1, db->tables[i].name);
    }
}

int main() {
    database db = create_database();

    add_table(&db, "Artistic Indexing System");
    add_table(&db, "C Database Example");

    print_database(&db);

    return 0;
}