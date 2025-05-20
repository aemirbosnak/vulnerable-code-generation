//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: careful
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

void init_diary(diary_t *diary) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        diary->entries[i].date[0] = '\0';
        diary->entries[i].entry[0] = '\0';
    }
    diary->current_index = 0;
}

void add_entry(diary_t *diary, char *date, char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (diary->entries[i].date[0] == '\0') {
            strcpy(diary->entries[i].date, date);
            strcpy(diary->entries[i].entry, entry);
            break;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Diary is full, cannot add new entry\n");
    }
}

void display_entry(diary_t *diary) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        printf("%s: %s\n", diary->entries[i].date, diary->entries[i].entry);
    }
}

int main() {
    diary_t *diary = (diary_t *)malloc(sizeof(diary_t));
    init_diary(diary);

    char date[] = "2022-01-01";
    char entry[] = "First digital diary entry!";
    add_entry(diary, date, entry);

    display_entry(diary);

    char new_entry[] = "Second digital diary entry!";
    add_entry(diary, date, new_entry);

    display_entry(diary);

    free(diary);
    return 0;
}