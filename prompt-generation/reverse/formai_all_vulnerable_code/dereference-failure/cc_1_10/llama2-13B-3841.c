//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char *title;
    char *entry;
    time_t date;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *title, char *entry) {
    entry_t *new_entry = (entry_t *)malloc(sizeof(entry_t));
    new_entry->title = title;
    new_entry->entry = entry;
    new_entry->date = time(NULL);
    if (num_entries < MAX_ENTRIES) {
        entries[num_entries] = *new_entry;
        num_entries++;
    } else {
        printf("Error: Maximum number of entries reached.\n");
    }
}

void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s - %s (%s)\n", entries[i].title, entries[i].entry, ctime(&entries[i].date));
    }
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    while (1) {
        char title[MAX_STRING_LENGTH];
        char entry[MAX_STRING_LENGTH];

        printf("Add entry: ");
        fgets(title, MAX_STRING_LENGTH, stdin);
        printf("Add entry: ");
        fgets(entry, MAX_STRING_LENGTH, stdin);

        add_entry(title, entry);

        display_entries();

        printf("Do you want to continue (y/n)? ");
        char ch = getchar();
        if (ch == 'n') break;
    }

    return 0;
}