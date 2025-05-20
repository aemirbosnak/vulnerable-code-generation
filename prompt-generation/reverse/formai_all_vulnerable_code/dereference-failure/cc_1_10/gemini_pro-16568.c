//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the number of diary entries to keep
#define NUM_ENTRIES 10

// Define the file name of the diary
#define DIARY_FILE "diary.txt"

// Define the structure of a diary entry
typedef struct {
    char *entry;
    time_t timestamp;
} DiaryEntry;

// Create a new diary entry
DiaryEntry *create_entry(char *entry) {
    DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
    new_entry->entry = strdup(entry);
    new_entry->timestamp = time(NULL);
    return new_entry;
}

// Add a new diary entry to the diary file
void add_entry(DiaryEntry *entry) {
    FILE *fp = fopen(DIARY_FILE, "a");
    if (fp == NULL) {
        perror("Error opening diary file");
        exit(1);
    }

    // Write the entry to the file
    fprintf(fp, "%s\n%ld\n", entry->entry, entry->timestamp);
    fclose(fp);
}

// Read the diary entries from the file
DiaryEntry **read_entries() {
    FILE *fp = fopen(DIARY_FILE, "r");
    if (fp == NULL) {
        perror("Error opening diary file");
        exit(1);
    }

    // Read the entries from the file
    DiaryEntry **entries = malloc(sizeof(DiaryEntry *) * NUM_ENTRIES);
    char *line = NULL;
    size_t len = 0;
    int i = 0;
    while (getline(&line, &len, fp) != -1) {
        // Create a new entry
        DiaryEntry *entry = create_entry(line);

        // Add the entry to the array
        entries[i++] = entry;
    }

    fclose(fp);
    return entries;
}

// Print the diary entries
void print_entries(DiaryEntry **entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        // Print the entry
        printf("%s\n", entries[i]->entry);

        // Print the timestamp
        char *ctime_str = ctime(&entries[i]->timestamp);
        printf("%s\n", ctime_str);
    }
}

// Free the memory allocated for the diary entries
void free_entries(DiaryEntry **entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        // Free the entry
        free(entries[i]->entry);
        free(entries[i]);
    }

    // Free the array
    free(entries);
}

// Main function
int main() {
    // Create a new diary entry
    char *entry = "Dear Diary,\n\nToday was a great day! I went for a walk in the park and saw some beautiful flowers. I also met a new friend and we had a great conversation. I'm so grateful for all the good things in my life.\n\nLove,\n[Your Name]";
    DiaryEntry *new_entry = create_entry(entry);

    // Add the new entry to the diary file
    add_entry(new_entry);

    // Read the diary entries from the file
    DiaryEntry **entries = read_entries();

    // Print the diary entries
    print_entries(entries, NUM_ENTRIES);

    // Free the memory allocated for the diary entries
    free_entries(entries, NUM_ENTRIES);

    return 0;
}