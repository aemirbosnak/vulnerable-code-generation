//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_MAX_ENTRIES 100
#define ENTRY_MAX_LENGTH 256

struct diary_entry {
    char date[20];
    char entry[ENTRY_MAX_LENGTH];
};

typedef struct diary_entry diary_entry_t;

diary_entry_t *diary = NULL;
int num_entries = 0;

void init_diary() {
    diary = (diary_entry_t *)calloc(DIARY_MAX_ENTRIES, sizeof(diary_entry_t));
    if (diary == NULL) {
        perror("Failed to allocate memory for diary");
        exit(EXIT_FAILURE);
    }
}

void add_entry(char *date, char *entry) {
    diary_entry_t *new_entry = (diary_entry_t *)calloc(1, sizeof(diary_entry_t));
    strcpy(new_entry->date, date);
    strcpy(new_entry->entry, entry);
    if (num_entries == DIARY_MAX_ENTRIES) {
        printf("Warning: Maximum number of entries reached. Overwriting oldest entry.\n");
        // Overwrite the oldest entry
        memmove(diary, diary + 1, (DIARY_MAX_ENTRIES - 1) * sizeof(diary_entry_t));
        diary[DIARY_MAX_ENTRIES - 1] = *new_entry;
    } else {
        diary[num_entries] = *new_entry;
        num_entries++;
    }
}

void display_diary() {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    init_diary();

    // Example usage
    char date[] = "2023-03-15";
    char entry[] = "Went to the beach with friends";
    add_entry(date, entry);

    char date2[] = "2023-03-16";
    char entry2[] = "Visited a museum with family";
    add_entry(date2, entry2);

    display_diary();

    return 0;
}