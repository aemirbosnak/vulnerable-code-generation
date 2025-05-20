//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// This is a custom cryptographic hash function for strings, which uses a statistic-based approach.

#define HASH_SIZE 128 // Define the size of the hash table
#define PRIME_NUM 31 // Choose a prime number for hashing

// Declaration of the hash node struct
struct hash_node {
    char* key;
    int val;
    struct hash_node* next;
};

// Declaration of the hash table struct
struct hash_table {
    struct hash_node** entries;
};

// Function to create a new hash node
struct hash_node* create_node(char* key, int val) {
    struct hash_node* new_node = (struct hash_node*) malloc(sizeof(struct hash_node));
    new_node->key = malloc(strlen(key) + 1);
    strcpy(new_node->key, key);
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new hash table
struct hash_table* create_table() {
    struct hash_table* new_table = (struct hash_table*) malloc(sizeof(struct hash_table));
    new_table->entries = (struct hash_node**) malloc(sizeof(struct hash_node*) * HASH_SIZE);
    int i;
    for(i=0;i<HASH_SIZE;i++) {
        new_table->entries[i] = NULL;
    }
    return new_table;
}

// Function to compute the hash value for a given key
int hash(char* key) {
    int hash_val = 0;
    int i;
    int len = strlen(key);
    for(i=0;i<len;i++) {
        hash_val += key[i] * (PRIME_NUM^i);
    }
    return hash_val % HASH_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct hash_table* table, char* key, int val) {
    int hash_val = hash(key);
    struct hash_node* list = table->entries[hash_val];
    if(list==NULL) {
        table->entries[hash_val] = create_node(key, val);
        return;
    }
    struct hash_node* curr_node = list;
    while(curr_node!=NULL) {
        if(strcmp(curr_node->key, key)==0) {
            curr_node->val = val;
            return;
        }
        curr_node = curr_node->next;
    }
    struct hash_node* new_node = create_node(key, val);
    new_node->next = list;
    table->entries[hash_val] = new_node;
}

// Function to search for a key in the hash table and return the value associated with it
int search(struct hash_table* table, char* key) {
    int hash_val = hash(key);
    struct hash_node* list = table->entries[hash_val];
    if(list==NULL) {
        return -1; // key not found
    }
    struct hash_node* curr_node = list;
    while(curr_node!=NULL) {
        if(strcmp(curr_node->key, key)==0) {
            return curr_node->val;
        }
        curr_node = curr_node->next;
    }
    return -1; // key not found
}

// Function to delete a key-value pair from the hash table
void delete_node(struct hash_table* table, char* key) {
    int hash_val = hash(key);
    struct hash_node* list = table->entries[hash_val];
    if(list==NULL) {
        return;
    }
    struct hash_node* curr_node = list;
    struct hash_node* prev_node = NULL;
    while(curr_node!=NULL) {
        if(strcmp(curr_node->key, key)==0) {
            if(prev_node==NULL) {
                table->entries[hash_val] = curr_node->next;
            }
            else {
                prev_node->next = curr_node->next;
            }
            free(curr_node->key);
            free(curr_node);
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}

int main() {

    struct hash_table* table = create_table();
    insert(table, "apple", 5);
    insert(table, "banana", 7);
    insert(table, "cherry", 3);
    printf("The value for key 'banana' is: %d\n", search(table, "banana"));
    delete_node(table, "banana");
    printf("The value for key 'banana' is: %d\n", search(table, "banana"));
    return 0;

}