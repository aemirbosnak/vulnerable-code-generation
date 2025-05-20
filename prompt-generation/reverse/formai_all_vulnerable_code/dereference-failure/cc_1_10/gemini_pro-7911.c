//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_LENGTH 50

typedef struct {
    char name[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
} record_t;

typedef struct {
    record_t records[MAX_RECORDS];
    int num_records;
} database_t;

database_t* create_database() {
    database_t* db = malloc(sizeof(database_t));
    db->num_records = 0;
    return db;
}

void destroy_database(database_t* db) {
    free(db);
}

int add_record(database_t* db, record_t* record) {
    if (db->num_records >= MAX_RECORDS) {
        return -1;
    }
    db->records[db->num_records] = *record;
    db->num_records++;
    return 0;
}

int find_record(database_t* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int delete_record(database_t* db, char* name) {
    int index = find_record(db, name);
    if (index == -1) {
        return -1;
    }
    for (int i = index + 1; i < db->num_records; i++) {
        db->records[i - 1] = db->records[i];
    }
    db->num_records--;
    return 0;
}

void print_record(record_t* record) {
    printf("Name: %s\n", record->name);
    printf("Address: %s\n", record->address);
    printf("Phone: %s\n", record->phone);
}

void print_database(database_t* db) {
    for (int i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
        printf("\n");
    }
}

int main() {
    database_t* db = create_database();

    record_t record1 = {"John Doe", "123 Main Street", "555-123-4567"};
    add_record(db, &record1);

    record_t record2 = {"Jane Doe", "456 Elm Street", "555-234-5678"};
    add_record(db, &record2);

    print_database(db);

    int index = find_record(db, "Jane Doe");
    if (index != -1) {
        print_record(&db->records[index]);
    }

    delete_record(db, "John Doe");

    print_database(db);

    destroy_database(db);

    return 0;
}