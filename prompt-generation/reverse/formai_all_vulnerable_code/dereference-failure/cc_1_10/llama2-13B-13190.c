//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define DIARY_SIZE 1024
#define ENTRY_SIZE 256

typedef struct {
    char date[16];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int curr_entry;
} digital_diary_t;

void init_diary(digital_diary_t* d) {
    memset(d, 0, sizeof(digital_diary_t));
    d->curr_entry = 0;
}

void add_entry(digital_diary_t* d, const char* date, const char* entry) {
    diary_entry_t* new_entry = (diary_entry_t*) malloc(sizeof(diary_entry_t));
    strncpy(new_entry->date, date, 16);
    strncpy(new_entry->entry, entry, ENTRY_SIZE);
    d->entries[d->curr_entry] = *new_entry;
    d->curr_entry++;
}

void print_diary(digital_diary_t* d) {
    for (int i = 0; i < d->curr_entry; i++) {
        printf("%15s: %s\n", d->entries[i].date, d->entries[i].entry);
    }
}

int main() {
    digital_diary_t* d = (digital_diary_t*) malloc(sizeof(digital_diary_t));
    init_diary(d);

    // Add some entries
    add_entry(d, "January 1st", "Happy New Year!");
    add_entry(d, "January 2nd", "Went to the beach.");
    add_entry(d, "January 3rd", "Learned a new programming language.");

    // Print the diary
    print_diary(d);

    return 0;
}