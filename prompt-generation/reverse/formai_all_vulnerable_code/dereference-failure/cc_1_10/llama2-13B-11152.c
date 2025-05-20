//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 256

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_entry;
} diary_t;

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_entry = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (d->current_entry == i) {
            strcpy(d->entries[i].entry, entry);
            strcpy(d->entries[i].date, date);
            break;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Diary full! Sorry, no more entries can be added.\n");
    }
}

void view_entry(diary_t *d, int entry_num) {
    if (entry_num < 0 || entry_num >= DIARY_SIZE) {
        printf("Invalid entry number! Sorry, can't display that entry.\n");
        return;
    }
    printf("Entry %d: %s\n", entry_num + 1, d->entries[entry_num].entry);
    printf("Date: %s\n", d->entries[entry_num].date);
}

int main() {
    diary_t *d;
    char date[20];
    char entry[ENTRY_SIZE];

    // Initialize diary
    init_diary(&d);

    // Add some entries
    add_entry(d, "January 1st", "Happy New Year!");
    add_entry(d, "January 2nd", "Went to the beach.");
    add_entry(d, "January 3rd", "Learned a new language.");

    // View an entry
    view_entry(d, 2);

    // Add another entry
    add_entry(d, "January 4th", "Went to a party.");

    // View the last entry
    view_entry(d, DIARY_SIZE - 1);

    // Free memory
    free(d);

    return 0;
}