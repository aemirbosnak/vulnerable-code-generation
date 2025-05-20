//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define NAME_LENGTH 50

typedef struct User {
    int userID;
    char name[NAME_LENGTH];
    int age;
    struct User* next;
} User;

typedef struct HashTable {
    User* table[TABLE_SIZE];
} HashTable;

// Hash function to convert userID to an index
int hashFunction(int userID) {
    return userID % TABLE_SIZE;
}

// Create a new user node
User* createUser(int userID, const char* name, int age) {
    User* newUser = (User*)malloc(sizeof(User));
    newUser->userID = userID;
    strncpy(newUser->name, name, NAME_LENGTH);
    newUser->age = age;
    newUser->next = NULL;
    return newUser;
}

// Initialize the hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert user into hash table
void insertUser(HashTable* ht, int userID, const char* name, int age) {
    int index = hashFunction(userID);
    User* newUser = createUser(userID, name, age);
    newUser->next = ht->table[index]; // Insert at the beginning
    ht->table[index] = newUser;
}

// Search for a user by userID
User* searchUser(HashTable* ht, int userID) {
    int index = hashFunction(userID);
    User* current = ht->table[index];
    while (current != NULL) {
        if (current->userID == userID) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}

// Display all users in the hash table
void displayUsers(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        User* current = ht->table[i];
        if (current != NULL) {
            printf("Index %d:\n", i);
            while (current != NULL) {
                printf("  UserID: %d, Name: %s, Age: %d\n", current->userID, current->name, current->age);
                current = current->next;
            }
        }
    }
}

// Free the memory associated with the hash table
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        User* current = ht->table[i];
        while (current != NULL) {
            User* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}

int main() {
    HashTable* ht = createHashTable();
    
    // Let's insert some users
    insertUser(ht, 1, "Alice", 30);
    insertUser(ht, 2, "Bob", 25);
    insertUser(ht, 11, "Charlie", 35); // This will collide with userID 1
    insertUser(ht, 12, "David", 29);   // This will collide with userID 2

    // Display all users
    displayUsers(ht);

    // Search for users
    for (int i = 1; i <= 12; i++) {
        User* user = searchUser(ht, i);
        if (user != NULL) {
            printf("Found User: UserID: %d, Name: %s, Age: %d\n", user->userID, user->name, user->age);
        } else {
            printf("UserID %d not found.\n", i);
        }
    }

    // Free allocated memory
    freeHashTable(ht);
    return 0;
}