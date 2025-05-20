//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

typedef struct record {
    char name[50];
    int age;
    float salary;
} record_t;

typedef struct database {
    char *file_name;
    size_t records_count;
    record_t *records;
} database_t;

void init_database(database_t *db) {
    db->file_name = malloc(50);
    db->records_count = 0;
    db->records = malloc(MAX_RECORDS * sizeof(record_t));
}

void add_record(database_t *db, char *name, int age, float salary) {
    if (db->records_count >= MAX_RECORDS) {
        printf("Database is full, cannot add more records\n");
        return;
    }

    strcpy(db->records[db->records_count].name, name);
    db->records[db->records_count].age = age;
    db->records[db->records_count].salary = salary;
    db->records_count++;
}

record_t *get_record(database_t *db, int index) {
    if (index < 0 || index >= db->records_count) {
        printf("Invalid record index %d\n", index);
        return NULL;
    }

    return &db->records[index];
}

void delete_record(database_t *db, int index) {
    if (index < 0 || index >= db->records_count) {
        printf("Invalid record index %d\n", index);
        return;
    }

    memmove(db->records + index, db->records + index + 1,
            (db->records_count - index - 1) * sizeof(record_t));
    db->records_count--;
}

void print_records(database_t *db) {
    printf("Records in database:\n");
    for (int i = 0; i < db->records_count; i++) {
        printf("%d: %s, %d, %f\n", i, db->records[i].name, db->records[i].age,
               db->records[i].salary);
    }
}

int main() {
    database_t db;
    init_database(&db);

    add_record(&db, "John", 25, 50000.0);
    add_record(&db, "Jane", 30, 60000.0);
    add_record(&db, "Bob", 35, 70000.0);

    print_records(&db);

    delete_record(&db, 1);

    print_records(&db);

    return 0;
}