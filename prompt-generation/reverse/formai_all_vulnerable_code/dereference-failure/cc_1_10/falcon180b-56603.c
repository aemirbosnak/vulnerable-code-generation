//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    Record **rows;
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->rows = (Record **)malloc(num_rows * sizeof(Record *));
    for (int i = 0; i < num_rows; i++) {
        db->rows[i] = (Record *)malloc(num_cols * sizeof(Record));
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            free(db->rows[i][j].name);
        }
        free(db->rows[i]);
    }
    free(db->rows);
    free(db);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s\t", db->rows[i][j].name);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(3, 3);
    db->rows[0][0].name = strdup("Alice");
    db->rows[0][1].name = strdup("25");
    db->rows[0][2].name = strdup("50000");
    db->rows[1][0].name = strdup("Bob");
    db->rows[1][1].name = strdup("30");
    db->rows[1][2].name = strdup("60000");
    db->rows[2][0].name = strdup("Charlie");
    db->rows[2][1].name = strdup("35");
    db->rows[2][2].name = strdup("70000");
    print_database(db);
    destroy_database(db);
    return 0;
}