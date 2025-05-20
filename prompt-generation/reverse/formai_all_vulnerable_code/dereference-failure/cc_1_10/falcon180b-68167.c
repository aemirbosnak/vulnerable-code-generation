//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

void add_entry(diary_entry entries[], int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void display_entries(diary_entry entries[], int num_entries) {
    printf("Diary Entries:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;

    time_t now = time(NULL);
    struct tm* time_info = localtime(&now);

    char date[20];
    strftime(date, 20, "%d/%m/%Y", time_info);

    char input[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry for %s:\n", date);
    fgets(input, MAX_ENTRY_LENGTH, stdin);

    add_entry(entries, num_entries, date, input);
    display_entries(entries, num_entries);

    return 0;
}