//FormAI DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {  //structure to store each data item
    int key;
    char value[50];
    struct node* next;
} node;

typedef struct hashtable {  //structure hash table, containing an array of pointers to nodes
    int size;
    struct node** table;
} hashtable;

node* create_node(int key, char* value) {  //function to create and initialize a new node
    node* new_node = (node*)malloc(sizeof(node));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = NULL;
    return new_node;
}

hashtable* create_table(int size) {  //function to create and initialize a new hash table
    hashtable* new_table = (hashtable*)malloc(sizeof(hashtable));
    new_table->size = size;
    new_table->table = (node**)malloc(size * sizeof(node*));  //dynamically allocating space for array of pointers to nodes
    for (int i = 0; i < size; i++) {
        new_table->table[i] = NULL;
    }
    return new_table;
}

int hash(int key, int size) {  //function to calculate hash value
    return key % size;
}

void insert(hashtable* table, int key, char* value) {  //function to insert data into the hash table
    int index = hash(key, table->size);
    node* new_node = create_node(key, value);
    if (table->table[index] == NULL) {  //if there is no collision, insert new node at the index
        table->table[index] = new_node;
    }
    else {  //if there is a collision, insert new node at the end of the linked list at the index
        node* current = table->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void search(hashtable* table, int key) {  //function to search for data in the hash table
    int index = hash(key, table->size);
    node* current = table->table[index];
    while (current != NULL) {
        if (current->key == key) {  //if key matches, print value
            printf("Value for key %d: %s\n", key, current->value);
            return;
        }
        current = current->next;
    }
    printf("Key not found in table.\n");  //if key is not found
}

int main() {
    hashtable* table = create_table(100);  //create a table with size 100
    insert(table, 1, "apple");
    insert(table, 2, "banana");
    insert(table, 101, "orange");  //testing for collision
    insert(table, 102, "grape");
    search(table, 1);
    search(table, 101);
    search(table, 50);  //testing for non-existent key
    return 0;
}