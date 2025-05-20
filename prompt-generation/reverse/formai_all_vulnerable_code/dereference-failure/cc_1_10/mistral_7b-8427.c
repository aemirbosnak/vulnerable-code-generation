//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 101
#define RECORD_SIZE 100

typedef struct {
    int key;
    char data[RECORD_SIZE];
    struct Node* next;
} Record;

typedef struct Node {
    Record record;
    struct Node* next;
} Node;

Node** hash_table;

void init_hash_table() {
    int i;
    hash_table = (Node**) calloc(TABLE_SIZE, sizeof(Node*));
    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void add_record(int key, char* data) {
    Record new_record = {key, {0}, NULL};
    strncpy(new_record.data, data, RECORD_SIZE);
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->record = new_record;

    int hash_index = hash_function(key);
    new_node->next = hash_table[hash_index];
    hash_table[hash_index] = new_node;
}

bool search_record(int key, char* buffer, int buffer_size) {
    int hash_index = hash_function(key);
    Node* current = hash_table[hash_index];

    while (current != NULL) {
        if (current->record.key == key) {
            strncpy(buffer, current->record.data, buffer_size);
            return true;
        }
        current = current->next;
    }

    return false;
}

void remove_record(int key) {
    int hash_index = hash_function(key);
    Node** current = &hash_table[hash_index];

    while (*current != NULL && (*current)->record.key != key) {
        current = &((*current)->next);
    }

    if (*current == NULL) {
        printf("Record not found.\n");
        return;
    }

    Node* temp = *current;
    *current = (*current)->next;
    free(temp);
}

int main() {
    init_hash_table();

    add_record(1, "John Doe, 25, New York");
    add_record(2, "Jane Smith, 30, Los Angeles");
    add_record(3, "Mike Johnson, 22, Chicago");

    char data[RECORD_SIZE];

    printf("Searching for record with key 2:\n");
    if (search_record(2, data, RECORD_SIZE)) {
        printf("%s\n", data);
    } else {
        printf("Record not found.\n");
    }

    printf("Searching for record with key 4:\n");
    search_record(4, data, RECORD_SIZE); // This will print "Record not found."

    printf("Removing record with key 1:\n");
    remove_record(1);

    printf("Searching for record with key 1 after removal:\n");
    search_record(1, data, RECORD_SIZE); // This will print "Record not found."

    return 0;
}