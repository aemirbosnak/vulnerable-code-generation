//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
} Person;

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    Person **data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db, int num_rows, int num_cols) {
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = (Person **)malloc(num_rows * sizeof(Person *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = (Person *)malloc(num_cols * sizeof(Person));
        for (int j = 0; j < num_cols; j++) {
            db->data[i][j].id = -1;
        }
    }
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
}

int get_empty_slot(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            if (db->data[i][j].id == -1) {
                return i * db->num_cols + j;
            }
        }
    }
    return -1;
}

int main() {
    Database db;
    init_database(&db, 10, 10);

    int empty_slot = get_empty_slot(&db);
    if (empty_slot!= -1) {
        db.data[empty_slot / db.num_cols][empty_slot % db.num_cols].id = 0;
        strcpy(db.data[empty_slot / db.num_cols][empty_slot % db.num_cols].name, "John Doe");
    }

    empty_slot = get_empty_slot(&db);
    if (empty_slot!= -1) {
        db.data[empty_slot / db.num_cols][empty_slot % db.num_cols].id = 1;
        strcpy(db.data[empty_slot / db.num_cols][empty_slot % db.num_cols].name, "Jane Doe");
    }

    destroy_database(&db);
    return 0;
}