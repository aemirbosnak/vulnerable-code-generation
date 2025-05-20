//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Structure for the diary
struct diary {
    int day;
    char* month;
    char* year;
    char* entry[10];
    int num_entries;
};

// Function to create the diary structure
void create_diary(struct diary* d) {
    d->day = 0;
    d->month = malloc(5 * sizeof(char));
    d->year = malloc(5 * sizeof(char));
    d->entry[0] = malloc(100 * sizeof(char));
    d->entry[1] = malloc(100 * sizeof(char));
    d->entry[2] = malloc(100 * sizeof(char));
    d->entry[3] = malloc(100 * sizeof(char));
    d->entry[4] = malloc(100 * sizeof(char));
    d->entry[5] = malloc(100 * sizeof(char));
    d->entry[6] = malloc(100 * sizeof(char));
    d->entry[7] = malloc(100 * sizeof(char));
    d->entry[8] = malloc(100 * sizeof(char));
    d->entry[9] = malloc(100 * sizeof(char));
    d->num_entries = 10;
}

// Function to add an entry to the diary
void add_entry(struct diary* d, const char* entry) {
    d->num_entries++;
    d->entry[d->num_entries-1] = malloc((strlen(entry)+1) * sizeof(char));
    strcpy(d->entry[d->num_entries-1], entry);
}

// Function to read entries from the diary
void read_entries(struct diary* d) {
    printf("Day: %d\n", d->day);
    printf("Month: %s\n", d->month);
    printf("Year: %s\n", d->year);
    printf("Entries:\n");
    for (int i = 0; i < d->num_entries; i++) {
        printf("Entry %d: %s\n", i+1, d->entry[i]);
    }
}

// Function to print the diary entries
void print_entries(struct diary* d) {
    printf("Day: %d\n", d->day);
    printf("Month: %s\n", d->month);
    printf("Year: %s\n", d->year);
    printf("Entries:\n");
    for (int i = 0; i < d->num_entries; i++) {
        printf("Entry %d: %s\n", i+1, d->entry[i]);
    }
}

int main() {
    struct diary diary;
    create_diary(&diary);
    add_entry(&diary, "Entry 1");
    add_entry(&diary, "Entry 2");
    read_entries(&diary);
    print_entries(&diary);
    return 0;
}