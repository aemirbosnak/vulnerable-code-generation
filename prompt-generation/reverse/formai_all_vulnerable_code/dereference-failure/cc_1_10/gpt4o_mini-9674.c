//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define TABLE_SIZE 10

typedef struct Record {
    int id;
    char name[50];
} Record;

typedef struct HashNode {
    Record record;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[TABLE_SIZE];

unsigned int hashFunction(int id) {
    return id % TABLE_SIZE;
}

void insertRecord(Record record) {
    unsigned int index = hashFunction(record.id);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->record = record;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        HashNode* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

Record* retrieveRecord(int id) {
    unsigned int index = hashFunction(id);
    HashNode* current = hashTable[index];

    while (current != NULL) {
        if (current->record.id == id) {
            return &current->record;
        }
        current = current->next;
    }
    return NULL;
}

void displayRecords() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = hashTable[i];
        if (current) {
            printf("Index %d: ", i);
            while (current != NULL) {
                printf("ID: %d, Name: %s -> ", current->record.id, current->record.name);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = hashTable[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    int choice;
    Record record;

    while (1) {
        printf("\n=== Database Indexing System ===\n");
        printf("1. Add Record\n");
        printf("2. Retrieve Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (MAX_RECORDS > 0) {
                    printf("Enter ID: ");
                    scanf("%d", &record.id);
                    printf("Enter Name: ");
                    scanf("%s", record.name);
                    insertRecord(record);
                    printf("Record added successfully!\n");
                } else {
                    printf("Database limit reached!\n");
                }
                break;
            case 2:
                printf("Enter ID to retrieve: ");
                scanf("%d", &record.id);
                Record* retrievedRecord = retrieveRecord(record.id);
                if (retrievedRecord) {
                    printf("Record Found: ID: %d, Name: %s\n", retrievedRecord->id, retrievedRecord->name);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                freeHashTable();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}