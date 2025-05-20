//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1000

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct diary_entry {
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

// Create a new diary entry
diary_entry* create_entry(char* date, char* time, char* entry) {
    diary_entry* new_entry = malloc(sizeof(diary_entry));
    strcpy(new_entry->date, date);
    strcpy(new_entry->time, time);
    strcpy(new_entry->entry, entry);
    return new_entry;
}

// Add a new diary entry to the diary
void add_entry(diary_entry** diary, int* num_entries, diary_entry* new_entry) {
    diary[*num_entries] = new_entry;
    (*num_entries)++;
}

// Print a diary entry
void print_entry(diary_entry* entry) {
    printf("%s %s\n%s\n", entry->date, entry->time, entry->entry);
}

// Print all diary entries
void print_all_entries(diary_entry** diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_entry(diary[i]);
        printf("\n");
    }
}

// Free the memory allocated for a diary entry
void free_entry(diary_entry* entry) {
    free(entry);
}

// Free the memory allocated for the diary
void free_diary(diary_entry** diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free_entry(diary[i]);
    }
    free(diary);
}

// Main function
int main() {
    // Create a new diary
    diary_entry** diary = malloc(MAX_ENTRIES * sizeof(diary_entry*));
    int num_entries = 0;

    // Add some sample diary entries
    add_entry(diary, &num_entries, create_entry("2023-01-01", "09:00:00", "Today I woke up feeling refreshed and motivated. I went for a run and then I worked on my new project. I'm feeling really good about the future."));
    add_entry(diary, &num_entries, create_entry("2023-01-02", "12:00:00", "I had a great lunch with my friends today. We went to a new restaurant and I had the best pasta I've ever tasted. I'm so happy to have such wonderful friends."));
    add_entry(diary, &num_entries, create_entry("2023-01-03", "17:00:00", "I finished working on my project today and I'm really happy with how it turned out. I'm going to take a break for the rest of the day and relax. I'm feeling very proud of myself."));

    // Print all diary entries
    print_all_entries(diary, num_entries);

    // Free the memory allocated for the diary
    free_diary(diary, num_entries);

    return 0;
}