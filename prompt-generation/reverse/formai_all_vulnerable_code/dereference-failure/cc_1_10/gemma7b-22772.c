//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char name[20];
    char number[20];
    struct Entry* next;
} Entry;

Entry* insert(Entry* head, char* name, char* number) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        Entry* traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newEntry;
    }

    return head;
}

void search(Entry* head, char* name) {
    Entry* traverse = head;
    while (traverse) {
        if (strcmp(traverse->name, name) == 0) {
            printf("Name: %s, Number: %s\n", traverse->name, traverse->number);
            return;
        }
        traverse = traverse->next;
    }

    printf("No entry found for name: %s\n", name);
}

int main() {
    Entry* head = NULL;
    head = insert(head, "John Doe", "123-45-678");
    head = insert(head, "Jane Doe", "456-78-901");
    head = insert(head, "Peter Pan", "555-12-345");

    search(head, "John Doe");
    search(head, "Jane Doe");
    search(head, "Peter Pan");
    search(head, "Mary Poppins");

    return 0;
}