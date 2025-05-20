//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: complete
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
    for (i = 0; i < DIARY_SIZE; i++) {
        if (d->current_entry == DIARY_SIZE) {
            printf("Diary full! Please delete some entries before adding more.\n");
            return;
        }
        if (strcmp(d->entries[i].date, date) == 0) {
            strcpy(d->entries[i].entry, entry);
            return;
        }
    }
    d->current_entry++;
    strcpy(d->entries[d->current_entry - 1].date, date);
    strcpy(d->entries[d->current_entry - 1].entry, entry);
}

void view_entry(diary_t *d, int entry_num) {
    printf("Entry %d: %s\n", entry_num, d->entries[entry_num].entry);
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    while (1) {
        printf("Enter date (mm/dd/yyyy): ");
        fgets(date, 20, stdin);
        printf("Enter entry: ");
        fgets(entry, ENTRY_SIZE, stdin);

        add_entry(d, date, entry);

        view_entry(d, d->current_entry - 1);
    }

    return 0;
}