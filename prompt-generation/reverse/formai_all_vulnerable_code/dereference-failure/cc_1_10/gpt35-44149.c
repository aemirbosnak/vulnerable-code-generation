//FormAI DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the record
typedef struct Record {
    int id;
    char name[20];
    char phone[20];
    char address[50];
} Record;

// Define the structure of the node in the array
typedef struct Node {
    Record* record;
    struct Node* next;
} Node;

// Define the array of nodes (simulating a hash table)
Node* nodeArray[100];

// Define the hashing function
int hash(int id) {
    return id % 100;
}

// Define the function to add a record to the database
void addRecord(Record* record) {
    // Calculate the index of the node in the array
    int index = hash(record->id);
    
    // Allocate memory for the new node
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    // Initialize the new node
    newNode->record = record;
    newNode->next = NULL;
    
    // Add the new node to the beginning of the list
    if (nodeArray[index] == NULL) {
        nodeArray[index] = newNode;
    } else {
        newNode->next = nodeArray[index];
        nodeArray[index] = newNode;
    }
}

// Define the function to search for a record by id
Record* searchRecord(int id) {
    // Calculate the index of the node in the array
    int index = hash(id);
    
    // Traverse the list looking for the record
    Node* currentNode = nodeArray[index];
    while (currentNode != NULL) {
        if (currentNode->record->id == id) {
            return currentNode->record;
        }
        currentNode = currentNode->next;
    }
    
    // Return NULL if the record is not found
    return NULL;
}

// Define the main function
int main() {
    // Initialize the array of nodes
    memset(nodeArray, 0, sizeof(nodeArray));
    
    // Add some records to the database
    Record* record1 = (Record*) malloc(sizeof(Record));
    record1->id = 123;
    strcpy(record1->name, "John Smith");
    strcpy(record1->phone, "555-1234");
    strcpy(record1->address, "123 Main St.");
    addRecord(record1);
    
    Record* record2 = (Record*) malloc(sizeof(Record));
    record2->id = 456;
    strcpy(record2->name, "Jane Doe");
    strcpy(record2->phone, "555-5678");
    strcpy(record2->address, "456 Oak St.");
    addRecord(record2);
    
    // Search for a record by id
    Record* foundRecord = searchRecord(123);
    printf("Record found: id=%d, name=%s, phone=%s, address=%s\n", foundRecord->id, foundRecord->name, foundRecord->phone, foundRecord->address);
    
    // Free the memory for the records and nodes
    free(record1);
    free(record2);
    free(nodeArray[0]);
    free(nodeArray[1]);
    
    return 0;
}