//FormAI DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This is a C database indexing system example program that allows you to store, search and retrieve 
 * data using index. The data is stored in a binary file on disk and indexed using a hash table. 
 * The hash function used is simple XOR based. The program provides command-line interface to 
 * add, delete, search and display records in the database.
 */

// Define maximum length of name and address fields
#define NAME_LENGTH 30
#define ADDRESS_LENGTH 100

// Define database record structure
struct Record {
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
    int index;      // index in the hash table
};

// Define hash table structure
struct HashTable {
    int size;       // size of the table
    struct Record** data;   // a 2D array to store pointers to records
};

// A hash function to calculate the hash value of a string
int hash(char* str, int size) {
    int i, sum = 0;
    for (i = 0; str[i]; i++) {
        sum ^= str[i];
    }
    return sum % size;
}

/**
 * Function to initialize the hash table
 */
struct HashTable* initHashTable(int size) {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
    if (!table) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    table->size = size;
    table->data = (struct Record**)calloc(size, sizeof(struct Record*));
    if (!table->data) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    return table;
}

/**
 * Function to free memory used by hash table
 */
void freeHashTable(struct HashTable* table) {
    int i;
    for (i = 0; i < table->size; i++) {
        if (table->data[i]) {
            free(table->data[i]);
        }
    }
    free(table->data);
    free(table);
}

/**
 * Function to add a record to the database
 */
void addRecord(char* name, char* address, struct HashTable* table) {
    struct Record* record = (struct Record*)malloc(sizeof(struct Record));
    if (!record) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    strncpy(record->name, name, NAME_LENGTH);
    strncpy(record->address, address, ADDRESS_LENGTH);
    record->index = hash(name, table->size);
    if (table->data[record->index]) {
        printf("Collision detected, unable to add record.\n");
        free(record);
        return;
    }
    table->data[record->index] = record;
    printf("Record added successfully with index: %d\n", record->index);
}

/**
 * Function to delete a record from the database
 */
void deleteRecord(char* name, struct HashTable* table) {
    int index = hash(name, table->size);
    struct Record* record = table->data[index];
    if (!record) {
        printf("Record not found.\n");
        return;
    }
    if (strcmp(record->name, name) != 0) {
        printf("Record not found.\n");
        return;
    }
    free(record);
    table->data[index] = NULL;
    printf("Record deleted successfully.\n");
}

/**
 * Function to search a record in the database
 */
void searchRecord(char* name, struct HashTable* table) {
    int index = hash(name, table->size);
    struct Record* record = table->data[index];
    if (!record) {
        printf("Record not found.\n");
        return;
    }
    if (strcmp(record->name, name) != 0) {
        printf("Record not found.\n");
        return;
    }
    printf("Record found with index: %d\n", record->index);
    printf("Name: %s\n", record->name);
    printf("Address: %s\n", record->address);
}

/**
 * Function to display all records in the database
 */
void displayRecords(struct HashTable* table) {
    int i;
    for (i = 0; i < table->size; i++) {
        if (table->data[i]) {
            printf("Index: %d\n", table->data[i]->index);
            printf("Name: %s\n", table->data[i]->name);
            printf("Address: %s\n", table->data[i]->address);
            printf("\n");
        }
    }
}

/**
 * Main function to test the database indexing system
 */
int main() {
    struct HashTable* table = initHashTable(100);
    addRecord("John", "123 Main St", table);
    addRecord("Bob", "456 Oak St", table);
    addRecord("Alice", "789 Elm St", table);
    printf("\n");
    displayRecords(table);
    printf("\n");
    searchRecord("Bob", table);
    searchRecord("Mary", table);
    printf("\n");
    deleteRecord("John", table);
    deleteRecord("Mary", table);
    printf("\n");
    displayRecords(table);
    freeHashTable(table);
    return 0;
}