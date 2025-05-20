//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 256

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_entry;
} diary_t;

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_entry = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (d->current_entry == i) {
            strcpy(d->entries[i].date, date);
            strcpy(d->entries[i].entry, entry);
            break;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Error: Diary is full, cannot add new entry\n");
    }
}

void view_entry(diary_t *d, int entry_num) {
    if (entry_num >= 0 && entry_num < DIARY_SIZE) {
        printf("Date: %s\n", d->entries[entry_num].date);
        printf("Entry: %s\n", d->entries[entry_num].entry);
    } else {
        printf("Error: Invalid entry number\n");
    }
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter date (mm/dd/yyyy): ");
        fgets(date, 20, stdin);
        printf("Enter entry: ");
        fgets(entry, ENTRY_SIZE, stdin);

        add_entry(d, date, entry);

        printf("Here is your diary entry:\n");
        view_entry(d, d->current_entry);

        printf("Do you want to add another entry? (y/n): ");
        char ch = getchar();
        if (ch == 'n') {
            break;
        }
    }

    free(d);
    return 0;
}