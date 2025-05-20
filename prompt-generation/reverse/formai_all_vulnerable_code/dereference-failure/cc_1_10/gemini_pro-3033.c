//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structures
typedef struct Entry {
    char *timestamp;
    char *content;
} Entry;

typedef struct Diary {
    Entry *entries;
    int num_entries;
} Diary;

// Function declarations
void init_diary(Diary *diary);
void free_diary(Diary *diary);
Entry *create_entry(char *timestamp, char *content);
void add_entry(Diary *diary, Entry *entry);
void print_diary(Diary *diary);

// Main function
int main() {
    // Initialize the diary
    Diary diary;
    init_diary(&diary);

    // Add some entries to the diary
    char *timestamp1 = "2023-01-01 00:00:00";
    char *content1 = "This is my first entry!";
    Entry *entry1 = create_entry(timestamp1, content1);
    add_entry(&diary, entry1);

    char *timestamp2 = "2023-01-02 12:00:00";
    char *content2 = "Today I learned about artificial intelligence.";
    Entry *entry2 = create_entry(timestamp2, content2);
    add_entry(&diary, entry2);

    // Print the diary
    print_diary(&diary);

    // Free the diary
    free_diary(&diary);

    return 0;
}

// Function implementations
void init_diary(Diary *diary) {
    diary->entries = NULL;
    diary->num_entries = 0;
}

void free_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].timestamp);
        free(diary->entries[i].content);
    }
    free(diary->entries);
}

Entry *create_entry(char *timestamp, char *content) {
    Entry *entry = (Entry *)malloc(sizeof(Entry));
    entry->timestamp = (char *)malloc(strlen(timestamp) + 1);
    strcpy(entry->timestamp, timestamp);
    entry->content = (char *)malloc(strlen(content) + 1);
    strcpy(entry->content, content);
    return entry;
}

void add_entry(Diary *diary, Entry *entry) {
    diary->entries = (Entry *)realloc(diary->entries, (diary->num_entries + 1) * sizeof(Entry));
    diary->entries[diary->num_entries++] = *entry;
}

void print_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Timestamp: %s\n", diary->entries[i].timestamp);
        printf("Content: %s\n\n", diary->entries[i].content);
    }
}