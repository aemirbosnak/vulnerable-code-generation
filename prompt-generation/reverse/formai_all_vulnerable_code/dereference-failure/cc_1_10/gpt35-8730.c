//FormAI DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 1000 // size of hash table
#define MAX_STRING_LEN 100 // maximum length of string

typedef struct Record {
    int id; // id of the record
    char name[MAX_STRING_LEN]; // name of the record
    char address[MAX_STRING_LEN]; // address of the record
    struct Record* next; // pointer to next record
} Record;

Record* hashTable[HASH_TABLE_SIZE]; // hash table

/*
    Generates the hash value of a given string
*/
int hash(char* str) {
    int hash = 0;
    for (int i = 0; i < strlen(str); i++) {
        hash += str[i];
    }
    return hash % HASH_TABLE_SIZE;
}

/*
    Searches for a record with the given id in the hash table
*/
Record* search(int id) {
    int hashValue = id % HASH_TABLE_SIZE;
    Record* recordPtr = hashTable[hashValue];
    while (recordPtr != NULL) {
        if (recordPtr->id == id) {
            return recordPtr;
        }
        recordPtr = recordPtr->next;
    }
    return NULL;
}

/*
    Inserts a new record into the hash table
*/
void insert(int id, char* name, char* address) {
    Record* recordPtr = search(id);
    if (recordPtr != NULL) {
        printf("Record with id %d already exists\n", id);
        return;
    }
    int hashValue = id % HASH_TABLE_SIZE;
    Record* newRecord = (Record*) malloc(sizeof(Record));
    newRecord->id = id;
    strcpy(newRecord->name, name);
    strcpy(newRecord->address, address);
    newRecord->next = hashTable[hashValue];
    hashTable[hashValue] = newRecord;
}

/*
    Prints the contents of the hash table
*/
void printHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Record* recordPtr = hashTable[i];
        while (recordPtr != NULL) {
            printf("[%d] %d: %s, %s\n", i, recordPtr->id, recordPtr->name, recordPtr->address);
            recordPtr = recordPtr->next;
        }
    }
}

int main() {
    insert(101, "John Doe", "123 Main St");
    insert(102, "Jane Smith", "456 Elm St");
    insert(103, "Bob Johnson", "789 Oak St");
    printHashTable();
    Record* johnRecord = search(101);
    printf("Record found: %d, %s, %s\n", johnRecord->id, johnRecord->name, johnRecord->address);
    Record* nonExistentRecord = search(104);
    if (nonExistentRecord != NULL) {
        printf("This should not be printed\n");
    }
    return 0;
}