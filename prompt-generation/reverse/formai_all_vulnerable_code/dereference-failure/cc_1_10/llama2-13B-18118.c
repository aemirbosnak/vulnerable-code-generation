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
    int curr_entry;
} diary_t;

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->curr_entry = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (strcmp(d->entries[i].date, date) == 0) {
            strcpy(d->entries[i].entry, entry);
            return;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Error: Diary is full!\n");
        return;
    }
    strcpy(d->entries[i].date, date);
    strcpy(d->entries[i].entry, entry);
}

void display_entry(diary_t *d) {
    printf("Date: %s\n", d->entries[d->curr_entry].date);
    printf("Entry: %s\n", d->entries[d->curr_entry].entry);
}

int main() {
    diary_t *d;
    char date[20];
    char entry[ENTRY_SIZE];

    srand(time(NULL));

    d = (diary_t *)malloc(sizeof(diary_t));
    init_diary(d);

    while (1) {
        printf("Enter date (format: mm/dd/yyyy): ");
        fgets(date, 20, stdin);
        printf("Enter entry: ");
        fgets(entry, ENTRY_SIZE, stdin);

        add_entry(d, date, entry);

        display_entry(d);

        printf("Do you want to add another entry? (y/n): ");
        char ans = getchar();
        if (ans == 'n') break;
    }

    free(d);
    return 0;
}