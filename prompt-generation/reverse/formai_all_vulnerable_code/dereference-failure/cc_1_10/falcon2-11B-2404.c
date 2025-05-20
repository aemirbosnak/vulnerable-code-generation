//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Record {
    int key;
    int value;
    struct Record* next;
};

struct Record* createRecord(int key, int value) {
    struct Record* newRecord = (struct Record*)malloc(sizeof(struct Record));
    newRecord->key = key;
    newRecord->value = value;
    newRecord->next = NULL;
    return newRecord;
}

void insertRecord(struct Record** head, int key, int value) {
    struct Record* newRecord = createRecord(key, value);
    if (*head == NULL) {
        *head = newRecord;
        return;
    }
    struct Record* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newRecord;
}

int searchRecord(struct Record** head, int key) {
    struct Record* current = *head;
    while (current!= NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

int main() {
    struct Record* head = NULL;
    insertRecord(&head, 1, "apple");
    insertRecord(&head, 2, "banana");
    insertRecord(&head, 3, "orange");

    printf("Search Record with key 2: %d\n", searchRecord(&head, 2));
    printf("Search Record with key 4: %d\n", searchRecord(&head, 4));

    return 0;
}