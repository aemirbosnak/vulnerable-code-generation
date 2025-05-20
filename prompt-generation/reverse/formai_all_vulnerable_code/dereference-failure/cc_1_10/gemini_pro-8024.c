//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the diary entry structure
typedef struct {
    char *date;
    char *title;
    char *content;
} DiaryEntry;

// Create a new diary entry
DiaryEntry *new_diary_entry(char *date, char *title, char *content) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->date = malloc(strlen(date) + 1);
    strcpy(entry->date, date);
    entry->title = malloc(strlen(title) + 1);
    strcpy(entry->title, title);
    entry->content = malloc(strlen(content) + 1);
    strcpy(entry->content, content);
    return entry;
}

// Free the memory allocated for a diary entry
void free_diary_entry(DiaryEntry *entry) {
    free(entry->date);
    free(entry->title);
    free(entry->content);
    free(entry);
}

// Print a diary entry
void print_diary_entry(DiaryEntry *entry) {
    printf("Date: %s\n", entry->date);
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
}

// Get the current date and time
char *get_current_date_time() {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    char *date_time = malloc(26); // Assuming the date and time will be in the format "YYYY-MM-DD HH:MM:SS"
    strftime(date_time, 26, "%Y-%m-%d %H:%M:%S", current_time);
    return date_time;
}

// Main function
int main() {
    // Create a new diary entry
    char *date = get_current_date_time();
    char *title = "My First Diary Entry";
    char *content = "This is my first diary entry. I'm going to use this to keep track of my thoughts and experiences.";
    DiaryEntry *entry = new_diary_entry(date, title, content);

    // Print the diary entry
    print_diary_entry(entry);

    // Free the memory allocated for the diary entry
    free_diary_entry(entry);

    return 0;
}