//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define DIARY_MAX_ENTRIES 100
#define DIARY_ENTRY_SIZE 256

typedef struct {
    char date[20];
    char entry[DIARY_ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_MAX_ENTRIES];
    int current_entry;
} diary_t;

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_MAX_ENTRIES; i++) {
        d->entries[i].date[0] = '\0';
        d->entries[i].entry[0] = '\0';
    }
    d->current_entry = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    int i;
    if (d->current_entry == DIARY_MAX_ENTRIES) {
        printf("Error: Diary is full, cannot add another entry\n");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void print_entry(diary_t *d, int index) {
    printf("[%s] %s\n", d->entries[index].date, d->entries[index].entry);
}

int main() {
    diary_t *d;
    char date[20];
    char entry[DIARY_ENTRY_SIZE];

    // Initialize diary
    init_diary(d);

    // Add entries
    add_entry(d, "2022-01-01", "First entry");
    add_entry(d, "2022-01-02", "Second entry");
    add_entry(d, "2022-01-03", "Third entry");

    // Print entries
    for (int i = 0; i < DIARY_MAX_ENTRIES; i++) {
        print_entry(d, i);
    }

    // Get current date and entry
    struct tm now;
    char current_date[20];
    char current_entry[DIARY_ENTRY_SIZE];
    gettimeofday(&now, NULL);
    strftime(current_date, sizeof(current_date), "%Y-%m-%d", &now);
    current_entry[0] = '\0';

    // Add current entry
    add_entry(d, current_date, current_entry);

    // Print current entry
    print_entry(d, d->current_entry - 1);

    return 0;
}