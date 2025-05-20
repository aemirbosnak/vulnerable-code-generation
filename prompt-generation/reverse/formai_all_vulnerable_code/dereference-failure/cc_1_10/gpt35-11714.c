//FormAI DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    char name[50];
    struct Node* next;
} Node;

Node* create_node(int key, char name[]) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

void insert_to_list(Node** head, int key, char name[]) {
    Node* new_node = create_node(key, name);
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("Key: %d, Name: %s\n", current->key, current->name);
        current = current->next;
    }
}

void index_database(Node** index, int key, char name[]) {
    int index_key = key % 5;
    insert_to_list(&index[index_key], key, name);
}

void search_by_key(Node** index, int key) {
    int index_key = key % 5;
    Node* current = index[index_key];
    while(current != NULL && current->key != key) {
        current = current->next;
    }
    if(current == NULL) {
        printf("No record found with key %d\n", key);
    } else {
        printf("Record found with key %d, Name: %s\n", current->key, current->name);
    }
}

int main() {
    // initialize index
    Node* index[5];
    for(int i = 0; i < 5; i++) {
        index[i] = NULL;
    }

    // insert records
    index_database(index, 12345, "John Doe");
    index_database(index, 54321, "Jane Smith");
    index_database(index, 67890, "Bob Johnson");
    index_database(index, 45678, "Alice Williams");
    index_database(index, 90123, "Tom Wilson");

    // search for records
    search_by_key(index, 12345);
    search_by_key(index, 54321);
    search_by_key(index, 67890);
    search_by_key(index, 45678);
    search_by_key(index, 90123);

    // print all records in the index
    for(int i = 0; i < 5; i++) {
        printf("Index %d:\n", i);
        print_list(index[i]);
    }

    return 0;
}