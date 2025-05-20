//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define REHASH_FACTOR 2

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record *table;
    int size;
    int count;
} HashTable;

HashTable* create_table(int size) {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = size;
    ht->count = 0;
    ht->table = malloc(sizeof(Record) * size);
    
    for (int i = 0; i < size; i++) {
        ht->table[i].id = -1; // Initialize with -1 to denote empty slots
    }
    
    return ht;
}

int hash(int id, int size) {
    return id % size;
}

void resize_table(HashTable *ht);
void insert_record(HashTable *ht, int id, const char *name);
Record* search_record(HashTable *ht, int id);
void delete_record(HashTable *ht, int id);
void print_table(HashTable *ht);
void free_table(HashTable *ht);

int main() {
    HashTable *ht = create_table(10);
    
    printf("Welcome to the Database Indexing System!\n");
    int choice, id;
    char name[MAX_NAME_LENGTH];
    
    do {
        printf("\nChoose an action:\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Print Table\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insert_record(ht, id, name);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record *record = search_record(ht, id);
                if (record != NULL) {
                    printf("Record Found - ID: %d, Name: %s\n", record->id, record->name);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_record(ht, id);
                break;
            case 4:
                print_table(ht);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    free_table(ht);
    printf("Goodbye!\n");
    return 0;
}

void insert_record(HashTable *ht, int id, const char *name) {
    if (ht->count >= ht->size * REHASH_FACTOR / 100) {
        resize_table(ht);
    }
    
    int index = hash(id, ht->size);
    while (ht->table[index].id != -1) {
        if (ht->table[index].id == id) {
            printf("Error: Record with ID %d already exists!\n", id);
            return;
        }
        index = (index + 1) % ht->size;
    }

    ht->table[index].id = id;
    strncpy(ht->table[index].name, name, MAX_NAME_LENGTH);
    ht->count++;
    printf("Record with ID %d inserted successfully!\n", id);
}

Record* search_record(HashTable *ht, int id) {
    int index = hash(id, ht->size);
    while (ht->table[index].id != -1) {
        if (ht->table[index].id == id) {
            return &ht->table[index];
        }
        index = (index + 1) % ht->size;
    }
    return NULL; // Record not found
}

void delete_record(HashTable *ht, int id) {
    int index = hash(id, ht->size);
    while (ht->table[index].id != -1) {
        if (ht->table[index].id == id) {
            ht->table[index].id = -1; // Mark as deleted
            ht->count--;
            printf("Record with ID %d deleted successfully!\n", id);
            return;
        }
        index = (index + 1) % ht->size;
    }
    printf("Error: Record with ID %d not found!\n", id);
}

void print_table(HashTable *ht) {
    printf("\nCurrent Records in the Hash Table:\n");
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i].id != -1) {
            printf("Index %d: ID = %d, Name = %s\n", i, ht->table[i].id, ht->table[i].name);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

void resize_table(HashTable *ht) {
    int newSize = ht->size * 2;
    Record *oldTable = ht->table;
    ht->table = malloc(sizeof(Record) * newSize);
    
    for (int i = 0; i < newSize; i++) {
        ht->table[i].id = -1; // Initialize new slots
    }
    
    ht->size = newSize;
    ht->count = 0;

    for (int i = 0; i < (ht->size / 2); i++) {
        if (oldTable[i].id != -1) {
            insert_record(ht, oldTable[i].id, oldTable[i].name);
        }
    }
    
    free(oldTable);
    printf("Table resized! New size: %d\n", newSize);
}

void free_table(HashTable *ht) {
    free(ht->table);
    free(ht);
}