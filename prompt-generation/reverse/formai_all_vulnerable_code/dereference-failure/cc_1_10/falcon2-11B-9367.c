//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure for a mailing list entry
typedef struct mailingList {
    char name[50];
    char email[100];
} MailingList;

// Define a structure for a mailing list
typedef struct mailingListManager {
    int size;
    MailingList *list;
} MailingListManager;

// Function to add a new entry to the mailing list
void addEntry(MailingListManager *manager, MailingList newEntry) {
    if (manager->size == 0) {
        manager->list = (MailingList *) malloc(sizeof(MailingList));
        *manager->list = newEntry;
        manager->size++;
    } else {
        MailingList *newList = (MailingList *) malloc(sizeof(MailingList));
        *newList = newEntry;
        manager->list = (MailingList *) realloc(manager->list, (manager->size + 1) * sizeof(MailingList));
        manager->list[manager->size] = *newList;
        manager->size++;
    }
}

// Function to remove an entry from the mailing list
void removeEntry(MailingListManager *manager, MailingList entry) {
    int index = -1;
    for (int i = 0; i < manager->size; i++) {
        if (strcmp(entry.name, manager->list[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index!= -1) {
        for (int i = index; i < manager->size - 1; i++) {
            manager->list[i] = manager->list[i + 1];
        }
        manager->size--;
    }
}

// Function to display the mailing list
void displayList(MailingListManager *manager) {
    for (int i = 0; i < manager->size; i++) {
        printf("%s - %s\n", manager->list[i].name, manager->list[i].email);
    }
}

int main() {
    MailingListManager manager;
    manager.size = 0;
    MailingList newEntry = { "John", "john@example.com" };
    addEntry(&manager, newEntry);
    displayList(&manager);
    removeEntry(&manager, newEntry);
    displayList(&manager);
    return 0;
}