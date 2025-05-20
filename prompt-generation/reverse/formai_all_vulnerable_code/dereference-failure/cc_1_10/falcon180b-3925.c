//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    char data[100];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Database;

void init_database(Database *db, int max_records) {
    db->records = (Record *) malloc(max_records * sizeof(Record));
    db->num_records = 0;
    db->max_records = max_records;
}

int hash_function(int key, int max_records) {
    return key % max_records;
}

void insert_record(Database *db, int key, char *data) {
    int index = hash_function(key, db->max_records);
    if (db->num_records == db->max_records) {
        printf("Database is full!\n");
        return;
    }
    db->records[index].key = key;
    strcpy(db->records[index].data, data);
    db->num_records++;
}

void search_record(Database *db, int key) {
    int index = hash_function(key, db->max_records);
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[index].key == key) {
            printf("Record found:\nKey: %d\nData: %s\n", db->records[index].key, db->records[index].data);
            return;
        }
        index = (index + 1) % db->max_records;
    }
    printf("Record not found.\n");
}

void delete_record(Database *db, int key) {
    int index = hash_function(key, db->max_records);
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[index].key == key) {
            db->records[index].key = -1;
            db->records[index].data[0] = '\0';
            db->num_records--;
            printf("Record deleted.\n");
            return;
        }
        index = (index + 1) % db->max_records;
    }
    printf("Record not found.\n");
}

int main() {
    Database db;
    init_database(&db, 10);
    insert_record(&db, 123, "John Doe");
    insert_record(&db, 456, "Jane Doe");
    search_record(&db, 123);
    delete_record(&db, 456);
    return 0;
}