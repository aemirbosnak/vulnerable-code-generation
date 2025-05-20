//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    int date;
    int duration;
    int calories;
};

void add_entry(struct entry* entries, int count, int date, int duration, int calories) {
    if (count >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    entries[count].date = date;
    entries[count].duration = duration;
    entries[count].calories = calories;
    count++;
}

void display_entries(struct entry* entries, int count) {
    printf("Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%d/%d/%d - %d minutes - %d calories\n", entries[i].date, entries[i].date % 100 + 1, entries[i].date / 10000 + 1900, entries[i].duration, entries[i].calories);
    }
}

void calculate_stats(struct entry* entries, int count) {
    int total_duration = 0;
    int total_calories = 0;

    for (int i = 0; i < count; i++) {
        total_duration += entries[i].duration;
        total_calories += entries[i].calories;
    }

    printf("Total duration: %d minutes\n", total_duration);
    printf("Total calories burned: %d\n", total_calories);
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    time_t now = time(0);
    struct tm* t = localtime(&now);

    int date = t->tm_year + 1900;
    date = date * 10000 + t->tm_mon + 1;
    date = date * 100 + t->tm_mday;

    add_entry(entries, count, date, 30, 200);
    add_entry(entries, count, date, 45, 300);
    add_entry(entries, count, date, 60, 400);

    display_entries(entries, count);
    calculate_stats(entries, count);

    return 0;
}