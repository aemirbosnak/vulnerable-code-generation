//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Entry {
    char name[MAX_NAME_LENGTH];
    char entry[1000];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));

    printf("Enter name: ");
    scanf("%s", newEntry->name);

    printf("Enter entry: ");
    scanf("%[^\n]%*c", newEntry->entry);

    newEntry->next = head;
    head = newEntry;

    return head;
}

void displayEntries(Entry* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Entry: %s\n", head->entry);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Entry* head = NULL;

    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("Enter 1 to insert an entry, 2 to display entries, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertEntry(head);
                break;
            case 2:
                displayEntries(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}