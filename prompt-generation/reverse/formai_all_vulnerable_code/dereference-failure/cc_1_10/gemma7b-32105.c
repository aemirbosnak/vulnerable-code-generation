//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 10

typedef struct HashTableEntry {
    char *key;
    int value;
    struct HashTableEntry *next;
} HashTableEntry;

void hash_table_insert(HashTableEntry **head, char *key, int value) {
    // Allocate a new entry
    HashTableEntry *new_entry = malloc(sizeof(HashTableEntry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = NULL;

    // Insert the entry into the hash table
    if (*head == NULL) {
        *head = new_entry;
    } else {
        (*head)->next = new_entry;
    }
}

int hash_table_search(HashTableEntry *head, char *key) {
    // Traverse the hash table
    for (HashTableEntry *entry = head; entry; entry = entry->next) {
        // Check if the key is equal to the current entry key
        if (strcmp(key, entry->key) == 0) {
            return entry->value;
        }
    }

    // Key not found
    return -1;
}

int main() {
    // Create a hash table
    HashTableEntry *password_table = NULL;

    // Insert passwords into the hash table
    hash_table_insert(&password_table, "strong_password", 10);
    hash_table_insert(&password_table, "weak_password", 2);
    hash_table_insert(&password_table, "very_weak_password", 3);

    // Check the strength of a password
    int password_strength = hash_table_search(password_table, "strong_password");

    // Print the password strength
    if (password_strength == 10) {
        printf("Password strength: Strong\n");
    } else if (password_strength == 2) {
        printf("Password strength: Weak\n");
    } else if (password_strength == 3) {
        printf("Password strength: Very Weak\n");
    } else {
        printf("Password not found\n");
    }

    return 0;
}