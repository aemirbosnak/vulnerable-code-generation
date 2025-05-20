//FormAI DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} record_t;

typedef struct {
    record_t* records[MAX_RECORDS];
    int size;
} database_t;

typedef struct {
    database_t* database;
    int* indexes;
    int length;
} index_t;

database_t* create_database() {
    database_t* database = malloc(sizeof(database_t));
    database->size = 0;
    return database;
}

void add_record_to_database(database_t* database, char* name, char* email) {
    if(database->size >= MAX_RECORDS) {
        printf("Database full, cannot add more records.\n");
        return;
    }
    
    record_t* record = malloc(sizeof(record_t));
    strncpy(record->name, name, MAX_NAME_LENGTH - 1);
    strncpy(record->email, email, MAX_EMAIL_LENGTH - 1);
    database->records[database->size] = record;
    database->size++;
}

index_t* create_index(database_t* database) {
    index_t* index = malloc(sizeof(index_t));
    index->database = database;
    index->indexes = malloc(sizeof(int) * MAX_RECORDS);
    index->length = 0;

    for(int i = 0; i < database->size; i++) {
        index->indexes[index->length] = i;
        index->length++;
    }

    return index;
}

index_t* get_records_by_name(index_t* index, char* name) {
    index_t* result_index = malloc(sizeof(index_t));
    result_index->database = index->database;
    result_index->indexes = malloc(sizeof(int) * index->length);
    result_index->length = 0;

    for(int i = 0; i < index->length; i++) {
        int index_of_record = index->indexes[i];
        record_t* record = index->database->records[index_of_record];

        if(strcmp(record->name, name) == 0) {
            result_index->indexes[result_index->length] = index_of_record;
            result_index->length++;
        }
    }

    return result_index;
}

int main() {
    database_t* database = create_database();
    add_record_to_database(database, "Alice", "alice@example.com");
    add_record_to_database(database, "Bob", "bob@example.com");
    add_record_to_database(database, "Charlie", "charlie@example.com");
    add_record_to_database(database, "David", "david@example.com");
    add_record_to_database(database, "Eve", "eve@example.com");

    index_t* name_index = create_index(database);
    index_t* alice_records = get_records_by_name(name_index, "Alice");

    printf("Records for Alice:\n");
    for(int i = 0; i < alice_records->length; i++) {
        record_t* record = database->records[alice_records->indexes[i]];
        printf("%s %s\n", record->name, record->email);
    }

    return 0;
}