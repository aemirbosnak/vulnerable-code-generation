//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's create a simple database indexing system.

// First, we need a data structure to store our records.
typedef struct record {
    int id;
    char name[256];
    char email[256];
} record;

// Now, let's create a linked list to store our records.
typedef struct node {
    record data;
    struct node *next;
} node;

// And finally, let's create a hash table to store our indexes.
typedef struct hash_table {
    int size;
    node **buckets;
} hash_table;

// This function will create a new record.
record *create_record(int id, char *name, char *email) {
    record *new_record = malloc(sizeof(record));
    new_record->id = id;
    strcpy(new_record->name, name);
    strcpy(new_record->email, email);
    return new_record;
}

// This function will insert a record into the linked list.
void insert_record(node **head, record *new_record) {
    node *new_node = malloc(sizeof(node));
    new_node->data = *new_record;
    new_node->next = *head;
    *head = new_node;
}

// This function will create a new hash table.
hash_table *create_hash_table(int size) {
    hash_table *new_hash_table = malloc(sizeof(hash_table));
    new_hash_table->size = size;
    new_hash_table->buckets = malloc(sizeof(node *) * size);
    for (int i = 0; i < size; i++) {
        new_hash_table->buckets[i] = NULL;
    }
    return new_hash_table;
}

// This function will insert a record into the hash table.
void insert_hash(hash_table *hash_table, record *new_record) {
    int index = new_record->id % hash_table->size;
    insert_record(&hash_table->buckets[index], new_record);
}

// This function will search for a record in the linked list.
record *search_record(node *head, int id) {
    node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            return &current->data;
        }
        current = current->next;
    }
    return NULL;
}

// This function will search for a record in the hash table.
record *search_hash(hash_table *hash_table, int id) {
    int index = id % hash_table->size;
    return search_record(hash_table->buckets[index], id);
}

// This function will print the contents of the linked list.
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d %s %s\n", current->data.id, current->data.name, current->data.email);
        current = current->next;
    }
}

// This function will print the contents of the hash table.
void print_hash(hash_table *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        printf("Bucket %d: ", i);
        print_list(hash_table->buckets[i]);
    }
}

// Let's test our database indexing system.
int main() {
    // First, let's create a new record.
    record *new_record = create_record(1, "John Doe", "john.doe@example.com");

    // Now, let's insert the record into the linked list.
    node *head = NULL;
    insert_record(&head, new_record);

    // Next, let's create a new hash table.
    hash_table *hash_table = create_hash_table(10);

    // Finally, let's insert the record into the hash table.
    insert_hash(hash_table, new_record);

    // Now, let's search for the record in the linked list.
    record *found_record = search_record(head, 1);

    // And finally, let's search for the record in the hash table.
    record *found_hash = search_hash(hash_table, 1);

    // If the records are found, let's print them out.
    if (found_record != NULL) {
        printf("Found record in linked list: %d %s %s\n", found_record->id, found_record->name, found_record->email);
    }
    if (found_hash != NULL) {
        printf("Found record in hash table: %d %s %s\n", found_hash->id, found_hash->name, found_hash->email);
    }

    // Finally, let's print out the contents of the linked list and hash table.
    printf("Linked list:\n");
    print_list(head);
    printf("Hash table:\n");
    print_hash(hash_table);

    return 0;
}