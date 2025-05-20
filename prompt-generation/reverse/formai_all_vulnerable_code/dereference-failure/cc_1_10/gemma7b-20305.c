//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define NUM_ENTRIES 10
#define MAX_NAME_LENGTH 20

typedef struct Entry {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Entry* next;
} Entry;

Entry* createEntry(char* name, int age) {
    Entry* newEntry = malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    newEntry->age = age;
    newEntry->next = NULL;
    return newEntry;
}

Entry* addToEntries(Entry* head, char* name, int age) {
    Entry* newEntry = createEntry(name, age);
    if (head == NULL) {
        head = newEntry;
    } else {
        Entry* currentEntry = head;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
    return head;
}

void printEntries(Entry* head) {
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("%s (age: %d)\n", currentEntry->name, currentEntry->age);
        currentEntry = currentEntry->next;
    }
}

int main() {
    Entry* head = NULL;

    // Seed the random number generator
    srand(time(NULL));

    // Create a bunch of fake entries
    for (int i = 0; i < NUM_ENTRIES; i++) {
        addToEntries(head, "John Doe", rand() % 100);
    }

    // Print the entries
    printEntries(head);

    return 0;
}