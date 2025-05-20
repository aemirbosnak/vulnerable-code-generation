//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIARY_ENTRIES 10
#define MAX_ENTRY_LENGTH 256

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[MAX_DIARY_ENTRIES];
    int current_entry;
} diary_t;

void init_diary(diary_t *diary) {
    int i;
    for (i = 0; i < MAX_DIARY_ENTRIES; i++) {
        diary->entries[i].date[0] = '\0';
        diary->entries[i].entry[0] = '\0';
    }
    diary->current_entry = 0;
}

void add_entry(diary_t *diary, char *date, char *entry) {
    if (diary->current_entry < MAX_DIARY_ENTRIES) {
        strcpy(diary->entries[diary->current_entry].date, date);
        strcpy(diary->entries[diary->current_entry].entry, entry);
        diary->current_entry++;
    }
}

void view_entry(diary_t *diary, int entry_num) {
    if (entry_num < MAX_DIARY_ENTRIES && entry_num >= 0) {
        printf("Entry %d: %s\n", entry_num + 1, diary->entries[entry_num].entry);
    }
}

void delete_entry(diary_t *diary, int entry_num) {
    if (entry_num < MAX_DIARY_ENTRIES && entry_num >= 0) {
        memset(&diary->entries[entry_num], 0, sizeof(diary_entry_t));
        diary->current_entry--;
    }
}

int main() {
    diary_t *diary = malloc(sizeof(diary_t));
    init_diary(diary);

    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter date (mm/dd/yyyy): ");
        fgets(date, 20, stdin);
        printf("Enter entry: ");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);

        add_entry(diary, date, entry);

        view_entry(diary, diary->current_entry - 1);

        printf("Delete entry %d? (y/n): ", diary->current_entry);
        char delete_response = getchar();

        if (delete_response == 'y' || delete_response == 'Y') {
            delete_entry(diary, diary->current_entry - 1);
        }
    }

    free(diary);
    return 0;
}