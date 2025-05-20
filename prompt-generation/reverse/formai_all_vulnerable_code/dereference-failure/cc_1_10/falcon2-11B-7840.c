//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash function for calculating the hash code for a given key
int hashFunction(char* key) {
    int hash = 0;
    int length = strlen(key);
    
    for (int i = 0; i < length; i++) {
        hash += key[i];
    }
    
    return hash % 10;
}

int main() {
    // Create an array of chars to store the records
    char records[100];
    
    // Create a hash table to store the records
    int hashTableSize = 10;
    int* hashTable = (int*) malloc(sizeof(int) * hashTableSize);
    memset(hashTable, 0, sizeof(int) * hashTableSize);
    
    // Add records to the hash table
    int recordCount = 0;
    char* key = "John";
    char* value = "Smith";
    char* key2 = "Jane";
    char* value2 = "Doe";
    char* key3 = "Bob";
    char* value3 = "Johnson";
    
    hashTable[hashFunction(key)] = recordCount;
    records[recordCount++] = key;
    records[recordCount++] = value;
    
    hashTable[hashFunction(key2)] = recordCount;
    records[recordCount++] = key2;
    records[recordCount++] = value2;
    
    hashTable[hashFunction(key3)] = recordCount;
    records[recordCount++] = key3;
    records[recordCount++] = value3;
    
    // Print the records in the hash table
    printf("Records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%s -> %s\n", records[i], records[i + 1]);
    }
    
    // Delete records from the hash table
    char* keyToDelete = "Jane";
    hashTable[hashFunction(keyToDelete)] = -1;
    int index = hashFunction(keyToDelete);
    for (int i = index; i < recordCount - 1; i++) {
        hashTable[i] = hashTable[i + 1];
    }
    recordCount--;
    
    // Print the updated records in the hash table
    printf("\nRecords after deletion:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%s -> %s\n", records[i], records[i + 1]);
    }
    
    // Search for records in the hash table
    char* searchKey = "John";
    int searchIndex = hashFunction(searchKey);
    for (int i = searchIndex; i < recordCount; i++) {
        if (strcmp(records[i], searchKey) == 0) {
            printf("%s -> %s\n", records[i], records[i + 1]);
            break;
        }
    }
    
    // Free the allocated memory
    free(hashTable);
    return 0;
}