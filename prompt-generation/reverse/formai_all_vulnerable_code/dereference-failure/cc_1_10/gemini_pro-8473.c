//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our diary structure
typedef struct {
    char *title;
    char *body;
    int date;
} DiaryEntry;

// Create a new diary entry
DiaryEntry* new_entry(char *title, char *body, int date) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->title = strdup(title);
    entry->body = strdup(body);
    entry->date = date;
    return entry;
}

// Free a diary entry
void free_entry(DiaryEntry *entry) {
    free(entry->title);
    free(entry->body);
    free(entry);
}

// Print a diary entry
void print_entry(DiaryEntry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Body: %s\n", entry->body);
    printf("Date: %d\n", entry->date);
}

// Main function
int main() {
    // Create a new diary
    DiaryEntry *diary = malloc(sizeof(DiaryEntry) * 10);

    // Add some entries to the diary
    diary[0] = *new_entry("My First Entry", "This is my first diary entry. I'm so excited to start writing in it!", 20230101);
    diary[1] = *new_entry("My Second Entry", "Today I went to the park with my friends. We had a lot of fun playing on the swings and slides.", 20230102);
    diary[2] = *new_entry("My Third Entry", "Today I learned how to ride a bike! I'm so proud of myself.", 20230103);

    // Print the diary
    for (int i = 0; i < 3; i++) {
        print_entry(&diary[i]);
        printf("\n");
    }

    // Free the diary
    for (int i = 0; i < 3; i++) {
        free_entry(&diary[i]);
    }
    free(diary);

    return 0;
}