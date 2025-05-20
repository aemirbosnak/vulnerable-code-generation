//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Record* next;
} Record;

Record* head = NULL;

void addRecord(int id, const char* name) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->id = id;
    strncpy(newRecord->name, name, MAX_NAME_LENGTH - 1);
    newRecord->name[MAX_NAME_LENGTH - 1] = '\0';
    newRecord->next = head;
    head = newRecord;
    printf("Record added: ID=%d, Name=%s\n", id, name);
}

void deleteRecord(int id) {
    Record* current = head;
    Record* previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) { 
                head = current->next;
            } else {
                previous->next = current->next;
            }
            printf("Record deleted: ID=%d, Name=%s\n", current->id, current->name);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Record with ID=%d not found\n", id);
}

void findRecord(int id) {
    Record* current = head;

    while (current != NULL) {
        if (current->id == id) {
            printf("Record found: ID=%d, Name=%s\n", current->id, current->name);
            return;
        }
        current = current->next;
    }
    printf("Record with ID=%d not found\n", id);
}

void printAllRecords() {
    if (head == NULL) {
        printf("No records found!\n");
        return;
    }

    Record* current = head;
    printf("All Records:\n");
    while (current != NULL) {
        printf("ID=%d, Name=%s\n", current->id, current->name);
        current = current->next;
    }
}

void cleanup() {
    Record* current = head;
    Record* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}

int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\n=== Simple Database Indexing System ===\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Find Record\n");
        printf("4. Print All Records\n");
        printf("5. Exit\n");
        printf("=========================================\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                getchar(); // to consume newline
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                addRecord(id, name);
                break;

            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;

            case 3:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                findRecord(id);
                break;

            case 4:
                printAllRecords();
                break;

            case 5:
                cleanup();
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}