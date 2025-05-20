//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIARY_SIZE 5000
#define ENTRY_SIZE 100

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int cur_entry;
} diary_t;

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->cur_entry = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    int i;
    if (d->cur_entry == DIARY_SIZE - 1) {
        printf("Diary is full! Deleting oldest entry...\n");
        strcpy(d->entries[0].date, "");
        strcpy(d->entries[0].entry, "");
        d->cur_entry = 0;
    }
    strcpy(d->entries[d->cur_entry].date, date);
    strcpy(d->entries[d->cur_entry].entry, entry);
    d->cur_entry++;
}

void view_entry(diary_t *d, int index) {
    printf("Diary Entry %d (%s)\n", index, d->entries[index].date);
    printf("%s\n", d->entries[index].entry);
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    while (1) {
        printf("Enter date (mm/dd/yy): ");
        scanf("%19s", date);
        printf("Enter entry: ");
        scanf("%49s", entry);

        add_entry(d, date, entry);

        view_entry(d, d->cur_entry - 1);

        printf("Do you want to add another entry? (y/n): ");
        char ch = getchar();
        if (ch == 'n') break;
    }

    free(d);
    return 0;
}