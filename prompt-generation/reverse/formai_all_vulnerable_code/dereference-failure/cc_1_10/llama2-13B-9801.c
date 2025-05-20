//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define DAY_SIZE 32

typedef struct {
    char date[32];
    char entry[100];
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
        printf("Error: Diary is full.\n");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void view_entry(diary_t *d, int day) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (strcmp(d->entries[i].date, "") == 0) {
            continue;
        }
        if (strcmp(d->entries[i].date, day) == 0) {
            printf("%s\n", d->entries[i].entry);
            return;
        }
    }
    printf("Error: No entry found for %s\n", day);
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[32];
    char entry[100];

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        fgets(date, 32, stdin);
        date[31] = '\0';

        printf("Enter entry: ");
        fgets(entry, 100, stdin);
        entry[99] = '\0';

        add_entry(d, date, entry);

        view_entry(d, date);
    }

    return 0;
}