//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void addEntry(Entry entries[], int numEntries, char* date, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        exit(1);
    }

    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].entry, entry);

    numEntries++;
}

void viewEntries(Entry entries[], int numEntries) {
    printf("Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntries(Entry entries[], int numEntries, char* searchTerm) {
    int matches = 0;

    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, searchTerm)!= NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

void deleteEntry(Entry entries[], int numEntries, char* date) {
    int found = 0;

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            found = 1;
            for (int j = i; j < numEntries - 1; j++) {
                strcpy(entries[j].date, entries[j+1].date);
                strcpy(entries[j].entry, entries[j+1].entry);
            }
            numEntries--;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    time_t now = time(NULL);
    struct tm* currentTime = localtime(&now);
    char date[20];
    strftime(date, 20, "%Y-%m-%d", currentTime);

    addEntry(entries, numEntries, date, "First entry");
    addEntry(entries, numEntries, date, "Second entry");

    viewEntries(entries, numEntries);

    searchEntries(entries, numEntries, "entry");

    deleteEntry(entries, numEntries, "2022-02-22");

    viewEntries(entries, numEntries);

    return 0;
}