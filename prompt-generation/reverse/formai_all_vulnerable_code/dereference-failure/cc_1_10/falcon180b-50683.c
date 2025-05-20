//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Search results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s - %s\n", entries[i].date, entries[i].entry);
        }
    }
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index.\n");
        return;
    }

    for (int i = index; i < num_entries - 1; i++) {
        strcpy(entries[i].date, entries[i+1].date);
        strcpy(entries[i].entry, entries[i+1].entry);
    }

    num_entries--;
}

int main() {
    srand(time(NULL));

    char* date = (char*)malloc(20 * sizeof(char));
    sprintf(date, "%04d-%02d-%02d", rand() % 10000 + 1, rand() % 13 + 1, rand() % 32 + 1);

    char* entry = (char*)malloc(MAX_ENTRY_LENGTH * sizeof(char));
    sprintf(entry, "Dear Diary, today was a great day!");

    add_entry(date, entry);

    view_entries();

    search_entries("great");

    delete_entry(0);

    view_entries();

    free(date);
    free(entry);

    return 0;
}