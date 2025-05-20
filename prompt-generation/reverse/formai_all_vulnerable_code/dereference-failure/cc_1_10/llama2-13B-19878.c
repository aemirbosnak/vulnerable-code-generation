//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1024
#define ENTRY_SIZE 256

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int num_entries;
} diary_t;

void init_diary(diary_t *d) {
    for (int i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->num_entries = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    if (d->num_entries == DIARY_SIZE) {
        printf("Diary is full, cannot add new entry\n");
        return;
    }
    strcpy(d->entries[d->num_entries].date, date);
    strcpy(d->entries[d->num_entries].entry, entry);
    d->num_entries++;
}

void print_diary(diary_t *d) {
    for (int i = 0; i < d->num_entries; i++) {
        printf("%s - %s\n", d->entries[i].date, d->entries[i].entry);
    }
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    // Add some entries
    add_entry(d, "2023-02-01", "Went to the park");
    add_entry(d, "2023-02-02", "Did grocery shopping");
    add_entry(d, "2023-02-03", "Cooked dinner for my family");

    // Print the diary
    print_diary(d);

    free(d);
    return 0;
}