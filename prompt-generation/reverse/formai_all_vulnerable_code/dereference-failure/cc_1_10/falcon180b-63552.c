//Falcon-180B DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROW_LENGTH 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database* create_database() {
    Database *db = (Database*) malloc(sizeof(Database));
    db->num_rows = 0;
    db->num_cols = 0;
    db->data = (char**) malloc(sizeof(char*) * MAX_ROWS);
    for (int i = 0; i < MAX_ROWS; i++) {
        db->data[i] = (char*) malloc(sizeof(char) * MAX_ROW_LENGTH);
        memset(db->data[i], 0, sizeof(char) * MAX_ROW_LENGTH);
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void add_row(Database *db, char *row) {
    db->data[db->num_rows] = row;
    db->num_rows++;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s\n", db->data[i]);
    }
}

int main() {
    Database *db = create_database();
    add_row(db, "Name,Age,Gender");
    add_row(db, "John,25,Male");
    add_row(db, "Jane,30,Female");
    add_row(db, "Bob,20,Male");
    print_database(db);
    destroy_database(db);
    return 0;
}