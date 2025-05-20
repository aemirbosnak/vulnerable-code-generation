//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store a diary entry
typedef struct {
    char *date;
    char *time;
    char *entry;
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry *create_diary_entry(char *date, char *time, char *entry) {
    DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
    new_entry->date = malloc(strlen(date) + 1);
    strcpy(new_entry->date, date);
    new_entry->time = malloc(strlen(time) + 1);
    strcpy(new_entry->time, time);
    new_entry->entry = malloc(strlen(entry) + 1);
    strcpy(new_entry->entry, entry);
    return new_entry;
}

// Function to print a diary entry
void print_diary_entry(DiaryEntry *entry) {
    printf("Date: %s\n", entry->date);
    printf("Time: %s\n", entry->time);
    printf("Entry: %s\n", entry->entry);
}

// Function to add a diary entry to a file
int add_entry_to_file(char *filename, DiaryEntry *entry) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        return -1;
    }
    fprintf(fp, "%s %s %s\n", entry->date, entry->time, entry->entry);
    fclose(fp);
    return 0;
}

// Function to read diary entries from a file
DiaryEntry **read_entries_from_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }
    int num_entries = 0;
    fscanf(fp, "%d", &num_entries);
    DiaryEntry **entries = malloc(num_entries * sizeof(DiaryEntry *));
    for (int i = 0; i < num_entries; i++) {
        char date[11];
        char time[9];
        char entry[1024];
        fscanf(fp, "%s %s %[^\n]s", date, time, entry);
        entries[i] = create_diary_entry(date, time, entry);
    }
    fclose(fp);
    return entries;
}

// Function to free the memory allocated for a diary entry
void free_diary_entry(DiaryEntry *entry) {
    free(entry->date);
    free(entry->time);
    free(entry->entry);
    free(entry);
}

// Function to free the memory allocated for an array of diary entries
void free_diary_entries(DiaryEntry **entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free_diary_entry(entries[i]);
    }
    free(entries);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Get the current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[11];
    char time[9];
    strftime(date, sizeof(date), "%Y-%m-%d", tm);
    strftime(time, sizeof(time), "%H:%M:%S", tm);

    // Prompt the user for a diary entry
    printf("What's on your mind today? ");
    char entry[1024];
    fgets(entry, sizeof(entry), stdin);

    // Create a new diary entry
    DiaryEntry *new_entry = create_diary_entry(date, time, entry);

    // Add the diary entry to the file
    int status = add_entry_to_file(argv[1], new_entry);
    if (status == -1) {
        printf("Error writing to file\n");
        return -1;
    }

    // Print the diary entry to the console
    printf("Your entry has been saved.\n");
    print_diary_entry(new_entry);

    // Free the memory allocated for the diary entry
    free_diary_entry(new_entry);

    return 0;
}