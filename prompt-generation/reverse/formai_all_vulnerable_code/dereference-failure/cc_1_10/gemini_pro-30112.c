//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: calm
/* C Digital Diary Example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a diary entry
typedef struct {
    char date[11]; // Format: "YYYY-MM-DD"
    char title[51];
    char content[1024];
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry* create_entry(char* date, char* title, char* content) {
    DiaryEntry* entry = malloc(sizeof(DiaryEntry));
    if (entry == NULL) return NULL; // Error handling: malloc failed

    strcpy(entry->date, date);
    strcpy(entry->title, title);
    strcpy(entry->content, content);

    return entry;
}

// Function to print a diary entry
void print_entry(DiaryEntry* entry) {
    printf("Date: %s\n", entry->date);
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("\n");
}

// Function to add a new diary entry to a file
int add_entry_to_file(char* filename, DiaryEntry* entry) {
    FILE* fp = fopen(filename, "a");
    if (fp == NULL) return -1; // Error handling: fopen failed

    fprintf(fp, "%s|%s|%s\n", entry->date, entry->title, entry->content);
    fclose(fp);

    return 0;
}

// Function to read diary entries from a file
int read_entries_from_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) return -1; // Error handling: fopen failed

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the line into its components
        char* date = strtok(line, "|");
        char* title = strtok(NULL, "|");
        char* content = strtok(NULL, "|");

        // Create a new diary entry
        DiaryEntry* entry = create_entry(date, title, content);

        // Print the diary entry
        print_entry(entry);

        // Free the memory allocated for the diary entry
        free(entry);
    }

    fclose(fp);

    return 0;
}

// Main function
int main() {
    // Create a new diary entry
    DiaryEntry* entry = create_entry("2023-03-08", "My First Entry", "Today was a great day!");

    // Print the diary entry
    print_entry(entry);

    // Add the diary entry to a file
    int result = add_entry_to_file("diary.txt", entry);
    if (result != 0) {
        printf("Error adding entry to file.\n");
        return 1;
    }

    // Read diary entries from a file
    result = read_entries_from_file("diary.txt");
    if (result != 0) {
        printf("Error reading entries from file.\n");
        return 1;
    }

    // Free the memory allocated for the diary entry
    free(entry);

    return 0;
}