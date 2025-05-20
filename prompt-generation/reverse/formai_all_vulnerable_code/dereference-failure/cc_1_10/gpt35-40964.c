//FormAI DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int key;    // unique identifier of record
    char name[50];  // name of the record
};

// define a node for the linked list of records
struct Node {
    struct Record record;
    struct Node* next;
};

// define a hash table to index the records
#define TABLE_SIZE 100
struct Node* table[TABLE_SIZE];

// function to calculate the hash value for a given key
int hash(int key) {
    return key % TABLE_SIZE;
}

// function to insert a new record into the hash table
void insert(struct Record record) {
    int index = hash(record.key);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->record = record;
    new_node->next = table[index];
    table[index] = new_node;
}

// function to search for a record by key
struct Record* search(int key) {
    int index = hash(key);
    struct Node* current = table[index];
    while (current) {
        if (current->record.key == key) {
            return &current->record;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    // initialize hash table to NULL pointers
    memset(table, 0, sizeof(table));

    // insert some test records
    insert((struct Record) {1, "Alice"});
    insert((struct Record) {2, "Bob"});
    insert((struct Record) {3, "Charlie"});
    insert((struct Record) {4, "David"});
    insert((struct Record) {5, "Eve"});

    // search for some records and print their names
    struct Record* alice = search(1);
    if (alice) {
        printf("Alice found with key = 1, name = %s\n", alice->name);
    } else {
        printf("Alice not found with key = 1\n");
    }
    struct Record* charlie = search(3);
    if (charlie) {
        printf("Charlie found with key = 3, name = %s\n", charlie->name);
    } else {
        printf("Charlie not found with key = 3\n");
    }
    struct Record* frank = search(6);
    if (frank) {
        printf("Frank found with key = 6, name = %s\n", frank->name);
    } else {
        printf("Frank not found with key = 6\n");
    }

    return 0;
}