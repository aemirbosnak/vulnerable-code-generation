//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define DAY_SIZE 30

typedef struct {
    char date[10];
    char entry[100];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_index;
} diary_t;

void init_diary(diary_t* d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_index = 0;
}

void add_entry(diary_t* d, char* date, char* entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (strcmp(d->entries[i].date, date) == 0) {
            strcpy(d->entries[i].entry, entry);
            return;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Error: Diary is full. Please delete some entries before adding new ones.\n");
        return;
    }
    strcpy(d->entries[i].date, date);
    strcpy(d->entries[i].entry, entry);
}

void view_entry(diary_t* d, int index) {
    if (index < 0 || index >= DIARY_SIZE) {
        printf("Error: Invalid index %d\n", index);
        return;
    }
    printf("Date: %s\n", d->entries[index].date);
    printf("Entry: %s\n", d->entries[index].entry);
}

int main() {
    diary_t* d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[10];
    char entry[100];

    printf("Enter date (mm/dd/yy): ");
    fgets(date, 10, stdin);
    printf("Enter entry: ");
    fgets(entry, 100, stdin);

    add_entry(d, date, entry);

    view_entry(d, 0);

    return 0;
}