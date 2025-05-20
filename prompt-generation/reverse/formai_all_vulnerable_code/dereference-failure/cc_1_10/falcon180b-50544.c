//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, you can only have %d entries.\n", MAX_ENTRIES);
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("You have no entries yet.\n");
        return;
    }

    printf("Your entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void delete_entry(char* date) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            strcpy(entries[i].date, "");
            strcpy(entries[i].entry, "");

            num_entries--;

            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    srand(time(NULL));

    char date[20];
    sprintf(date, "%04d-%02d-%02d", rand() % 10000, rand() % 100, rand() % 100);
    add_entry(date, "Hello, world!");

    view_entries();

    delete_entry(date);

    view_entries();

    return 0;
}