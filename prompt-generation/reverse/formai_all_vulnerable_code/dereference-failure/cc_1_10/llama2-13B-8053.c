//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIARY_MAX_ENTRIES 100
#define ENTRY_MAX_LENGTH 256

typedef struct {
    char date[20];
    char entry[ENTRY_MAX_LENGTH];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_MAX_ENTRIES];
    int current_entry;
} diary_t;

void init_diary(diary_t *d) {
    for (int i = 0; i < DIARY_MAX_ENTRIES; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_entry = 0;
}

void add_entry(diary_t *d, const char *date, const char *entry) {
    if (d->current_entry == DIARY_MAX_ENTRIES) {
        printf("Diary is full, cannot add new entry\n");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void view_entry(diary_t *d, int entry_num) {
    if (entry_num < 0 || entry_num >= DIARY_MAX_ENTRIES) {
        printf("Invalid entry number\n");
        return;
    }
    printf("Entry %d: %s\n", entry_num + 1, d->entries[entry_num].entry);
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    // Example usage
    add_entry(d, "January 1st", "Woke up early and went for a run.");
    add_entry(d, "January 2nd", "Had a productive day at work.");
    view_entry(d, 1);

    // User input
    char date[20];
    char entry[ENTRY_MAX_LENGTH];
    printf("Enter a date (e.g. 'January 3rd'): ");
    fgets(date, 20, stdin);
    printf("Enter an entry (e.g. 'Went to the movies'): ");
    fgets(entry, ENTRY_MAX_LENGTH, stdin);
    add_entry(d, date, entry);

    // Clean up
    free(d);
    return 0;
}