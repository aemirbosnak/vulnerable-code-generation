//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    char *title;
    char *body;
    time_t timestamp;
} diary_entry;

// Define the structure of the digital diary
typedef struct {
    diary_entry entries[MAX_ENTRIES];
    int num_entries;
} digital_diary;

// Create a new digital diary
digital_diary *create_diary() {
    digital_diary *diary = malloc(sizeof(digital_diary));
    if (diary == NULL) {
        return NULL;
    }
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to the digital diary
int add_entry(digital_diary *diary, char *title, char *body) {
    if (diary->num_entries == MAX_ENTRIES) {
        return -1;
    }
    diary_entry *entry = &diary->entries[diary->num_entries++];
    entry->title = strdup(title);
    entry->body = strdup(body);
    entry->timestamp = time(NULL);
    return 0;
}

// Get an entry from the digital diary by its index
diary_entry *get_entry(digital_diary *diary, int index) {
    if (index < 0 || index >= diary->num_entries) {
        return NULL;
    }
    return &diary->entries[index];
}

// Print an entry to the console
void print_entry(diary_entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Body: %s\n", entry->body);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

// Free the memory allocated for a digital diary
void free_diary(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].body);
    }
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    digital_diary *diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "My First Entry", "This is my first entry in my digital diary. I'm so excited to be able to track my thoughts and experiences in one place.");
    add_entry(diary, "A Day at the Beach", "Today I went to the beach with my friends. We had a great time swimming, sunbathing, and building sandcastles. I even saw a dolphin!");
    add_entry(diary, "A Night Out with Friends", "I went out with my friends last night to celebrate my birthday. We had dinner at a great restaurant and then went dancing at a club. I had a blast!");

    // Print the entries to the console
    for (int i = 0; i < diary->num_entries; i++) {
        print_entry(get_entry(diary, i));
        printf("\n");
    }

    // Free the memory allocated for the diary
    free_diary(diary);

    return 0;
}