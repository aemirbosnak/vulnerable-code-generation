//FormAI DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct representing a record in the database */
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

/* Struct representing a node in the linked list */
typedef struct Node {
    Record record;
    struct Node* next;
} Node;

/* Struct representing the entire linked list */
typedef struct {
    Node* head;
} LinkedList;

/* Function to create a new record */
Record create_record(int id, char* name, int age) {
    Record record;
    record.id = id;
    strcpy(record.name, name);
    record.age = age;
    return record;
}

/* Function to create a new node with a given record */
Node* create_node(Record record) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->record = record;
    node->next = NULL;
    return node;
}

/* Function to insert a record into the linked list */
void insert_record(LinkedList* list, Record record) {
    Node* node = create_node(record);
    
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

/* Function to print all records in the linked list */
void print_records(LinkedList list) {
    Node* curr = list.head;
    while (curr != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n",
                curr->record.id, curr->record.name, curr->record.age);
        curr = curr->next;
    }
}

/* Function to search for a record by ID in the linked list */
Record search_by_id(LinkedList list, int id) {
    Node* curr = list.head;
    while (curr != NULL) {
        if (curr->record.id == id) {
            return curr->record;
        }
        curr = curr->next;
    }
    /* If record is not found, return a record with ID -1 */
    Record not_found = create_record(-1, "Not Found", -1);
    return not_found;
}

/* Function to create a hash value for a given ID */
int hash(int id) {
    return id % 10;
}

/* Struct representing a hash table with separate chaining */
typedef struct {
    LinkedList lists[10];
} HashTable;

/* Function to insert a record into the hash table */
void insert_hash(HashTable* hash_table, Record record) {
    int index = hash(record.id);
    LinkedList list = hash_table->lists[index];
    insert_record(&list, record);
    hash_table->lists[index] = list;
}

/* Function to search for a record by ID in the hash table */
Record search_hash(HashTable hash_table, int id) {
    int index = hash(id);
    LinkedList list = hash_table.lists[index];
    return search_by_id(list, id);
}

int main() {
    /* Create a new hash table */
    HashTable hash_table;
    for (int i = 0; i < 10; i++) {
        LinkedList list = {NULL};
        hash_table.lists[i] = list;
    }
    
    /* Insert some records into the hash table */
    Record record1 = create_record(1234, "John Smith", 25);
    Record record2 = create_record(5678, "Jane Doe", 30);
    Record record3 = create_record(9012, "Bob Johnson", 40);
    insert_hash(&hash_table, record1);
    insert_hash(&hash_table, record2);
    insert_hash(&hash_table, record3);
    
    /* Search for a record by ID */
    Record found_record = search_hash(hash_table, 5678);
    printf("Found record:\n");
    printf("ID: %d, Name: %s, Age: %d\n",
            found_record.id, found_record.name, found_record.age);
    
    return 0;
}