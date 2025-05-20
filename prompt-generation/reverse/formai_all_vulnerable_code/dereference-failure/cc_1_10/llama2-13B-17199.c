//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: genius
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
    int current_index;
} diary_t;

void init_diary(diary_t* d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_index = 0;
}

void add_entry(diary_t* d, char* date, char* entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (d->current_index == DIARY_SIZE - 1) {
            // If the diary is full, wrap around to the beginning
            d->current_index = 0;
        }
        if (strcmp(d->entries[d->current_index].date, date) > 0) {
            // Find the first empty slot after the current index
            break;
        }
        d->current_index++;
    }
    strcpy(d->entries[d->current_index].date, date);
    strcpy(d->entries[d->current_index].entry, entry);
}

void display_entry(diary_t* d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        printf("%d - %s\n", i + 1, d->entries[i].entry);
    }
}

int main() {
    diary_t* d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    // Add some entries
    add_entry(d, "January 1st", "New Year's Day");
    add_entry(d, "January 2nd", "First snow of the year");
    add_entry(d, "January 3rd", "Went skiing with friends");

    // Display the entries
    display_entry(d);

    // Add another entry, but this time, wrap around to the beginning
    add_entry(d, "December 31st", "New Year's Eve");

    // Display the entries again
    display_entry(d);

    // Free the memory
    free(d);

    return 0;
}