//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_DB_SIZE 1000
#define MAX_RECORD_SIZE 1024

typedef struct record {
    char name[50];
    int age;
} record_t;

typedef struct database {
    int num_records;
    record_t **records;
} database_t;

void init_database(database_t *db) {
    db->num_records = 0;
    db->records = calloc(MAX_DB_SIZE, sizeof(record_t *));
}

void insert_record(database_t *db, char *name, int age) {
    record_t *new_record = calloc(1, sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;
    db->num_records++;
    db->records = realloc(db->records, (db->num_records * sizeof(record_t *)) + sizeof(record_t));
    db->records[db->num_records - 1] = new_record;
}

void print_database(database_t *db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        printf("%d. %s (%d)\n", i, db->records[i]->name, db->records[i]->age);
    }
}

int main() {
    database_t db;
    init_database(&db);

    insert_record(&db, "Alice", 25);
    insert_record(&db, "Bob", 30);
    insert_record(&db, "Charlie", 20);

    print_database(&db);

    return 0;
}