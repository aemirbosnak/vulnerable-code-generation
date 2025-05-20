//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char name[20];
    int timestamp;
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = malloc(sizeof(Entry));
    scanf("%s", newEntry->name);
    scanf("%d", &newEntry->timestamp);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void printEntries(Entry* head) {
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("%s (%d) ", currentEntry->name, currentEntry->timestamp);
        currentEntry = currentEntry->next;
    }
    printf("\n");
}

int main() {
    Entry* head = NULL;

    printf("Enter 'add' to add an entry, 'print' to print entries:\n");
    char command;
    scanf(" %c", &command);

    switch (command) {
        case 'a':
            head = insertEntry(head);
            break;
        case 'p':
            printEntries(head);
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    return 0;
}