//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the index table
#define INDEX_TABLE_SIZE 100

// Define the maximum length of a key
#define KEY_MAX_LENGTH 100

// Define the maximum number of records per index entry
#define RECORDS_PER_INDEX_ENTRY 10

// Define the structure of an index entry
typedef struct index_entry {
    char key[KEY_MAX_LENGTH];
    int record_ids[RECORDS_PER_INDEX_ENTRY];
    int num_records;
} index_entry;

// Define the structure of the index table
typedef struct index_table {
    index_entry entries[INDEX_TABLE_SIZE];
    int num_entries;
} index_table;

// Create a new index table
index_table* create_index_table() {
    index_table* table = malloc(sizeof(index_table));
    table->num_entries = 0;
    return table;
}

// Insert a new key into the index table
void insert_key(index_table* table, char* key, int record_id) {
    // Find the index entry for the key
    index_entry* entry = NULL;
    for (int i = 0; i < table->num_entries; i++) {
        if (strcmp(table->entries[i].key, key) == 0) {
            entry = &table->entries[i];
            break;
        }
    }

    // If the index entry does not exist, create a new one
    if (entry == NULL) {
        entry = &table->entries[table->num_entries++];
        strcpy(entry->key, key);
        entry->num_records = 0;
    }

    // Insert the record ID into the index entry
    entry->record_ids[entry->num_records++] = record_id;
}

// Search for a key in the index table
int* search_key(index_table* table, char* key) {
    // Find the index entry for the key
    index_entry* entry = NULL;
    for (int i = 0; i < table->num_entries; i++) {
        if (strcmp(table->entries[i].key, key) == 0) {
            entry = &table->entries[i];
            break;
        }
    }

    // If the index entry does not exist, return NULL
    if (entry == NULL) {
        return NULL;
    }

    // Return the array of record IDs
    return entry->record_ids;
}

// Print the index table
void print_index_table(index_table* table) {
    for (int i = 0; i < table->num_entries; i++) {
        index_entry* entry = &table->entries[i];
        printf("%s: ", entry->key);
        for (int j = 0; j < entry->num_records; j++) {
            printf("%d ", entry->record_ids[j]);
        }
        printf("\n");
    }
}

// Free the index table
void free_index_table(index_table* table) {
    free(table);
}

// Main function
int main() {
    // Create a new index table
    index_table* table = create_index_table();

    // Insert some keys into the index table
    insert_key(table, "name", 1);
    insert_key(table, "age", 2);
    insert_key(table, "city", 3);

    // Search for a key in the index table
    int* record_ids = search_key(table, "name");

    // Print the record IDs
    for (int i = 0; i < RECORDS_PER_INDEX_ENTRY; i++) {
        printf("%d ", record_ids[i]);
    }
    printf("\n");

    // Print the index table
    print_index_table(table);

    // Free the index table
    free_index_table(table);

    return 0;
}