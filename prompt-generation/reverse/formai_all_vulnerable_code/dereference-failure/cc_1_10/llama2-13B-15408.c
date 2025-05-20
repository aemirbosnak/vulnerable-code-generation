//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: brave
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
        printf("Diary is full!:\n");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void view_entry(diary_t *d, int entry_num) {
    if (entry_num < 0 || entry_num >= DIARY_SIZE) {
        printf("Invalid entry number!:\n");
        return;
    }
    printf("Entry %d: %s\n", entry_num + 1, d->entries[entry_num].entry);
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[] = "2023-02-20";
    char entry[] = "Went to the beach with friends!";

    add_entry(d, date, entry);

    view_entry(d, 1);

    free(d);

    return 0;
}