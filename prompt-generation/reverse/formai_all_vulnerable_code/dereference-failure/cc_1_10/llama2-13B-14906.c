//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
        if (d->entries[i].date[0] == '\0') {
            strcpy(d->entries[i].date, date);
            strcpy(d->entries[i].entry, entry);
            d->current_entry = i;
            break;
        }
    }
}

void display_entry(diary_t *d) {
    if (d->current_entry < DIARY_SIZE) {
        printf("%s - %s\n", d->entries[d->current_entry].date, d->entries[d->current_entry].entry);
    } else {
        printf("No more entries\n");
    }
}

int main() {
    diary_t *d = (diary_t *)malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter a date (mm/dd/yyyy): ");
        fgets(date, 20, stdin);
        add_entry(d, date, entry);

        printf("Enter an entry: ");
        fgets(entry, ENTRY_SIZE, stdin);

        display_entry(d);
    }

    free(d);
    return 0;
}