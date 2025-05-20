//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ENTRIES 1000

typedef struct Entry {
    char name[50];
    int age;
    struct Entry* next;
} Entry;

pthread_t tid;

Entry* head = NULL;

void insertEntry(char* name, int age) {
    Entry* newEntry = malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    newEntry->age = age;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        Entry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEntry;
    }
}

void searchEntry(char* name) {
    Entry* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s, Age: %d\n", current->name, current->age);
            return;
        }
        current = current->next;
    }
    printf("Entry not found.\n");
}

void deleteEntry(char* name) {
    Entry* current = head;
    Entry* previous = NULL;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Entry not found.\n");
}

int main() {
    insertEntry("John Doe", 30);
    insertEntry("Jane Doe", 25);
    insertEntry("Peter Pan", 12);

    searchEntry("Jane Doe");
    deleteEntry("Peter Pan");

    searchEntry("Jane Doe");

    return 0;
}