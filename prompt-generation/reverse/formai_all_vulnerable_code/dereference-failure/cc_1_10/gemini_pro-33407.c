//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Romeo and Juliet style digital diary

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    time_t timestamp;            // The date and time of the entry
    char *text;                  // The text of the entry
} diary_entry;

// Define the structure of the digital diary
typedef struct {
    diary_entry entries[MAX_ENTRIES];    // The diary entries
    int num_entries;                // The number of diary entries
} digital_diary;

// Create a new digital diary
digital_diary *create_digital_diary() {
    digital_diary *diary = malloc(sizeof(digital_diary));
    if (diary == NULL) {
        return NULL;
    }
    
    diary->num_entries = 0;
    
    return diary;
}

// Add a new entry to the digital diary
void add_entry(digital_diary *diary, char *text) {
    if (diary->num_entries == MAX_ENTRIES) {
        printf("Error: The diary is full.\n");
        return;
    }
    
    diary->entries[diary->num_entries].timestamp = time(NULL);
    diary->entries[diary->num_entries].text = strdup(text);
    diary->num_entries++;
}

// Print the entries in the digital diary
void print_entries(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n", diary->entries[i].text);
    }
}

// Free the memory allocated for the digital diary
void free_digital_diary(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].text);
    }
    
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    digital_diary *diary = create_digital_diary();
    
    // Add some entries to the diary
    add_entry(diary, "My heart is full of love for thee, my dear Romeo.");
    add_entry(diary, "I wouldst fain die with thee than live without thee.");
    add_entry(diary, "O Romeo, Romeo! Wherefore art thou Romeo?");
    
    // Print the entries in the diary
    print_entries(diary);
    
    // Free the memory allocated for the digital diary
    free_digital_diary(diary);
    
    return 0;
}