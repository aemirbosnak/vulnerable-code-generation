//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_MAX_ENTRIES 10
#define ENTRY_LENGTH 256

typedef struct {
    char date[20];
    char entry[ENTRY_LENGTH];
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

void add_entry(diary_t *d, char *date, char *entry) {
    if (d->current_entry >= DIARY_MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void display_entries(diary_t *d) {
    for (int i = 0; i < d->current_entry; i++) {
        printf("%s: %s\n", d->entries[i].date, d->entries[i].entry);
    }
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_LENGTH];

    while (1) {
        printf("Add entry for %s: ", date);
        fgets(entry, ENTRY_LENGTH, stdin);
        add_entry(d, date, entry);

        display_entries(d);

        printf("Do you want to add another entry? (y/n): ");
        char choice = getchar();
        if (choice == 'n') break;
    }

    free(d);
    return 0;
}