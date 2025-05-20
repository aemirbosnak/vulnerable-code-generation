//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: safe
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

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, " ");
        d->entries[i].entry[0] = '\0';
    }
    d->curr_entry = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (d->entries[i].date[0] == ' ') {
            strcpy(d->entries[i].date, date);
            strcpy(d->entries[i].entry, entry);
            break;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Diary is full, cannot add new entry\n");
        return;
    }
}

void view_entry(diary_t *d) {
    if (d->curr_entry < DIARY_SIZE) {
        printf("%s: %s\n", d->entries[d->curr_entry].date, d->entries[d->curr_entry].entry);
    } else {
        printf("No more entries\n");
    }
    d->curr_entry++;
}

int main() {
    diary_t *d;
    char date[20];
    char entry[ENTRY_SIZE];

    d = malloc(sizeof(diary_t));
    init_diary(d);

    while (1) {
        printf("Add new entry: ");
        fgets(date, 20, stdin);
        fgets(entry, ENTRY_SIZE, stdin);
        add_entry(d, date, entry);
        view_entry(d);
    }

    return 0;
}