//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define HASH_TABLE_SIZE 31 // A prime number for better distribution
#define NAME_LENGTH 50

// Structure to store a student record
typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

// Node structure for the hash table to handle collisions
typedef struct Node {
    Record record;
    struct Node *next;
} Node;

// Hash table
Node *hashTable[HASH_TABLE_SIZE];

// Hash function to generate an index based on the record ID
unsigned int hash(int id) {
    return id % HASH_TABLE_SIZE;
}

// Function to create a new record
Record createRecord(int id, const char *name) {
    Record newRecord;
    newRecord.id = id;
    strncpy(newRecord.name, name, NAME_LENGTH - 1);
    newRecord.name[NAME_LENGTH - 1] = '\0'; // ensure null termination
    return newRecord;
}

// Function to insert a record into the hash table
void insertRecord(Record record) {
    unsigned int index = hash(record.id);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->record = record;
    newNode->next = NULL;

    // Collision handling via chaining
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node *temp = hashTable[index];
        while (temp->next != NULL) {
            // Check if the record ID already exists
            if (temp->record.id == record.id) {
                printf("Record with ID %d already exists.\n", record.id);
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Record with ID %d inserted successfully.\n", record.id);
}

// Function to search for a record by ID
Record *searchRecord(int id) {
    unsigned int index = hash(id);
    Node *temp = hashTable[index];

    while (temp != NULL) {
        if (temp->record.id == id) {
            return &(temp->record);
        }
        temp = temp->next;
    }
    return NULL; // Record not found
}

// Function to print all records in the hash table
void printAllRecords() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            Node *temp = hashTable[i];
            while (temp != NULL) {
                printf("ID: %d, Name: %s\n", temp->record.id, temp->record.name);
                temp = temp->next;
            }
        }
    }
}

// Function to free memory allocated for the hash table
void freeHashTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node *temp = hashTable[i];
        while (temp != NULL) {
            Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        hashTable[i] = NULL; // Clear the table entry
    }
}

// Main function to demonstrate the database indexing system
int main() {
    int choice, id;
    char name[NAME_LENGTH];
    Record *foundRecord;

    // Initialize the hash table
    memset(hashTable, 0, sizeof(hashTable));

    do {
        printf("\nDatabase Indexing System Menu\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Print All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name); // To read string with spaces
                insertRecord(createRecord(id, name));
                break;

            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                foundRecord = searchRecord(id);
                if (foundRecord) {
                    printf("Record found: ID: %d, Name: %s\n", foundRecord->id, foundRecord->name);
                } else {
                    printf("No record found with ID: %d\n", id);
                }
                break;

            case 3:
                printAllRecords();
                break;

            case 4:
                freeHashTable();
                printf("Exiting the program. All records cleared.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}