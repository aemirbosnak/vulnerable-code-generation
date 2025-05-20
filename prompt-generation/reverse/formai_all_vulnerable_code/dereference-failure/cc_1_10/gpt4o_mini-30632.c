//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_INDEX 10
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    int index;
    Record *record;
} IndexEntry;

typedef struct {
    IndexEntry *entries[MAX_INDEX];
    int count;
} IndexTable;

Record records[MAX_RECORDS];
int record_count = 0;

IndexTable *create_index() {
    IndexTable *index_table = malloc(sizeof(IndexTable));
    index_table->count = 0;
    return index_table;
}

void insert_record(Record record, IndexTable *index_table) {
    if (record_count >= MAX_RECORDS || index_table->count >= MAX_INDEX) {
        printf("Maximum records or indexes exceeded.\n");
        return;
    }
    
    records[record_count] = record;
    
    IndexEntry *entry = malloc(sizeof(IndexEntry));
    entry->index = record.id;  // Using ID as index for simplicity
    entry->record = &records[record_count];
    index_table->entries[index_table->count++] = entry;
    
    record_count++;
}

void search_by_id(int id, IndexTable *index_table) {
    for (int i = 0; i < index_table->count; i++) {
        if (index_table->entries[i]->index == id) {
            printf("Record found: ID = %d, Name = %s\n", 
                   index_table->entries[i]->record->id, 
                   index_table->entries[i]->record->name);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void display_all_records() {
    printf("All Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d, Name: %s\n", records[i].id, records[i].name);
    }
}

void free_index(IndexTable *index_table) {
    for (int i = 0; i < index_table->count; i++) {
        free(index_table->entries[i]);
    }
    free(index_table);
}

int main() {
    IndexTable *index_table = create_index();

    // Sample records
    Record record1 = {1, "Alice"};
    Record record2 = {2, "Bob"};
    Record record3 = {3, "Charlie"};
    
    // Inserting records
    insert_record(record1, index_table);
    insert_record(record2, index_table);
    insert_record(record3, index_table);
    
    display_all_records();
    
    // Searching for records
    printf("\nSearching for record with ID 2:\n");
    search_by_id(2, index_table);
    
    printf("\nSearching for record with ID 4:\n");
    search_by_id(4, index_table);
    
    // Cleanup
    free_index(index_table);
    
    return 0;
}