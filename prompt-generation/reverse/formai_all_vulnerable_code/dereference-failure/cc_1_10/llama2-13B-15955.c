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
    if (d->current_entry == DIARY_SIZE) {
        printf("Diary is full! Delete some entries before adding more.\n");
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

    while (1) {
        printf("Enter date (mm/dd/yyyy): ");
        fgets(date, 20, stdin);
        printf("Enter entry: ");
        fgets(entry, ENTRY_SIZE, stdin);

        add_entry(d, date, entry);

        display_entries(d);

        printf("Add another entry? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'n') break;
    }

    free(d);
    return 0;
}