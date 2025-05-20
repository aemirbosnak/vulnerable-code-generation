//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIARY_SIZE 10000
#define MAX_ENTRY_SIZE 500

typedef struct {
    char *entry_date;
    char *entry_text;
} diary_entry_t;

typedef struct {
    diary_entry_t entries[10];
    int num_entries;
} diary_t;

void init_diary(diary_t *diary) {
    for (int i = 0; i < 10; i++) {
        diary->entries[i].entry_date = NULL;
        diary->entries[i].entry_text = NULL;
    }
    diary->num_entries = 0;
}

void add_entry(diary_t *diary, char *entry_date, char *entry_text) {
    if (diary->num_entries == 10) {
        printf("Diary is full. Please delete some entries before adding new ones.\n");
        return;
    }
    diary->entries[diary->num_entries].entry_date = entry_date;
    diary->entries[diary->num_entries].entry_text = entry_text;
    diary->num_entries++;
}

void display_diary(diary_t *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s: %s\n", diary->entries[i].entry_date, diary->entries[i].entry_text);
    }
}

int main() {
    diary_t *diary = malloc(sizeof(diary_t));
    init_diary(diary);

    char entry_date[50];
    char entry_text[500];

    while (1) {
        printf("Enter a diary entry date (YYYY-MM-DD): ");
        fgets(entry_date, 50, stdin);
        printf("Enter a diary entry text: ");
        fgets(entry_text, 500, stdin);

        add_entry(diary, entry_date, entry_text);

        display_diary(diary);

        printf("Do you want to add another entry? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    free(diary);
    return 0;
}