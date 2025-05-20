//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIARY_SIZE 100
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
    memset(d, 0, sizeof(diary_t));
    strcpy(d->entries[0].date, "Today");
    strcpy(d->entries[0].entry, "No entry yet!");
    d->curr_entry = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    if (d->curr_entry == DIARY_SIZE - 1) {
        printf("Error: Diary is full! :(");
        return;
    }
    strcpy(d->entries[d->curr_entry].date, date);
    strcpy(d->entries[d->curr_entry].entry, entry);
    d->curr_entry++;
}

void display_diary(diary_t *d) {
    printf("--- DIARY ---\n");
    for (int i = 0; i < d->curr_entry; i++) {
        printf("%s: %s\n", d->entries[i].date, d->entries[i].entry);
    }
    printf("--- END OF DIARY ---\n");
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[] = "2022-01-01";
    char entry[] = "I woke up early today and had a nice breakfast!";

    add_entry(d, date, entry);

    display_diary(d);

    char new_entry[] = "I went to the park and played fetch with my dog!";
    add_entry(d, "2022-01-02", new_entry);

    display_diary(d);

    return 0;
}