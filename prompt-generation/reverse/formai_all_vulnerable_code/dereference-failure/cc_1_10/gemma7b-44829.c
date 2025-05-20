//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char name[20];
    char number[20];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    printf("Enter name: ");
    scanf("%s", newEntry->name);
    printf("Enter number: ");
    scanf("%s", newEntry->number);

    newEntry->next = head;
    head = newEntry;

    return head;
}

void searchEntry(Entry* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Number: %s\n", head->number);
            return;
        }
        head = head->next;
    }

    printf("Entry not found.\n");
}

int main() {
    Entry* head = NULL;

    // Insert entries
    head = insertEntry(head);
    insertEntry(head);
    insertEntry(head);

    // Search for an entry
    searchEntry(head, "John Doe");

    return 0;
}