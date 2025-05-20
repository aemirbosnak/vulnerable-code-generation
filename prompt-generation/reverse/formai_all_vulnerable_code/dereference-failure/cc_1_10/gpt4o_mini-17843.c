//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define MAX_RECORDS 100

typedef struct Record {
    int id;
    char name[NAME_LENGTH];
    struct Record *next;
} Record;

typedef struct IndexNode {
    int id;
    int index; // Position in the linked list
    struct IndexNode *next;
} IndexNode;

Record *head = NULL; // Head of the linked list
IndexNode *index_head = NULL; // Head of the index linked list
int record_count = 0;

// Function to add a record to the database
void add_record(int id, const char *name) {
    Record *new_record = (Record *)malloc(sizeof(Record));
    new_record->id = id;
    strncpy(new_record->name, name, NAME_LENGTH);
    new_record->next = head;
    head = new_record;

    // Insert into the index
    if (record_count < MAX_RECORDS) {
        IndexNode *new_index = (IndexNode *)malloc(sizeof(IndexNode));
        new_index->id = id;
        new_index->index = record_count;
        new_index->next = index_head;
        index_head = new_index;
        record_count++;
    } else {
        printf("Index capacity reached, cannot add more records\n");
    }
}

// Function to display all records
void display_records() {
    Record *current = head;
    printf("\nAll Records:\n");
    printf("ID\tName\n");
    while (current) {
        printf("%d\t%s\n", current->id, current->name);
        current = current->next;
    }
}

// Function to search for a record by index
void search_record(int id) {
    IndexNode *current_index = index_head;
    while (current_index) {
        if (current_index->id == id) {
            Record *current_record = head;
            for (int i = 0; i < current_index->index; i++) {
                current_record = current_record->next;
            }
            printf("\nRecord Found: ID: %d, Name: %s\n", current_record->id, current_record->name);
            return;
        }
        current_index = current_index->next;
    }
    printf("Record with ID %d not found\n", id);
}

// Function to free up memory
void free_memory() {
    // Free records
    Record *current_record = head;
    while (current_record) {
        Record *temp = current_record;
        current_record = current_record->next;
        free(temp);
    }

    // Free index
    IndexNode *current_index = index_head;
    while (current_index) {
        IndexNode *temp = current_index;
        current_index = current_index->next;
        free(temp);
    }
}

int main() {
    int choice, id;
    char name[NAME_LENGTH];
    
    do {
        printf("\nDatabase Indexing System Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                add_record(id, name);
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_record(id);
                break;
            case 4:
                printf("Exiting...\n");
                free_memory();
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (1);
    
    return 0;
}