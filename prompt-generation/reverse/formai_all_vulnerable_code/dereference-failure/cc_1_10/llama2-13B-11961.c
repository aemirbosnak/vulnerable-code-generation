//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DAY_COUNT 30
#define MAX_ENTRIES 10

typedef struct {
    char day[10];
    char entry[50];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[MAX_ENTRIES];
    int current_day;
} diary_t;

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        strcpy(d->entries[i].day, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_day = 0;
}

void add_entry(diary_t *d, char *day, char *entry) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(d->entries[i].day, day) == 0) {
            strcpy(d->entries[i].entry, entry);
            break;
        }
    }
    if (i == MAX_ENTRIES) {
        printf("Error: Diary is full, cannot add new entry!\n");
    }
}

void view_entry(diary_t *d, int day) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(d->entries[i].day, day) == 0) {
            printf("%s: %s\n", d->entries[i].day, d->entries[i].entry);
            break;
        }
    }
    if (i == MAX_ENTRIES) {
        printf("Error: No entry found for day %d\n", day);
    }
}

void next_day(diary_t *d) {
    d->current_day++;
    if (d->current_day >= DAY_COUNT) {
        d->current_day = 0;
    }
}

int main() {
    diary_t *d = (diary_t *)malloc(sizeof(diary_t));
    init_diary(d);

    while (1) {
        printf("Enter day (1-30): ");
        scanf("%d", &d->current_day);
        view_entry(d, d->current_day);
        next_day(d);
    }

    return 0;
}