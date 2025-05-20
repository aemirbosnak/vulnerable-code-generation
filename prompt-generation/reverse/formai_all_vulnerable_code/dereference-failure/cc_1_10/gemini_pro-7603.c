//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a diary entry
typedef struct {
    char date[11];
    char time[9];
    char title[51];
    char content[1001];
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry* createEntry(char *date, char *time, char *title, char *content) {
    DiaryEntry *entry = (DiaryEntry*)malloc(sizeof(DiaryEntry));
    strcpy(entry->date, date);
    strcpy(entry->time, time);
    strcpy(entry->title, title);
    strcpy(entry->content, content);
    return entry;
}

// Function to print a diary entry
void printEntry(DiaryEntry *entry) {
    printf("Date: %s\n", entry->date);
    printf("Time: %s\n", entry->time);
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n\n", entry->content);
}

// Function to add a new diary entry to a file
void addEntryToFile(DiaryEntry *entry, char *filename) {
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%s|%s|%s|%s\n", entry->date, entry->time, entry->title, entry->content);
    fclose(fp);
}

// Function to load all diary entries from a file
DiaryEntry** loadEntriesFromFile(char *filename, int *numEntries) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        *numEntries = 0;
        return NULL;
    }
    
    int count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        count++;
    }
    fclose(fp);
    
    *numEntries = count;
    
    DiaryEntry **entries = (DiaryEntry**)malloc(sizeof(DiaryEntry*) * count);
    
    fp = fopen(filename, "r");
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *date = strtok(line, "|");
        char *time = strtok(NULL, "|");
        char *title = strtok(NULL, "|");
        char *content = strtok(NULL, "|");
        entries[i++] = createEntry(date, time, title, content);
    }
    fclose(fp);
    
    return entries;
}

// Function to print all diary entries
void printEntries(DiaryEntry **entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printEntry(entries[i]);
    }
}

// Function to free all diary entries
void freeEntries(DiaryEntry **entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        free(entries[i]);
    }
    free(entries);
}

// Main function
int main() {
    // Create a new diary entry
    DiaryEntry *entry = createEntry("2023-01-01", "10:00:00", "My First Entry", "This is my first diary entry. I'm so excited to start writing in a diary! I've always wanted to keep a diary, but I never knew what to write about. Now I have a whole year to fill up with my thoughts and feelings.");
    
    // Print the diary entry
    printEntry(entry);
    
    // Add the diary entry to a file
    addEntryToFile(entry, "diary.txt");
    
    // Load all diary entries from the file
    int numEntries;
    DiaryEntry **entries = loadEntriesFromFile("diary.txt", &numEntries);
    
    // Print all diary entries
    printEntries(entries, numEntries);
    
    // Free all diary entries
    freeEntries(entries, numEntries);
    
    return 0;
}