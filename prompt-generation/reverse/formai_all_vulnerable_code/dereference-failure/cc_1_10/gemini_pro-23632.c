//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_INDEX_ENTRIES 1000

struct Record {
    int id;
    char name[32];
    int age;
};

struct IndexEntry {
    int id;
    int record_offset;
};

struct Database {
    struct Record records[MAX_RECORDS];
    struct IndexEntry index[MAX_INDEX_ENTRIES];
    int num_records;
    int num_index_entries;
};

struct Database* create_database() {
    struct Database* db = malloc(sizeof(struct Database));
    db->num_records = 0;
    db->num_index_entries = 0;
    return db;
}

void destroy_database(struct Database* db) {
    free(db);
}

int add_record(struct Database* db, struct Record* record) {
    if (db->num_records >= MAX_RECORDS) {
        return -1;  // Database is full
    }

    db->records[db->num_records] = *record;
    db->index[db->num_records].id = record->id;
    db->index[db->num_records].record_offset = db->num_records;
    db->num_records++;
    db->num_index_entries++;

    return 0;
}

int find_record_by_id(struct Database* db, int id, struct Record* record) {
    int i;
    for (i = 0; i < db->num_index_entries; i++) {
        if (db->index[i].id == id) {
            *record = db->records[db->index[i].record_offset];
            return 0;  // Record found
        }
    }

    return -1;  // Record not found
}

void print_database(struct Database* db) {
    int i;
    printf("Records:\n");
    for (i = 0; i < db->num_records; i++) {
        printf("  %d %s %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }

    printf("Index:\n");
    for (i = 0; i < db->num_index_entries; i++) {
        printf("  %d %d\n", db->index[i].id, db->index[i].record_offset);
    }
}

int main() {
    struct Database* db = create_database();

    struct Record record1 = {1, "John", 20};
    add_record(db, &record1);

    struct Record record2 = {2, "Mary", 25};
    add_record(db, &record2);

    struct Record record3 = {3, "Bob", 30};
    add_record(db, &record3);

    print_database(db);

    struct Record found_record;
    int id = 2;
    if (find_record_by_id(db, id, &found_record) == 0) {
        printf("Found record with ID %d: %s %d\n", found_record.id, found_record.name, found_record.age);
    } else {
        printf("Record with ID %d not found\n", id);
    }

    destroy_database(db);

    return 0;
}