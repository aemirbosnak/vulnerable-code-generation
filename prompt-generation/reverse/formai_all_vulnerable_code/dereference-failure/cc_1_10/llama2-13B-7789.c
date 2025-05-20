//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DAY_COUNT 30
#define MONTH_COUNT 12
#define YEAR_COUNT 100

typedef struct {
    int day;
    int month;
    int year;
} date_t;

typedef struct {
    date_t start_date;
    date_t end_date;
    int entry_count;
    char** entries;
} diary_t;

diary_t* create_diary(void);
void add_entry(diary_t* d, char* entry);
void print_diary(diary_t* d);

int main(void) {
    diary_t* d = create_diary();

    // Add some entries
    add_entry(d, "First entry");
    add_entry(d, "Second entry");
    add_entry(d, "Third entry");

    // Print the diary
    print_diary(d);

    return 0;
}

diary_t* create_diary(void) {
    diary_t* d = (diary_t*) malloc(sizeof(diary_t));
    d->start_date = (date_t){1, 1, 2000};
    d->end_date = (date_t){31, 12, 2030};
    d->entry_count = 0;
    d->entries = (char**) malloc(sizeof(char*) * DAY_COUNT * MONTH_COUNT);
    return d;
}

void add_entry(diary_t* d, char* entry) {
    int day = d->start_date.day + d->entry_count;
    int month = d->start_date.month + d->entry_count / DAY_COUNT;
    int year = d->start_date.year + d->entry_count / DAY_COUNT / MONTH_COUNT;

    if (day > DAY_COUNT) {
        day = 1;
        month++;
        if (month > MONTH_COUNT) {
            month = 1;
            year++;
        }
    }

    d->entries[day][month] = entry;
    d->entry_count++;
}

void print_diary(diary_t* d) {
    for (int i = 1; i <= DAY_COUNT; i++) {
        for (int j = 1; j <= MONTH_COUNT; j++) {
            printf("%2d %s\n", i, d->entries[i][j]);
        }
    }
}