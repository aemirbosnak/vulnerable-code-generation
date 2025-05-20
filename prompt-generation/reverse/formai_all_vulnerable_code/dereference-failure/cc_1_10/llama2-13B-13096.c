//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: detailed
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
    int current_index;
} diary_t;

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_index = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (d->current_index == DIARY_SIZE - 1) {
            printf("Diary is full, cannot add new entry\n");
            return;
        }
        if (strcmp(d->entries[i].date, date) == 0) {
            strcpy(d->entries[i].entry, entry);
            return;
        }
    }
    // Not found, add new entry
    strcpy(d->entries[d->current_index].date, date);
    strcpy(d->entries[d->current_index].entry, entry);
    d->current_index++;
}

void display_diary(diary_t *d) {
    int i;
    for (i = 0; i < d->current_index; i++) {
        printf("%s: %s\n", d->entries[i].date, d->entries[i].entry);
    }
}

int main() {
    diary_t *d;
    char date[20];
    char entry[ENTRY_SIZE];

    // Initialize diary
    init_diary(&d);

    // Add entries
    add_entry(d, "2023-02-14", "Went to the park");
    add_entry(d, "2023-02-15", "Met a new friend");
    add_entry(d, "2023-02-16", "Learned a new skill");

    // Display diary
    display_diary(d);

    return 0;
}