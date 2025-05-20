//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Ada Lovelace's Analytical Engine
typedef struct {
    int year;
    int month;
    int day;
    char entry[1024];
} DiaryEntry;

// Linked list of diary entries
typedef struct {
    DiaryEntry entry;
    struct Diary *next;
} Diary;

// Create a new diary entry
Diary *new_entry(int year, int month, int day, char *entry) {
    Diary *new = malloc(sizeof(Diary));
    new->entry.year = year;
    new->entry.month = month;
    new->entry.day = day;
    strcpy(new->entry.entry, entry);
    new->next = NULL;
    return new;
}

// Add a new entry to the diary
void add_entry(Diary **diary, Diary *new) {
    if (*diary == NULL) {
        *diary = new;
    } else {
        Diary *current = *diary;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}

// Print the diary
void print_diary(Diary *diary) {
    while (diary != NULL) {
        printf("%d-%02d-%02d: %s\n", diary->entry.year, diary->entry.month, diary->entry.day, diary->entry.entry);
        diary = diary->next;
    }
}

// Free the memory allocated for the diary
void free_diary(Diary *diary) {
    while (diary != NULL) {
        Diary *next = diary->next;
        free(diary);
        diary = next;
    }
}

int main() {
    // Create a new diary
    Diary *diary = NULL;

    // Add some entries to the diary
    add_entry(&diary, new_entry(1843, 6, 15, "Today, I have begun my work on the Analytical Engine."));
    add_entry(&diary, new_entry(1843, 6, 16, "I have made some progress on the Analytical Engine."));
    add_entry(&diary, new_entry(1843, 6, 17, "I have completed the design of the Analytical Engine."));

    // Print the diary
    print_diary(diary);

    // Free the memory allocated for the diary
    free_diary(diary);

    return 0;
}