//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 100
#define MAX_ENTRY_LENGTH 256

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_entry;
} diary_t;

void init_diary(diary_t *diary) {
    int i;

    for (i = 0; i < DIARY_SIZE; i++) {
        diary->entries[i].date[0] = '\0';
        diary->entries[i].entry[0] = '\0';
    }

    diary->current_entry = 0;
}

void add_entry(diary_t *diary, char *date, char *entry) {
    int i;

    for (i = 0; i < DIARY_SIZE; i++) {
        if (diary->entries[i].date[0] == '\0') {
            break;
        }
    }

    if (i == DIARY_SIZE) {
        printf("Error: Diary is full! 😱\n");
        return;
    }

    strcpy(diary->entries[i].date, date);
    strcpy(diary->entries[i].entry, entry);

    diary->current_entry = i;
}

void display_entry(diary_t *diary) {
    int i;

    if (diary->current_entry == -1) {
        printf("No entries found! 😔\n");
        return;
    }

    printf("Date: %s\n", diary->entries[diary->current_entry].date);
    printf("Entry: %s\n", diary->entries[diary->current_entry].entry);

    diary->current_entry++;
}

int main() {
    diary_t *diary = malloc(sizeof(diary_t));

    init_diary(diary);

    add_entry(diary, "Monday", "Woke up early and ate a bowl of oatmeal for breakfast");
    add_entry(diary, "Tuesday", "Went to the gym and ran 5 miles on the treadmill");
    add_entry(diary, "Wednesday", "Had a big meeting at work and nailed it!");

    display_entry(diary);

    return 0;
}