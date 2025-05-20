//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void init_diary(diary_t *diary) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(diary->entries[i].date, "");
        strcpy(diary->entries[i].entry, "");
    }
    diary->current_index = 0;
}

void add_entry(diary_t *diary, char *date, char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (strlen(diary->entries[i].date) < ENTRY_SIZE) {
            strcpy(diary->entries[i].date, date);
            strcpy(diary->entries[i].entry, entry);
            break;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Error: Diary is full, cannot add new entry\n");
    }
}

void display_entry(diary_t *diary) {
    int i;
    for (i = 0; i < diary->current_index; i++) {
        printf("%s - %s\n", diary->entries[i].date, diary->entries[i].entry);
    }
}

int main() {
    diary_t *diary = malloc(sizeof(diary_t));
    init_diary(diary);

    while (1) {
        char date[20];
        char entry[ENTRY_SIZE];

        printf("Enter date (mm/dd/yyyy): ");
        scanf("%19s", date);
        printf("Enter entry: ");
        scanf("%255s", entry);

        add_entry(diary, date, entry);
        display_entry(diary);
    }

    return 0;
}