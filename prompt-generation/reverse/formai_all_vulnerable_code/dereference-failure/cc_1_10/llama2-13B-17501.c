//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRATITUDE_MAX_ENTRIES 10
#define GRATITUDE_ENTRY_LENGTH 256

typedef struct {
    char date[20];
    char entry[GRATITUDE_ENTRY_LENGTH];
} gratitude_entry_t;

typedef struct {
    gratitude_entry_t entries[GRATITUDE_MAX_ENTRIES];
    int count;
} gratitude_diary_t;

void init_gratitude_diary(gratitude_diary_t *diary) {
    memset(diary, 0, sizeof(gratitude_diary_t));
}

void add_gratitude_entry(gratitude_diary_t *diary, const char *date, const char *entry) {
    gratitude_entry_t *new_entry = (gratitude_entry_t *)realloc(diary->entries, (diary->count + 1) * sizeof(gratitude_entry_t));
    if (!new_entry) {
        printf("Error: unable to allocate memory for gratitude entry\n");
        return;
    }
    diary->entries[diary->count] = *new_entry;
    strcpy(diary->entries[diary->count].date, date);
    strcpy(diary->entries[diary->count].entry, entry);
    diary->count++;
}

void print_gratitude_diary(gratitude_diary_t *diary) {
    for (int i = 0; i < diary->count; i++) {
        printf("%s: %s\n", diary->entries[i].date, diary->entries[i].entry);
    }
}

int main() {
    gratitude_diary_t diary;
    init_gratitude_diary(&diary);

    add_gratitude_entry(&diary, "2023-02-14", "Woke up to a beautiful sunrise");
    add_gratitude_entry(&diary, "2023-02-15", "Had a great conversation with a friend");
    add_gratitude_entry(&diary, "2023-02-16", "Found a dollar on the ground");

    print_gratitude_diary(&diary);

    return 0;
}