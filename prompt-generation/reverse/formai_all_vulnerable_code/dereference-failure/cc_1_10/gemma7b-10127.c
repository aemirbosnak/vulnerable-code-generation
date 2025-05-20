//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char title[255];
    char content[255];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->next = NULL;

    printf("Enter title: ");
    scanf("%s", newEntry->title);

    printf("Enter content: ");
    scanf("%s", newEntry->content);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void displayEntries(Entry* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Content: %s\n", head->content);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Entry* head = NULL;

    // Insert entries
    insertEntry(head);
    insertEntry(head);
    insertEntry(head);

    // Display entries
    displayEntries(head);

    return 0;
}