//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 500
#define ENTRY_SIZE 200

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
    if (d->current_entry >= DIARY_SIZE) {
        printf("Diary is full! :(");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void display_entries(diary_t *d) {
    int i;
    for (i = 0; i < d->current_entry; i++) {
        printf("%s - %s\n", d->entries[i].date, d->entries[i].entry);
    }
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    // Add some entries
    add_entry(d, "January 1st", "Woke up early and went for a run");
    add_entry(d, "January 2nd", "Had a productive day at work");
    add_entry(d, "January 3rd", "Went out with friends for dinner and drinks");

    // Display the entries
    display_entries(d);

    return 0;
}