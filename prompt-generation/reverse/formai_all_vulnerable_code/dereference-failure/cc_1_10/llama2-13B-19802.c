//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 100

struct entry {
    char date[20];
    char entry[100];
};

void init_digital_diary(void);
void add_entry(struct entry *, char *, char *);
void display_entries(struct entry *, int);
void delete_entry(struct entry *, int);

int main() {
    init_digital_diary();

    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        char date[20];
        scanf("%19s", date);

        printf("Enter an entry: ");
        char entry[100];
        scanf("%99s", entry);

        add_entry(NULL, date, entry);
    }

    return 0;
}

void init_digital_diary(void) {
    struct entry *entries = calloc(MAX_ENTRIES, sizeof(struct entry));
    int i;

    for (i = 0; i < MAX_ENTRIES; i++) {
        entries[i].date[0] = '\0';
        entries[i].entry[0] = '\0';
    }
}

void add_entry(struct entry *entries, char *date, char *entry) {
    int i = 0;

    while (i < MAX_ENTRIES && strlen(entries[i].date) > 0) {
        i++;
    }

    if (i == MAX_ENTRIES) {
        printf("Error: Digital diary is full. Please delete some entries before adding new ones.\n");
        return;
    }

    strcpy(entries[i].date, date);
    strcpy(entries[i].entry, entry);

    printf("Entry added successfully. Total entries: %d\n", i + 1);
}

void display_entries(struct entry *entries, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%4d. %s\n", i + 1, entries[i].date);
        printf("    %s\n", entries[i].entry);
    }

    if (i < count) {
        printf("There are %d more entries...\n", count - i);
    }
}

void delete_entry(struct entry *entries, int index) {
    if (index < 0 || index >= MAX_ENTRIES) {
        printf("Error: Invalid index. Please enter a valid index between 0 and %d.\n", MAX_ENTRIES - 1);
        return;
    }

    strcpy(entries[index].date, "");
    strcpy(entries[index].entry, "");

    for (int i = index; i < MAX_ENTRIES - 1; i++) {
        entries[i] = entries[i + 1];
    }

    printf("Entry deleted successfully. Total entries: %d\n", MAX_ENTRIES - 1);
}