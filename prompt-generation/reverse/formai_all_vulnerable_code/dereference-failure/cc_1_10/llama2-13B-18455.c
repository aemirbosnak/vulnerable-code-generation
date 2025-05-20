//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: active
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
    int current_entry;
} diary_t;

void init_diary(diary_t *diary) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        strcpy(diary->entries[i].date, "");
        strcpy(diary->entries[i].entry, "");
    }
    diary->current_entry = 0;
}

void add_entry(diary_t *diary, char *date, char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (strcmp(diary->entries[i].date, date) == 0) {
            strcpy(diary->entries[i].entry, entry);
            break;
        }
    }
    if (i == DIARY_SIZE) {
        printf("Error: No more space in diary!\n");
    }
}

void display_entry(diary_t *diary) {
    printf("Date: %s\n", diary->entries[diary->current_entry].date);
    printf("Entry: %s\n", diary->entries[diary->current_entry].entry);
}

int main() {
    diary_t *diary = malloc(sizeof(diary_t));
    init_diary(diary);

    char date[20];
    char entry[ENTRY_SIZE];

    printf("Welcome to your digital diary! \n");

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        fgets(date, 20, stdin);
        printf("Enter entry: ");
        fgets(entry, ENTRY_SIZE, stdin);

        add_entry(diary, date, entry);
        display_entry(diary);
    }

    return 0;
}