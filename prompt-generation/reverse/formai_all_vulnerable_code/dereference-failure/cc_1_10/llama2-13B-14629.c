//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 256

typedef struct {
    char date[10];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_entry;
} diary_t;

void init_diary(diary_t* d) {
    for (int i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_entry = 0;
}

void add_entry(diary_t* d, char* date, char* entry) {
    if (d->current_entry >= DIARY_SIZE) {
        printf("Oops, the diary is full! Maybe you should start a new one? :P\n");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void view_entry(diary_t* d, int entry_num) {
    if (entry_num < 0 || entry_num >= DIARY_SIZE) {
        printf("Invalid entry number! :P\n");
        return;
    }
    printf("--- %s ---\n", d->entries[entry_num].date);
    printf("%s\n", d->entries[entry_num].entry);
}

int main() {
    diary_t* d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[10];
    char entry[ENTRY_SIZE];

    while (1) {
        printf("What's the date today? ");
        scanf("%9s", date);
        add_entry(d, date, entry);

        printf("What's your entry for %s? ", date);
        scanf("%255s", entry);

        view_entry(d, d->current_entry - 1);
    }

    return 0;
}