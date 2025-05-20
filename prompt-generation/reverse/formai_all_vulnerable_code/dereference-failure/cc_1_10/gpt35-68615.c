//FormAI DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

//Creating the structure of the record
typedef struct Record {
    int id;
    char name[50];
    int age;
} Record;

//Creating the node structure for the linked list
typedef struct Node {
    Record *record;
    struct Node *next;
} Node;

//Creating the hash table structure
typedef struct HashTable {
    Node **array;
    int size;
} HashTable;

//Creating the function that creates a new record
Record* create_record(int id, char name[], int age) {
    //Allocating memory for the record
    Record *record = (Record*)malloc(sizeof(Record));
    //Initializing the record fields
    record->id = id;
    strcpy(record->name, name);
    record->age = age;

    return record;
}

//Creating the function that creates a new node
Node* create_node(Record* record) {
    //Allocating memory for the node
    Node *node = (Node*)malloc(sizeof(Node));
    //Initializing the node fields
    node->record = record;
    node->next = NULL;

    return node;
}

//Creating the function that inserts a record into the hash table
void insert_record(HashTable *hash_table, Record *record) {
    //Calculating the index of the array where the record should be inserted
    int index = record->id % hash_table->size;

    //Creating a new node for the record
    Node *node = create_node(record);

    //Inserting the node at the front of the linked list at the index
    node->next = hash_table->array[index];
    hash_table->array[index] = node;
}

//Creating the function that searches for a record in the hash table
Record* search_record(HashTable *hash_table, int id) {
    //Calculating the index of the array where the record should be searched
    int index = id % hash_table->size;

    //Traversing the linked list at the index to find the record
    Node *current_node = hash_table->array[index];
    while (current_node != NULL) {
        if (current_node->record->id == id) {
            return current_node->record;
        }
        current_node = current_node->next;
    }

    return NULL;
}

//Creating the function that deletes a record from the hash table
void delete_record(HashTable *hash_table, int id) {
    //Calculating the index of the array where the record should be deleted
    int index = id % hash_table->size;

    //Checking if the linked list at the index is empty
    if (hash_table->array[index] == NULL) {
        printf("Record not found\n");
        return;
    }

    //Checking if the first node in the linked list at the index is the record to be deleted
    if (hash_table->array[index]->record->id == id) {
        Node *temp_node = hash_table->array[index];
        hash_table->array[index] = hash_table->array[index]->next;
        free(temp_node->record);
        free(temp_node);
        printf("Record deleted successfully\n");
        return;
    }

    //Traversing the linked list at the index to find the record to be deleted
    Node *previous_node = hash_table->array[index];
    Node *current_node = hash_table->array[index]->next;
    while (current_node != NULL) {
        if (current_node->record->id == id) {
            previous_node->next = current_node->next;
            free(current_node->record);
            free(current_node);
            printf("Record deleted successfully\n");
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Record not found\n");
}

int main() {
    //Creating the hash table and initializing its fields
    HashTable hash_table;
    int size = 10;
    hash_table.array = (Node**)malloc(size * sizeof(Node*));
    hash_table.size = size;
    for (int i = 0; i < size; i++) {
        hash_table.array[i] = NULL;
    }

    //Creating and inserting some records into the hash table
    Record *record1 = create_record(12345, "John Doe", 25);
    Record *record2 = create_record(67890, "Alice Smith", 32);
    Record *record3 = create_record(13579, "Bob Johnson", 45);
    insert_record(&hash_table, record1);
    insert_record(&hash_table, record2);
    insert_record(&hash_table, record3);

    //Searching and deleting a record from the hash table
    Record *found_record = search_record(&hash_table, 12345);
    if (found_record != NULL) {
        printf("Record found: %s\n", found_record->name);
        delete_record(&hash_table, 12345);
    }
    else {
        printf("Record not found\n");
    }

    return 0;
}