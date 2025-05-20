//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a 日記 entry
typedef struct {
    char *title;       // Title of the entry
    char *date;        // Date of the entry
    char *content;     // Content of the entry
} DiaryEntry;

// Function to create a new 日記 entry
DiaryEntry *create_entry(char *title, char *date, char *content) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->title = strdup(title);
    entry->date = strdup(date);
    entry->content = strdup(content);
    return entry;
}

// Function to free the memory allocated for a 日記 entry
void free_entry(DiaryEntry *entry) {
    free(entry->title);
    free(entry->date);
    free(entry->content);
    free(entry);
}

// Function to add a new 日記 entry to a file
void add_entry(char *filename, DiaryEntry *entry) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%s\n", entry->title);
    fprintf(fp, "%s\n", entry->date);
    fprintf(fp, "%s\n", entry->content);
    fprintf(fp, "\n");

    fclose(fp);
}

// Function to read 日記 entries from a file
DiaryEntry **read_entries(char *filename, int *num_entries) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Count the number of 日記 entries in the file
    int count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strlen(line) > 1) {
            count++;
        }
    }

    // Allocate memory for the 日記 entries
    DiaryEntry **entries = malloc(sizeof(DiaryEntry *) * count);

    // Read the 日記 entries from the file
    rewind(fp);
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strlen(line) > 1) {
            char *title = strdup(line);
            fgets(line, sizeof(line), fp);
            char *date = strdup(line);
            fgets(line, sizeof(line), fp);
            char *content = strdup(line);
            entries[i] = create_entry(title, date, content);
            i++;
        }
    }

    fclose(fp);

    *num_entries = count;
    return entries;
}

// Function to print a 日記 entry
void print_entry(DiaryEntry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Date: %s\n", entry->date);
    printf("Content: %s\n\n", entry->content);
}

// Function to search for a 日記 entry by title
DiaryEntry *search_entry(DiaryEntry **entries, int num_entries, char *title) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i]->title, title) == 0) {
            return entries[i];
        }
    }

    return NULL;
}

int main() {
    // Create a new 日記 entry
    DiaryEntry *entry = create_entry("My First 日記 Entry", "2023-01-01", "This is my first 日記 entry. I'm going to use this to keep track of my thoughts and feelings.");

    // Add the 日記 entry to the file
    add_entry("my_diary.txt", entry);

    // Read the 日記 entries from the file
    int num_entries;
    DiaryEntry **entries = read_entries("my_diary.txt", &num_entries);

    // Print the 日記 entries
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }

    // Search for a 日記 entry by title
    DiaryEntry *entry2 = search_entry(entries, num_entries, "My First 日記 Entry");

    // Print the 日記 entry
    print_entry(entry2);

    // Free the memory allocated for the 日記 entries
    for (int i = 0; i < num_entries; i++) {
        free_entry(entries[i]);
    }
    free(entries);

    return 0;
}