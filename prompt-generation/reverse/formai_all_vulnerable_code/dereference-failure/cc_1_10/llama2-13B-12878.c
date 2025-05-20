//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DIARY_SIZE 1024
#define ENTRY_SIZE 256

typedef struct {
    char date[16];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int curr_entry;
} diary_t;

void init_diary(diary_t* d) {
    for (int i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->curr_entry = 0;
}

void add_entry(diary_t* d, char* date, char* entry) {
    if (d->curr_entry >= DIARY_SIZE) {
        printf("Error: Diary is full\n");
        return;
    }
    strcpy(d->entries[d->curr_entry].date, date);
    strcpy(d->entries[d->curr_entry].entry, entry);
    d->curr_entry++;
}

void display_entry(diary_t* d) {
    printf("Diary Entry %d\n", d->curr_entry);
    printf("Date: %s\n", d->entries[d->curr_entry - 1].date);
    printf("Entry: %s\n", d->entries[d->curr_entry - 1].entry);
}

int main() {
    diary_t* d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[256];
    char entry[256];

    printf("Enter date (mm/dd/yyyy): ");
    fgets(date, 256, stdin);
    printf("Enter entry: ");
    fgets(entry, 256, stdin);

    add_entry(d, date, entry);
    display_entry(d);

    return 0;
}