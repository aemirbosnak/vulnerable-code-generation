//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 500
#define ENTRY_SIZE 200

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_entry;
} diary_t;

void init_diary(diary_t* d) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_entry = 0;
}

void add_entry(diary_t* d, char* date, char* entry) {
    if (d->current_entry == DIARY_SIZE) {
        printf("Error: Diary is full. Please delete some entries before adding more.\n");
        return;
    }
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
}

void view_entry(diary_t* d, int index) {
    if (index < 0 || index >= DIARY_SIZE) {
        printf("Error: Invalid entry index. Please enter a valid index between 0 and %d.\n", DIARY_SIZE - 1);
        return;
    }
    printf("Entry for %s:\n", d->entries[index].date);
    printf("%s\n", d->entries[index].entry);
}

int main() {
    diary_t* d = malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    printf("Welcome to my digital diary! Please enter the date and entry for today:\n");

    // Add entries
    printf("Add entry for %s:\n", date);
    scanf("%19s%19s", date, entry);
    add_entry(d, date, entry);

    // View entries
    printf("Here are my previous entries:\n");
    for (int i = 0; i < DIARY_SIZE; i++) {
        view_entry(d, i);
    }

    return 0;
}