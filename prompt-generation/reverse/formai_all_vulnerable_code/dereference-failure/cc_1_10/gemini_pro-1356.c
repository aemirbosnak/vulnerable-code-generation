//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store diary entry
typedef struct {
    char date[11];
    char title[51];
    char content[1024];
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry* create_entry() {
    DiaryEntry* entry = malloc(sizeof(DiaryEntry));

    // Get current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Format date string
    strftime(entry->date, sizeof(entry->date), "%Y-%m-%d", tm);

    // Prompt user for title and content
    printf("Title: ");
    fgets(entry->title, sizeof(entry->title), stdin);

    printf("Content: ");
    fgets(entry->content, sizeof(entry->content), stdin);

    return entry;
}

// Function to print a diary entry
void print_entry(DiaryEntry* entry) {
    printf("Date: %s\n", entry->date);
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n\n", entry->content);
}

// Function to save a diary entry to a file
void save_entry(DiaryEntry* entry, FILE* file) {
    fprintf(file, "%s\n", entry->date);
    fprintf(file, "%s\n", entry->title);
    fprintf(file, "%s\n\n", entry->content);
}

// Function to load a diary entry from a file
DiaryEntry* load_entry(FILE* file) {
    DiaryEntry* entry = malloc(sizeof(DiaryEntry));

    // Read date, title, and content from file
    fscanf(file, "%s\n", entry->date);
    fscanf(file, "%s\n", entry->title);
    fscanf(file, "%[^\n]\n\n", entry->content);

    return entry;
}

// Main function
int main() {
    // Create a new diary file
    FILE* file = fopen("diary.txt", "w+");

    // Prompt user for number of entries
    int num_entries;
    printf("How many entries would you like to make? ");
    scanf("%d", &num_entries);

    // Create and save entries
    for (int i = 0; i < num_entries; i++) {
        DiaryEntry* entry = create_entry();
        save_entry(entry, file);
    }

    // Go back to the beginning of the file
    fseek(file, 0, SEEK_SET);

    // Load and print entries
    DiaryEntry* entry;
    while ((entry = load_entry(file)) != NULL) {
        print_entry(entry);
    }

    // Close the file
    fclose(file);

    return 0;
}