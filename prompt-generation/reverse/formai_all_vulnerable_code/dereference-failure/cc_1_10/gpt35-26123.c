//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the maximum size of a key
#define MAX_KEY_SIZE 50

// Define a structure for a database record
typedef struct record {
    char key[MAX_KEY_SIZE];
    int data;
    struct record* next;
} Record;

// Define a function to calculate the hash value for a given key
int hash(char* key) {
    int hash_val = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash_val += key[i];
    }
    return hash_val;
}

// Define a function to add a record to the database
void add_record(Record** hash_table, char* key, int data) {
    // Calculate the hash value for the key
    int hash_val = hash(key);
    
    // Create a new record and add it to the hash table
    Record* new_record = (Record*)malloc(sizeof(Record));
    strcpy(new_record->key, key);
    new_record->data = data;
    new_record->next = hash_table[hash_val];
    hash_table[hash_val] = new_record;
}

// Define a function to search for a record in the database
int search_record(Record** hash_table, char* key) {
    // Calculate the hash value for the key
    int hash_val = hash(key);
    
    // Traverse the linked list at the hash table index until the key is found
    Record* current = hash_table[hash_val];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->data;
        }
        current = current->next;
    }
    
    // Return -1 if the key was not found
    return -1;
}

// Define a function to print the entire contents of the database
void print_database(Record** hash_table) {
    // Loop through each index in the hash table and print the linked list at each index
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        Record* current = hash_table[i];
        printf("Index %d:\n", i);
        while (current != NULL) {
            printf("%s: %d\n", current->key, current->data);
            current = current->next;
        }
    }
}

int main() {
    // Allocate space for the hash table
    Record** hash_table = (Record**)malloc(MAX_KEY_SIZE * sizeof(Record*));
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        hash_table[i] = NULL;
    }
    
    // Add some sample records to the database
    add_record(hash_table, "John Smith", 1234);
    add_record(hash_table, "Jane Doe", 5678);
    add_record(hash_table, "Bob Johnson", 9012);
    
    // Search for a record in the database
    int result = search_record(hash_table, "Jane Doe");
    if (result != -1) {
        printf("Jane Doe's data is %d\n", result);
    } else {
        printf("Jane Doe was not found\n");
    }
    
    // Print the entire contents of the database
    printf("Database contents:\n");
    print_database(hash_table);
    
    return 0;
}