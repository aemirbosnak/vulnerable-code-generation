//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure for the diary
typedef struct {
    char *title;
    char *content;
    time_t timestamp;
} Entry;

// Function to create a new entry
Entry *create_entry(char *title, char *content) {
    Entry *entry = malloc(sizeof(Entry));
    if (entry == NULL) {
        printf("Error: Could not allocate memory for entry.\n");
        return NULL;
    }

    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->timestamp = time(NULL);

    return entry;
}

// Function to free the memory allocated for an entry
void free_entry(Entry *entry) {
    if (entry == NULL) {
        return;
    }

    free(entry->title);
    free(entry->content);
    free(entry);
}

// Function to add an entry to the diary
int add_entry(Entry **entries, int *num_entries, Entry *entry) {
    if (entries == NULL || num_entries == NULL || entry == NULL) {
        return -1;
    }

    *entries = realloc(*entries, (*num_entries + 1) * sizeof(Entry));
    if (*entries == NULL) {
        printf("Error: Could not allocate memory for entries.\n");
        return -1;
    }

    (*entries)[*num_entries] = *entry;
    (*num_entries)++;

    return 0;
}

// Function to print the diary
void print_diary(Entry *entries, int num_entries) {
    if (entries == NULL || num_entries <= 0) {
        printf("Error: Diary is empty.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", entries[i].title);
        printf("Content: %s\n", entries[i].content);
        printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
        printf("\n");
    }
}

// Function to save the diary to a file
int save_diary(Entry *entries, int num_entries, char *filename) {
    if (entries == NULL || num_entries <= 0 || filename == NULL) {
        return -1;
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return -1;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s\n%s\n%ld\n\n", entries[i].title, entries[i].content, entries[i].timestamp);
    }

    fclose(file);

    return 0;
}

// Function to load the diary from a file
int load_diary(Entry **entries, int *num_entries, char *filename) {
    if (entries == NULL || num_entries == NULL || filename == NULL) {
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return -1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *title = strdup(line);
        char *content = strdup(fgets(line, sizeof(line), file));
        long timestamp = atol(fgets(line, sizeof(line), file));

        Entry *entry = create_entry(title, content);
        entry->timestamp = timestamp;

        add_entry(entries, num_entries, entry);

        free(title);
        free(content);
    }

    fclose(file);

    return 0;
}

// Main function
int main() {
    // Create an array of entries
    Entry *entries = NULL;
    int num_entries = 0;

    // Add some entries to the diary
    add_entry(&entries, &num_entries, create_entry("First entry", "This is my first entry."));
    add_entry(&entries, &num_entries, create_entry("Second entry", "This is my second entry."));
    add_entry(&entries, &num_entries, create_entry("Third entry", "This is my third entry."));

    // Print the diary
    print_diary(entries, num_entries);

    // Save the diary to a file
    save_diary(entries, num_entries, "diary.txt");

    // Load the diary from a file
    load_diary(&entries, &num_entries, "diary.txt");

    // Print the diary again
    print_diary(entries, num_entries);

    // Free the memory allocated for the entries
    for (int i = 0; i < num_entries; i++) {
        free_entry(&entries[i]);
    }
    free(entries);

    return 0;
}