//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the hash table
#define HASH_SIZE 11

// Define the structure for a hash table entry
typedef struct {
    char name[100];
    char phone[20];
} HashEntry;

// Define the structure for the hash table
typedef struct {
    HashEntry entries[HASH_SIZE];
    int count;
} HashTable;

// Define the hash function to calculate the index for a given key
int hashFunction(char* key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = (hash << 2) ^ key[i];
    }
    return hash % size;
}

// Define the insert function to add an entry to the hash table
void insert(HashTable* table, char* name, char* phone) {
    int index = hashFunction(name, HASH_SIZE);
    HashEntry* entry = &(table->entries[index]);
    strcpy(entry->name, name);
    strcpy(entry->phone, phone);
    table->count++;
}

// Define the search function to find an entry in the hash table
int search(HashTable* table, char* name) {
    int index = hashFunction(name, HASH_SIZE);
    HashEntry* entry = &(table->entries[index]);
    if (strcmp(entry->name, name) == 0) {
        return 1;
    }
    return 0;
}

// Define the delete function to remove an entry from the hash table
void deleteEntry(HashTable* table, char* name) {
    int index = hashFunction(name, HASH_SIZE);
    HashEntry* entry = &(table->entries[index]);
    if (strcmp(entry->name, name) == 0) {
        strcpy(entry->name, "");
        strcpy(entry->phone, "");
        table->count--;
    }
}

// Define the print function to display the contents of the hash table
void printTable(HashTable* table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashEntry* entry = &(table->entries[i]);
        if (strcmp(entry->name, "")!= 0) {
            printf("%s - %s\n", entry->name, entry->phone);
        }
    }
}

// Define the main function
int main() {
    HashTable table;
    table.count = 0;

    // Insert entries into the hash table
    insert(&table, "Alice", "1234567890");
    insert(&table, "Bob", "0987654321");
    insert(&table, "Charlie", "5555555555");
    insert(&table, "David", "6666666666");

    // Search for entries in the hash table
    if (search(&table, "Alice")) {
        printf("Found Alice!\n");
    }
    else {
        printf("Alice not found.\n");
    }

    // Delete an entry from the hash table
    deleteEntry(&table, "David");

    // Print the contents of the hash table
    printTable(&table);

    // Free memory allocated to the hash table
    for (int i = 0; i < HASH_SIZE; i++) {
        if (strcmp(table.entries[i].name, "")!= 0) {
            free(table.entries[i].name);
        }
        if (strcmp(table.entries[i].phone, "")!= 0) {
            free(table.entries[i].phone);
        }
    }
    free(table.entries);

    return 0;
}