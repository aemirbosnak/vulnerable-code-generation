//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DAY_LENGTH 24 * 60 * 60
#define MONTH_LENGTH 31
#define YEAR_LENGTH 12

typedef struct {
    int day;
    int month;
    int year;
    char entry[100];
} diary_t;

diary_t *diary_create(void) {
    diary_t *d = malloc(sizeof(diary_t));
    d->day = 1;
    d->month = 1;
    d->year = 2023;
    strcpy(d->entry, "");
    return d;
}

void diary_delete(diary_t *d) {
    free(d);
}

void diary_write(diary_t *d, const char *entry) {
    strcpy(d->entry, entry);
}

const char *diary_read(diary_t *d) {
    return d->entry;
}

int diary_check_day(diary_t *d) {
    if (d->day > DAY_LENGTH) {
        d->day = 1;
        d->month++;
        if (d->month > MONTH_LENGTH) {
            d->month = 1;
            d->year++;
        }
    }
    return d->day;
}

int main() {
    diary_t *d = diary_create();
    char entry[] = "Woke up early today and went for a run. The sun was shining bright and the birds were singing their sweet melodies. It's going to be a great day!";
    diary_write(d, entry);
    while (1) {
        diary_check_day(d);
        printf("Today is %d/%d/%d\n", d->day, d->month, d->year);
        printf("Entry: %s\n", diary_read(d));
        getchar();
    }
    diary_delete(d);
    return 0;
}