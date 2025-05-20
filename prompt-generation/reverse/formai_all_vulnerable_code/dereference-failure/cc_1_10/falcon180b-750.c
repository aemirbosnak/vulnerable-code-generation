//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
        printf("Error: Maximum number of entries reached.\n");
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
    printf("Date\tEntry\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].date, entries[i].entry);
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
            printf("%s\t%s\n", entries[i].date, entries[i].entry);
        }
    }
}

void delete_entry(int index) {
    if (index >= num_entries || index < 0) {
        printf("Invalid entry index.\n");
        return;
    }
    num_entries--;
    for (int i = index; i < num_entries; i++) {
        strcpy(entries[i].date, entries[i+1].date);
        strcpy(entries[i].entry, entries[i+1].entry);
    }
}

int main() {
    srand(time(NULL));
    char date[20];
    sprintf(date, "%04d-%02d-%02d", rand() % 10000 + 1, rand() % 13 + 1, rand() % 28 + 1);
    add_entry(date, "Hello, world!");
    view_entries();
    search_entries("world");
    delete_entry(0);
    view_entries();
    return 0;
}