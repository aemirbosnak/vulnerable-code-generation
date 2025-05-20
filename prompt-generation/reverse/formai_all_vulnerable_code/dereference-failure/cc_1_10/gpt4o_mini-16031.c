//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101

typedef struct Record {
    int id; // Unique identifier
    char name[50]; // Name of the record
    struct Record* next; // Pointer to the next record for collision handling
} Record;

typedef struct HashTable {
    Record** table;
} HashTable;

// Function to create a new record
Record* createRecord(int id, const char* name) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->id = id;
    strcpy(newRecord->name, name);
    newRecord->next = NULL;
    return newRecord;
}

// Hash function to determine the index
unsigned int hash(int id) {
    return id % TABLE_SIZE;
}

// Function to initialize the hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (Record**)calloc(TABLE_SIZE, sizeof(Record*));
    return ht;
}

// Function to insert a record into the hash table
void insertRecord(HashTable* ht, int id, const char* name) {
    unsigned int index = hash(id);
    Record* newRecord = createRecord(id, name);

    if (ht->table[index] == NULL) {
        ht->table[index] = newRecord;
    } else {
        Record* temp = ht->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRecord; // Handle collision by chaining
    }
}

// Function to search for a record by ID
Record* searchRecord(HashTable* ht, int id) {
    unsigned int index = hash(id);
    Record* current = ht->table[index];

    while (current != NULL) {
        if (current->id == id) {
            return current; // Record found
        }
        current = current->next; // Move to the next in the chain
    }
    return NULL; // Record not found
}

// Function to delete a record by ID
void deleteRecord(HashTable* ht, int id) {
    unsigned int index = hash(id);
    Record* current = ht->table[index];
    Record* previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                ht->table[index] = current->next; // Remove head
            } else {
                previous->next = current->next; // Bypass the current record
            }
            free(current); // Free the memory
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to free the hash table
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Record* current = ht->table[i];
        while (current != NULL) {
            Record* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

// Main function demonstrating the database index system
int main() {
    HashTable* ht = createHashTable();

    insertRecord(ht, 1, "Alice");
    insertRecord(ht, 2, "Bob");
    insertRecord(ht, 103, "Charlie"); // Collision with id 2
    insertRecord(ht, 4, "David");
    
    // Inquiry into the database
    printf("Searching for ID 2...\n");
    Record* result = searchRecord(ht, 2);
    if (result) {
        printf("Found: %s\n", result->name);
    } else {
        printf("Record not found.\n");
    }

    printf("Searching for ID 103...\n");
    result = searchRecord(ht, 103);
    if (result) {
        printf("Found: %s\n", result->name);
    } else {
        printf("Record not found.\n");
    }

    printf("Deleting record with ID 1...\n");
    deleteRecord(ht, 1);
    
    printf("Searching for ID 1...\n");
    result = searchRecord(ht, 1);
    if (result) {
        printf("Found: %s\n", result->name);
    } else {
        printf("Record not found.\n");
    }

    // Cleaning up
    freeHashTable(ht);
    return 0;
}