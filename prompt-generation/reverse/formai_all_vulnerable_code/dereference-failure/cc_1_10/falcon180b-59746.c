//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 50

typedef struct {
    char *name;
    int age;
    char *email;
} Record;

typedef struct {
    Record **records;
    int num_records;
    int num_cols;
} Database;

Database *create_database(int num_cols) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->records = (Record **)malloc(sizeof(Record *) * MAX_ROWS);
    db->num_records = 0;
    db->num_cols = num_cols;
    return db;
}

void add_record(Database *db, char *name, int age, char *email) {
    Record *record = (Record *)malloc(sizeof(Record));
    record->name = strdup(name);
    record->age = age;
    record->email = strdup(email);
    db->records[db->num_records++] = record;
}

void print_database(Database *db) {
    printf("+----+----------------+----------------+\n");
    for (int i = 0; i < db->num_cols; i++) {
        printf("| %s |", db->records[0]->name);
        for (int j = 1; j < db->num_records; j++) {
            printf(" %s |", db->records[j]->name);
        }
        printf("\n+----+----------------+----------------+\n");
    }
}

int main() {
    Database *db = create_database(3);
    add_record(db, "John", 25, "john@example.com");
    add_record(db, "Jane", 30, "jane@example.com");
    add_record(db, "Bob", 40, "bob@example.com");
    print_database(db);
    return 0;
}