//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char title[50];
    char content[200];
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

    while (1) {
        int choice;

        printf("1. Insert Entry\n");
        printf("2. Display Entries\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertEntry(head);
                break;
            case 2:
                displayEntries(head);
                break;
            default:
                exit(1);
        }
    }

    return 0;
}