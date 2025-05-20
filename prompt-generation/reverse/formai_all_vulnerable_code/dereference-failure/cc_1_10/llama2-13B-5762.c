//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIARY_SIZE 1000 // size of the diary in bytes
#define ENTRY_SIZE 50 // size of each entry in bytes

typedef struct {
    int day; // day of the month (1-31)
    int month; // month of the year (1-12)
    int year; // year (1900-2099)
    char entry[ENTRY_SIZE]; // entry text
} DiaryEntry;

typedef struct {
    DiaryEntry** entries; // array of entries
    int capacity; // capacity of the diary in entries
    int size; // number of entries in the diary
} Diary;

Diary* createDiary(int capacity) {
    Diary* d = (Diary*) malloc(sizeof(Diary));
    d->capacity = capacity;
    d->size = 0;
    d->entries = (DiaryEntry**) malloc(capacity * sizeof(DiaryEntry*));
    return d;
}

void addEntry(Diary* d, char* entry) {
    if (d->size == d->capacity) {
        // increase capacity by 50%
        int newCapacity = d->capacity * 2;
        DiaryEntry** newEntries = (DiaryEntry**) realloc(d->entries, newCapacity * sizeof(DiaryEntry*));
        d->capacity = newCapacity;
        d->entries = newEntries;
    }
    DiaryEntry* e = (DiaryEntry*) malloc(sizeof(DiaryEntry));
    e->day = rand() % 31;
    e->month = rand() % 12;
    e->year = rand() % 100;
    strcpy(e->entry, entry);
    d->entries[d->size] = e;
    d->size++;
}

void printDiary(Diary* d) {
    for (int i = 0; i < d->size; i++) {
        printf("%d-%d-%d: %s\n", d->entries[i]->day, d->entries[i]->month, d->entries[i]->year, d->entries[i]->entry);
    }
}

int main() {
    Diary* d = createDiary(10);
    char* entries[] = {"I love math", "I hate algebra", "Calculus is fun", "Geometry is cool", "I'm a math genius"};
    for (int i = 0; i < 5; i++) {
        addEntry(d, entries[i]);
    }
    printDiary(d);
    return 0;
}