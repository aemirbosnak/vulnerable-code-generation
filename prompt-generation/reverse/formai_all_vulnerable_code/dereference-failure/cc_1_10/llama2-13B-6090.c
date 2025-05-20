//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 500

typedef struct {
    char date[20];
    char entry[100];
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
    if (d->current_entry == DIARY_SIZE) {
        printf("Error: Diary is full. Please delete some entries first.\n");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void print_entry(diary_t *d) {
    int i;
    printf("-----------------------------------------------------------------\n");
    for (i = 0; i < d->current_entry; i++) {
        printf("Date: %s\n", d->entries[i].date);
        printf("Entry: %s\n", d->entries[i].entry);
    }
    printf("-----------------------------------------------------------------\n");
}

int main() {
    diary_t *d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[100];

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter a date (format: mm/dd/yyyy): ");
        fgets(date, 20, stdin);
        printf("Enter an entry: ");
        fgets(entry, 100, stdin);

        add_entry(d, date, entry);

        print_entry(d);

        printf("Do you want to add another entry? (y/n): ");
        char ch = getchar();
        if (ch == 'n') break;
    }

    free(d);
    return 0;
}