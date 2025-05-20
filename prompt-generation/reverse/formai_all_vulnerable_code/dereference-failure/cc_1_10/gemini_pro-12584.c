//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a diary entry
typedef struct {
    char date[11];
    char time[6];
    char title[51];
    char content[1024];
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry* createEntry(char* date, char* time, char* title, char* content) {
    DiaryEntry* entry = (DiaryEntry*) malloc(sizeof(DiaryEntry));
    strcpy(entry->date, date);
    strcpy(entry->time, time);
    strcpy(entry->title, title);
    strcpy(entry->content, content);
    return entry;
}

// Function to print a diary entry
void printEntry(DiaryEntry* entry) {
    printf("Date: %s\n", entry->date);
    printf("Time: %s\n", entry->time);
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n\n", entry->content);
}

// Function to add a new diary entry to a file
void addEntryToFile(DiaryEntry* entry, FILE* file) {
    fprintf(file, "%s,%s,%s,%s\n", entry->date, entry->time, entry->title, entry->content);
}

// Function to load all diary entries from a file
DiaryEntry** loadEntriesFromFile(FILE* file, int* numEntries) {
    char line[1024];
    DiaryEntry** entries = NULL;
    *numEntries = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Parse the line into date, time, title, and content
        char* date = strtok(line, ",");
        char* time = strtok(NULL, ",");
        char* title = strtok(NULL, ",");
        char* content = strtok(NULL, ",");

        // Create a new diary entry
        DiaryEntry* entry = createEntry(date, time, title, content);

        // Add the entry to the array
        entries = (DiaryEntry**) realloc(entries, (*numEntries + 1) * sizeof(DiaryEntry*));
        entries[*numEntries] = entry;

        // Increment the number of entries
        (*numEntries)++;
    }

    return entries;
}

// Function to print all diary entries
void printAllEntries(DiaryEntry** entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printEntry(entries[i]);
    }
}

// Function to free all diary entries
void freeAllEntries(DiaryEntry** entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        free(entries[i]);
    }
    free(entries);
}

// Main function
int main() {
    // Create a new diary entry
    DiaryEntry* entry = createEntry("2023-03-08", "10:00", "My first diary entry", "This is my first diary entry. I'm going to use it to track my thoughts and feelings.");

    // Add the entry to a file
    FILE* file = fopen("diary.txt", "a");
    addEntryToFile(entry, file);
    fclose(file);

    // Load all diary entries from the file
    file = fopen("diary.txt", "r");
    int numEntries;
    DiaryEntry** entries = loadEntriesFromFile(file, &numEntries);
    fclose(file);

    // Print all diary entries
    printAllEntries(entries, numEntries);

    // Free all diary entries
    freeAllEntries(entries, numEntries);

    return 0;
}