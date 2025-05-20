//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void add_entry(Entry* entries, int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached!\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void display_entries(Entry* entries, int num_entries) {
    printf("Digital Diary Entries:\n");
    printf("------------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char date[11];

    strftime(date, 11, "%Y-%m-%d", tm);

    add_entry(entries, num_entries, date, "Started my digital diary today! ");
    add_entry(entries, num_entries, date, "Feeling excited to start this new journey.");

    display_entries(entries, num_entries);

    return 0;
}