//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100
#define MAX_KEY 20

typedef struct {
    char key[MAX_KEY];
    char data[MAX_DATA];
} Record;

typedef struct {
    Record* records;
    int num_records;
} Database;

Database* db = NULL;

void init_database() {
    db = (Database*)malloc(sizeof(Database));
    db->records = (Record*)malloc(MAX_DATA * sizeof(Record));
    db->num_records = 0;
}

int add_record(char* key, char* data) {
    if (db->num_records >= MAX_DATA) {
        printf("Error: Database is full.\n");
        return 0;
    }

    Record* record = &db->records[db->num_records];
    strcpy(record->key, key);
    strcpy(record->data, data);

    db->num_records++;

    return 1;
}

int search_record(char* key) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            printf("Record found:\nKey: %s\nData: %s\n", db->records[i].key, db->records[i].data);
            return 1;
        }
    }

    printf("Record not found.\n");
    return 0;
}

int delete_record(char* key) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            strcpy(db->records[i].key, "");
            strcpy(db->records[i].data, "");

            db->num_records--;

            return 1;
        }
    }

    printf("Record not found.\n");
    return 0;
}

int main() {
    init_database();

    add_record("Name", "John");
    add_record("Age", "30");
    add_record("City", "New York");

    search_record("Name");
    search_record("City");

    delete_record("Age");

    search_record("Age");

    return 0;
}