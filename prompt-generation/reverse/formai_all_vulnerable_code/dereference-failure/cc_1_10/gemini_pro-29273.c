//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: statistical
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

typedef struct {
    char *date;
    char *entry;
} DiaryEntry;

typedef struct {
    int num_entries;
    DiaryEntry *entries;
} DigitalDiary;

DigitalDiary *create_diary() {
    DigitalDiary *dd = malloc(sizeof(DigitalDiary));
    dd->num_entries = 0;
    dd->entries = NULL;
    return dd;
}

void add_entry(DigitalDiary *dd, char *date, char *entry) {
    dd->entries = realloc(dd->entries, sizeof(DiaryEntry) * (dd->num_entries + 1));
    dd->entries[dd->num_entries].date = strdup(date);
    dd->entries[dd->num_entries].entry = strdup(entry);
    dd->num_entries++;
}

void print_entry(DiaryEntry *entry) {
    printf("%s: %s\n", entry->date, entry->entry);
}

void print_diary(DigitalDiary *dd) {
    for (int i = 0; i < dd->num_entries; i++) {
        print_entry(&dd->entries[i]);
    }
}

int main() {
    DigitalDiary *dd = create_diary();

    add_entry(dd, "2023-01-01", "Today I went for a walk in the park.");
    add_entry(dd, "2023-01-02", "I went to the library and borrowed a book.");
    add_entry(dd, "2023-01-03", "I had a meeting with my friends.");
    add_entry(dd, "2023-01-04", "I worked on a project for school.");

    print_diary(dd);

    return 0;
}