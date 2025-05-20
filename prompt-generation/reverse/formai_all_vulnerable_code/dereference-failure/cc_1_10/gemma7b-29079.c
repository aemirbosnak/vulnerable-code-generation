//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char name[20];
    int age;
    char occupation[50];
    struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry(char* name, int age, char* occupation) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    newEntry->age = age;
    strcpy(newEntry->occupation, occupation);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        Entry* currentEntry = head;
        while (currentEntry->next != NULL) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
}

void printEntries() {
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("%s, %d, %s\n", currentEntry->name, currentEntry->age, currentEntry->occupation);
        currentEntry = currentEntry->next;
    }
}

int main() {
    addEntry("John Doe", 25, "Software Engineer");
    addEntry("Jane Doe", 30, "Nurse");
    addEntry("Peter Pan", 12, "Student");

    printEntries();

    return 0;
}