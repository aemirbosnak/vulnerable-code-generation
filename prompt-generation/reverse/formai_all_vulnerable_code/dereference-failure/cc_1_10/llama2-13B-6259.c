//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 256

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int curr_entry;
} diary_t;

void init_diary(diary_t* d) {
    memset(d, 0, sizeof(diary_t));
    srand(time(NULL));
}

void add_entry(diary_t* d, const char* date, const char* entry) {
    if (d->curr_entry == DIARY_SIZE) {
        printf("Oops, the diary is full! 😱\n");
        return;
    }
    strcpy(d->entries[d->curr_entry].date, date);
    strcpy(d->entries[d->curr_entry].entry, entry);
    d->curr_entry++;
}

void view_entry(diary_t* d, int entry_num) {
    if (entry_num < 0 || entry_num >= d->curr_entry) {
        printf("Invalid entry number! 😳\n");
        return;
    }
    printf("Diary Entry %d:\n", entry_num + 1);
    printf("Date: %s\n", d->entries[entry_num].date);
    printf("Entry: %s\n", d->entries[entry_num].entry);
}

int main() {
    diary_t* d = malloc(sizeof(diary_t));
    init_diary(d);

    // Example usage
    add_entry(d, "Monday", "Woke up early and went for a run.");
    add_entry(d, "Tuesday", "Had a big meeting at work.");
    add_entry(d, "Wednesday", "Learned a new programming language.");

    // View all entries
    for (int i = 0; i < d->curr_entry; i++) {
        view_entry(d, i);
    }

    // View a specific entry
    view_entry(d, 1);

    return 0;
}