//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: complete
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
    int current_index;
} diary_t;

void init_diary(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_index = 0;
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
        printf("Diary is full, cannot add new entry\n");
    }
}

void display_entry(diary_t *d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        printf("%s: %s\n", d->entries[i].date, d->entries[i].entry);
    }
}

int main() {
    diary_t *d;
    char date[20];
    char entry[ENTRY_SIZE];

    d = (diary_t *) malloc(sizeof(diary_t));
    init_diary(d);

    printf("Welcome to your digital diary\n");

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        fgets(date, 20, stdin);
        printf("Enter entry: ");
        fgets(entry, ENTRY_SIZE, stdin);

        add_entry(d, date, entry);

        display_entry(d);

        printf("Do you want to add another entry? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'N') {
            break;
        }
    }

    free(d);
    return 0;
}