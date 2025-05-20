//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100

// A structure to represent a database
struct Database {
    char *keys[MAX_KEYS];   // Array of keys
    int values[MAX_KEYS];   // Array of values
    int size;               // Size of the database
};

// A structure to represent an index
struct Index {
    char *key;              // Key of the index
    int value;              // Value of the index
};

// A function to create a new database
struct Database* createDatabase() {
    struct Database *db = (struct Database*)malloc(sizeof(struct Database));
    db->size = 0;
    return db;
}

// A function to add a key-value pair to the database
void addKeyValue(struct Database *db, char *key, int value) {
    // Check if the key already exists
    for(int i=0;i<db->size;i++) {
        if(strcmp(db->keys[i], key) == 0) {
            db->values[i] = value;
            return;
        }
    }
    
    // If the key does not exist, add it to the database
    db->keys[db->size] = strdup(key);
    db->values[db->size] = value;
    db->size++;
}

// A function to find a value by a key in the database
int findValue(struct Database *db, char *key) {
    for(int i=0;i<db->size;i++) {
        if(strcmp(db->keys[i], key) == 0) {
            return db->values[i];
        }
    }
    
    // If the key does not exist, return -1
    return -1;
}

// A function to create an index array of the given database
struct Index* createIndex(struct Database *db) {
    struct Index *index = (struct Index*)malloc(sizeof(struct Index) * db->size);
    for(int i=0;i<db->size;i++) {
        index[i].key = db->keys[i];
        index[i].value = db->values[i];
    }
    return index;
}

// A function to sort an index array by key
void sortIndex(struct Index *index, int size) {
    // Bubble sort algorithm
    for(int i=0;i<size-1;i++) {
        for(int j=0;j<size-i-1;j++) {
            if(strcmp(index[j].key, index[j+1].key) > 0) {
                // Swap the elements
                struct Index temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }
        }
    }
}

// A function to print the database
void printDatabase(struct Database *db) {
    for(int i=0;i<db->size;i++) {
        printf("%s -> %d\n", db->keys[i], db->values[i]);
    }
}

// A function to print the index
void printIndex(struct Index *index, int size) {
    for(int i=0;i<size;i++) {
        printf("%s -> %d\n", index[i].key, index[i].value);
    }
}

int main() {
    // Create a new database
    struct Database *db = createDatabase();
    
    // Add some key-value pairs to the database
    addKeyValue(db, "John", 51);
    addKeyValue(db, "Sarah", 27);
    addKeyValue(db, "Peter", 35);
    addKeyValue(db, "Emily", 18);
    addKeyValue(db, "Samuel", 42);
    
    // Print the database
    printf("Original database:\n");
    printDatabase(db);
    
    // Create an index of the database
    struct Index *index = createIndex(db);
    
    // Sort the index by key
    sortIndex(index, db->size);
    
    // Print the sorted index
    printf("Sorted index:\n");
    printIndex(index, db->size);
    
    // Find a value by a key in the database
    printf("Value of Peter: %d\n", findValue(db, "Peter"));
    
    // Free the memory
    for(int i=0;i<db->size;i++) {
        free(db->keys[i]);
    }
    free(db);
    free(index);
    
    return 0;
}