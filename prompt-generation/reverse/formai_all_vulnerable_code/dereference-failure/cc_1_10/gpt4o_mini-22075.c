//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define INDEX_SIZE 10

typedef struct Record {
    int id;
    char name[NAME_LENGTH];
    struct Record* next;
} Record;

typedef struct Index {
    int id;
    Record* recordPtr;
} Index;

Record* head = NULL;
Index indexArray[INDEX_SIZE];
int currentIndex = 0;

Record* createRecord(int id, const char* name) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->id = id;
    strcpy(newRecord->name, name);
    newRecord->next = NULL;
    return newRecord;
}

void addRecord(int id, const char* name) {
    Record* newRecord = createRecord(id, name);
    
    if (head == NULL) {
        head = newRecord;
    } else {
        Record* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRecord;
    }
    
    if (currentIndex < INDEX_SIZE) {
        indexArray[currentIndex].id = id;
        indexArray[currentIndex].recordPtr = newRecord;
        currentIndex++;
    } else {
        printf("Index limit reached! Unable to add: %d, %s\n", id, name);
    }
}

void displayRecords() {
    Record* temp = head;
    printf("All Records:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

Record* searchRecordById(int id) {
    for (int i = 0; i < currentIndex; i++) {
        if (indexArray[i].id == id) {
            return indexArray[i].recordPtr;
        }
    }
    return NULL;
}

void deleteRecord(int id) {
    Record* temp = head;
    Record* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Record with ID %d not found!\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);

    // Remove from index
    for (int i = 0; i < currentIndex; i++) {
        if (indexArray[i].id == id) {
            indexArray[i] = indexArray[currentIndex - 1];
            currentIndex--;
            return;
        }
    }
}

void freeMemory() {
    Record* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int option, id;
    char name[NAME_LENGTH];

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Delete Record by ID\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addRecord(id, name);
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record* record = searchRecordById(id);
                if (record) {
                    printf("Found Record - ID: %d, Name: %s\n", record->id, record->name);
                } else {
                    printf("Record with ID %d not found!\n", id);
                }
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case 5:
                freeMemory();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}