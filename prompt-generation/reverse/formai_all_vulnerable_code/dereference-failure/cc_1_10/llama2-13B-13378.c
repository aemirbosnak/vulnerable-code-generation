//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_MAX_ENTRIES 100
#define DIARY_ENTRY_LENGTH 256

typedef struct {
    char date[20];
    char entry[DIARY_ENTRY_LENGTH];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_MAX_ENTRIES];
    int num_entries;
} diary_t;

void diary_init(diary_t *diary) {
    memset(diary, 0, sizeof(diary_t));
}

void diary_add_entry(diary_t *diary, char *date, char *entry) {
    if (diary->num_entries >= DIARY_MAX_ENTRIES) {
        printf("Error: Diary is full, cannot add new entry.\n");
        return;
    }

    strcpy(diary->entries[diary->num_entries].date, date);
    strcpy(diary->entries[diary->num_entries].entry, entry);
    diary->num_entries++;
}

void diary_print(diary_t *diary) {
    int i;

    printf("--- Diary ---\n");

    for (i = 0; i < diary->num_entries; i++) {
        printf("%d. %s: %s\n", i + 1, diary->entries[i].date, diary->entries[i].entry);
    }

    printf("--- End of Diary ---\n");
}

int main() {
    diary_t *diary = malloc(sizeof(diary_t));
    diary_init(diary);

    char date[] = "2022-01-01";
    char entry[] = "First diary entry!";

    diary_add_entry(diary, date, entry);

    diary_print(diary);

    free(diary);

    return 0;
}