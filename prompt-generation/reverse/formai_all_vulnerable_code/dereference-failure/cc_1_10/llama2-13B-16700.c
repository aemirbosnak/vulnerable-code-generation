//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 500
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
        if (strcmp(diary->entries[i].date, date) == 0) {
            strcpy(diary->entries[i].entry, entry);
            return;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Error: Diary is full\n");
        return;
    }
    strcpy(diary->entries[i].date, date);
    strcpy(diary->entries[i].entry, entry);
}

void display_entry(diary_t *diary) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        printf("%s: %s\n", diary->entries[i].date, diary->entries[i].entry);
    }
}

int main() {
    diary_t *diary = malloc(sizeof(diary_t));
    init_diary(diary);

    char date[] = "2023-03-14";
    char entry[] = "Went to the park with my dog";

    add_entry(diary, date, entry);

    display_entry(diary);

    free(diary);

    return 0;
}