//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 100

typedef struct {
    char name[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_entry;
} diary_t;

void init_diary(diary_t *diary) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        diary->entries[i].name[0] = '\0';
        diary->entries[i].entry[0] = '\0';
    }
    diary->current_entry = 0;
}

void add_entry(diary_t *diary, const char *name, const char *entry) {
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (diary->entries[i].name[0] == '\0') {
            strcpy(diary->entries[i].name, name);
            strcpy(diary->entries[i].entry, entry);
            diary->current_entry = i;
            break;
        }
    }
}

void display_entry(diary_t *diary) {
    if (diary->current_entry >= DIARY_SIZE) {
        printf("No more entries available\n");
        return;
    }
    printf("Name: %s\n", diary->entries[diary->current_entry].name);
    printf("Entry: %s\n", diary->entries[diary->current_entry].entry);
    diary->current_entry++;
}

int main() {
    diary_t *diary = malloc(sizeof(diary_t));
    init_diary(diary);

    // Add some entries
    add_entry(diary, "Breakfast", "Overnight oats with almond milk and fruit");
    add_entry(diary, "Lunch", "Tuna salad sandwich with avocado and carrot sticks");
    add_entry(diary, "Dinner", "Grilled chicken with roasted vegetables and quinoa");

    // Display the entries
    display_entry(diary);

    // Add some more entries
    add_entry(diary, "Breakfast", "Scrambled eggs with whole wheat toast and orange juice");
    add_entry(diary, "Lunch", "Turkey and cheese wrap with mixed greens and hummus");
    add_entry(diary, "Dinner", "Baked salmon with roasted sweet potatoes and green beans");

    // Display the updated entries
    display_entry(diary);

    free(diary);
    return 0;
}