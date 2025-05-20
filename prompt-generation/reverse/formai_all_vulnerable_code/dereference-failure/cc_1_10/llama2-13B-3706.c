//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 10000
#define ENTRY_SIZE 100

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_index;
} diary_t;

void init_diary(diary_t* d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        d->entries[i].entry[0] = '\0';
    }
    d->current_index = 0;
}

void add_entry(diary_t* d, char* date, char* entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (strcmp(d->entries[i].date, date) == 0) {
            strcat(d->entries[i].entry, "\n");
            strcat(d->entries[i].entry, entry);
            return;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Error: Diary is full! Sorry, I can't add any more entries.\n");
        return;
    }
    strcpy(d->entries[i].date, date);
    strcpy(d->entries[i].entry, entry);
    d->current_index = i;
}

void view_entry(diary_t* d) {
    if (d->current_index == -1) {
        printf("Error: No entries found! Sorry, try again later.\n");
        return;
    }
    printf("Diary Entry for %s\n", d->entries[d->current_index].date);
    printf("%s\n", d->entries[d->current_index].entry);
}

int main() {
    diary_t* d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    while (1) {
        printf("Enter date (format: mm/dd/yyyy): ");
        scanf("%19s", date);
        add_entry(d, date, entry);
        view_entry(d);
    }

    return 0;
}