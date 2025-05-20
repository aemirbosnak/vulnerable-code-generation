//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definition of a node in the database
struct node {
    int key;   // Key of the record
    char value[50]; // Value of the record
    struct node* next; // Next node in the linked list
};

// Definition of the database
struct db {
    struct node* head; // Head of the linked list
    int size; // Size of the database
};

// Function to insert a record into the database
void insert(struct db* db, int key, char value[]) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = db->head;
    db->head = new_node;
    db->size++;
}

// Function to search for a record in the database
struct node* search(struct db* db, int key) {
    struct node* current = db->head;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a record from the database
void delete(struct db* db, int key) {
    struct node* current = db->head;
    struct node* previous = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (previous == NULL) {
                db->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            db->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print all records in the database
void print(struct db* db) {
    struct node* current = db->head;
    while (current != NULL) {
        printf("%d: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    srand(time(NULL)); // For random key generation
    struct db* db = (struct db*) malloc(sizeof(struct db));
    db->head = NULL;
    db->size = 0;

    // Insert some records into the database
    insert(db, 1, "apple");
    insert(db, 2, "banana");
    insert(db, 3, "cherry");

    // Search for a record in the database
    struct node* found = search(db, 2);
    if (found != NULL) {
        printf("Found record with key %d and value %s\n", found->key, found->value);
    } else {
        printf("Record not found\n");
    }

    // Delete a record from the database
    delete(db, 3);

    // Print all records in the database
    print(db);

    return 0;
}