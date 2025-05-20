//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Entry {
    char name[MAX_SIZE];
    char date[MAX_SIZE];
    char description[MAX_SIZE];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->next = NULL;

    printf("Enter name: ");
    scanf("%s", newEntry->name);

    printf("Enter date: ");
    scanf("%s", newEntry->date);

    printf("Enter description: ");
    scanf("%s", newEntry->description);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void displayEntries(Entry* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Description: %s\n", head->description);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Entry* head = NULL;

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
                printf("Invalid choice.\n");
        }
    }

    return 0;
}