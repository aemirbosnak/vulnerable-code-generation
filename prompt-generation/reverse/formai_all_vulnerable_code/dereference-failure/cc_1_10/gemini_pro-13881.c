//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for a diary entry
typedef struct {
    char *title;
    char *content;
    int year;
    int month;
    int day;
} DiaryEntry;

// Create a new diary entry
DiaryEntry *create_diary_entry(char *title, char *content, int year, int month, int day) {
    DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
    new_entry->title = malloc(strlen(title) + 1);
    strcpy(new_entry->title, title);
    new_entry->content = malloc(strlen(content) + 1);
    strcpy(new_entry->content, content);
    new_entry->year = year;
    new_entry->month = month;
    new_entry->day = day;
    return new_entry;
}

// Free a diary entry
void free_diary_entry(DiaryEntry *entry) {
    free(entry->title);
    free(entry->content);
    free(entry);
}

// Print a diary entry
void print_diary_entry(DiaryEntry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Date: %d-%d-%d\n", entry->year, entry->month, entry->day);
}

// Main function
int main() {
    // Create a new diary entry
    DiaryEntry *entry = create_diary_entry("My First Diary Entry", "This is my first diary entry. I'm going to write about my day today.", 2023, 1, 1);

    // Print the diary entry
    print_diary_entry(entry);

    // Free the diary entry
    free_diary_entry(entry);

    return 0;
}