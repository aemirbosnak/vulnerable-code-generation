//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a diary entry
typedef struct {
    char *date;
    char *time;
    char *entry;
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry *create_diary_entry(char *date, char *time, char *entry) {
    DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
    new_entry->date = malloc(strlen(date) + 1);
    new_entry->time = malloc(strlen(time) + 1);
    new_entry->entry = malloc(strlen(entry) + 1);
    strcpy(new_entry->date, date);
    strcpy(new_entry->time, time);
    strcpy(new_entry->entry, entry);
    return new_entry;
}

// Function to add a new diary entry to a file
void add_diary_entry(char *filename, DiaryEntry *entry) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(fp, "%s %s %s\n", entry->date, entry->time, entry->entry);
    fclose(fp);
}

// Function to read all diary entries from a file
DiaryEntry **read_diary_entries(char *filename, int *num_entries) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }
    int line_count = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        line_count++;
    }
    *num_entries = line_count;
    DiaryEntry **entries = malloc(sizeof(DiaryEntry *) * line_count);
    rewind(fp);
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *date = strtok(line, " ");
        char *time = strtok(NULL, " ");
        char *entry = strtok(NULL, "\n");
        entries[i] = create_diary_entry(date, time, entry);
        i++;
    }
    fclose(fp);
    return entries;
}

// Function to print all diary entries
void print_diary_entries(DiaryEntry **entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s\n", entries[i]->date, entries[i]->time, entries[i]->entry);
    }
}

// Function to free all diary entries
void free_diary_entries(DiaryEntry **entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free(entries[i]->date);
        free(entries[i]->time);
        free(entries[i]->entry);
        free(entries[i]);
    }
    free(entries);
}

// Main function
int main() {
    // Create a new diary entry
    char *date = "2023-03-08";
    char *time = "10:00 AM";
    char *entry = "Today I went for a walk in the park. It was a beautiful day and I saw a lot of birds and squirrels. I also saw a group of children playing soccer. It made me smile to see them having so much fun.";
    DiaryEntry *new_entry = create_diary_entry(date, time, entry);

    // Add the new diary entry to a file
    add_diary_entry("diary.txt", new_entry);

    // Read all diary entries from the file
    int num_entries;
    DiaryEntry **entries = read_diary_entries("diary.txt", &num_entries);

    // Print all diary entries
    print_diary_entries(entries, num_entries);

    // Free all diary entries
    free_diary_entries(entries, num_entries);

    return 0;
}