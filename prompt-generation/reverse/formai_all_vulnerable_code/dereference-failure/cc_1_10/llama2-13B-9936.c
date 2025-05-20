//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define MAX_ENTRIES 10

typedef struct {
    char date[20];
    char entry[100];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[MAX_ENTRIES];
    int count;
} diary_t;

void init_diary(diary_t *d) {
    memset(d, 0, sizeof(diary_t));
}

void add_entry(diary_t *d, const char *date, const char *entry) {
    int i;
    for (i = 0; i < d->count; i++) {
        if (strcmp(d->entries[i].date, date) == 0) {
            // Entry already exists, just update the entry
            strcpy(d->entries[i].entry, entry);
            return;
        }
    }
    // Entry does not exist, add a new one
    d->entries[d->count++] = (diary_entry_t) {
        .date = date,
        .entry = entry
    };
}

void print_diary(diary_t *d) {
    int i;
    for (i = 0; i < d->count; i++) {
        printf("%s: %s\n", d->entries[i].date, d->entries[i].entry);
    }
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    add_entry(d, "2023-02-28", "Went to the park");
    add_entry(d, "2023-03-01", "Visited a museum");
    add_entry(d, "2023-03-02", "Went shopping");

    print_diary(d);

    free(d);
    return 0;
}