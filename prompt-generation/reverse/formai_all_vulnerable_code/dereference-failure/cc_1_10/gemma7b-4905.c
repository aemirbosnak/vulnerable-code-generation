//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[50];
    char address[100];
    char phone[20];
    struct Record* next;
} Record;

Record* insertRecord(Record* head, char* name, char* address, char* phone) {
    Record* newNode = (Record*)malloc(sizeof(Record));
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void searchRecord(Record* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Address: %s\n", head->address);
            printf("Phone: %s\n", head->phone);
            return;
        }
        head = head->next;
    }

    printf("Record not found.\n");
}

int main() {
    Record* head = NULL;

    // Insert some records
    insertRecord(head, "Sherlock Holmes", "221B Baker St.", "12345");
    insertRecord(head, "John Watson", "221B Baker St.", "45678");
    insertRecord(head, "Dr. Watson", "221B Baker St.", "98426");

    // Search for a record
    searchRecord(head, "John Watson");

    return 0;
}