//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the diary structure
typedef struct {
    int day; // current day of the month
    int month; // current month of the year
    int year; // current year
    int entries[31]; // array of entries for each day
} diary_t;

// Function to initialize the diary
void init_diary(diary_t *d) {
    d->day = 1; // initialize day to 1
    d->month = 1; // initialize month to 1
    d->year = 2023; // initialize year to 2023
    memset(d->entries, 0, sizeof(d->entries)); // initialize entries array to 0
}

// Function to add an entry to the diary
void add_entry(diary_t *d, int day, int month, int year, const char *text) {
    if (day > 31 || month > 12 || year < 1970 || year > 2050) {
        printf("Invalid date and/or text entry\n");
        return;
    }
    d->day = day;
    d->month = month;
    d->year = year;
    strcpy(d->entries[day], text); // store the text entry in the array
}

// Function to print the diary
void print_diary(diary_t *d) {
    for (int i = 1; i <= 31; i++) {
        if (d->entries[i]) {
            printf("%d %d %d: %s\n", d->day, d->month, d->year, d->entries[i]);
        }
    }
}

int main() {
    diary_t d; // initialize the diary struct
    init_diary(&d);

    // Add some entries
    add_entry(&d, 1, 1, 2023, "First entry");
    add_entry(&d, 5, 2, 2023, "Second entry");
    add_entry(&d, 15, 3, 2023, "Third entry");

    // Print the diary
    print_diary(&d);

    return 0;
}