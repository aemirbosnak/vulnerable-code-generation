//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define HASH_TABLE_SIZE 37
#define MAX_STRING_LENGTH 50

typedef struct Record {
    int id;
    char name[MAX_STRING_LENGTH];
} Record;

typedef struct HashNode {
    Record *record;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode *nodes[HASH_TABLE_SIZE];
} HashTable;

HashTable *createHashTable() {
    HashTable *table = malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table->nodes[i] = NULL;
    }
    return table;
}

unsigned long hash(int id) {
    return id % HASH_TABLE_SIZE;
}

void insertRecord(HashTable *table, Record *record) {
    unsigned long index = hash(record->id);
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->record = record;
    newNode->next = table->nodes[index];
    table->nodes[index] = newNode;
}

Record *searchRecord(HashTable *table, int id) {
    unsigned long index = hash(id);
    HashNode *current = table->nodes[index];
    while (current != NULL) {
        if (current->record->id == id) {
            return current->record;
        }
        current = current->next;
    }
    return NULL;
}

void freeHashTable(HashTable *table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode *current = table->nodes[i];
        while (current != NULL) {
            HashNode *temp = current;
            current = current->next;
            free(temp->record);
            free(temp);
        }
    }
    free(table);
}

int main() {
    HashTable *dbIndex = createHashTable();
    Record *records[MAX_RECORDS];
    int recordCount = 0;

    char command[10];

    while (1) {
        printf("Enter command (add, search, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (recordCount >= MAX_RECORDS) {
                printf("Database is full. Cannot add more records.\n");
                continue;
            }
            Record *newRecord = malloc(sizeof(Record));
            printf("Enter record ID: ");
            scanf("%d", &newRecord->id);
            printf("Enter record name (max %d characters): ", MAX_STRING_LENGTH - 1);
            scanf("%s", newRecord->name);

            insertRecord(dbIndex, newRecord);
            records[recordCount++] = newRecord;
            printf("Record added.\n");
        } else if (strcmp(command, "search") == 0) {
            int idToSearch;
            printf("Enter record ID to search: ");
            scanf("%d", &idToSearch);
            Record *foundRecord = searchRecord(dbIndex, idToSearch);
            if (foundRecord) {
                printf("Record found: ID = %d, Name = %s\n", foundRecord->id, foundRecord->name);
            } else {
                printf("Record not found.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Please enter 'add', 'search', or 'exit'.\n");
        }
    }

    freeHashTable(dbIndex);
    printf("Exiting program. Database cleaned up successfully.\n");
    return 0;
}