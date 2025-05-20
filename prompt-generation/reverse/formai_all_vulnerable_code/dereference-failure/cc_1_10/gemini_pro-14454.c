//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_NUM_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    char date[11];
    char title[50];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Define the structure of the digital diary
typedef struct {
    DiaryEntry entries[MAX_NUM_ENTRIES];
    int num_entries;
} DigitalDiary;

// Create a new digital diary
DigitalDiary* create_digital_diary() {
    DigitalDiary* diary = malloc(sizeof(DigitalDiary));
    if (diary == NULL) {
        return NULL;
    }

    diary->num_entries = 0;

    return diary;
}

// Add a new entry to the digital diary
int add_entry(DigitalDiary* diary, char* date, char* title, char* entry) {
    if (diary->num_entries >= MAX_NUM_ENTRIES) {
        return -1;
    }

    strcpy(diary->entries[diary->num_entries].date, date);
    strcpy(diary->entries[diary->num_entries].title, title);
    strcpy(diary->entries[diary->num_entries].entry, entry);

    diary->num_entries++;

    return 0;
}

// Get an entry from the digital diary
DiaryEntry* get_entry(DigitalDiary* diary, int index) {
    if (index < 0 || index >= diary->num_entries) {
        return NULL;
    }

    return &diary->entries[index];
}

// Print the digital diary
void print_diary(DigitalDiary* diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Date: %s\n", diary->entries[i].date);
        printf("Title: %s\n", diary->entries[i].title);
        printf("Entry: %s\n\n", diary->entries[i].entry);
    }
}

// Free the memory allocated for the digital diary
void free_digital_diary(DigitalDiary* diary) {
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    DigitalDiary* diary = create_digital_diary();

    // Add some entries to the digital diary
    add_entry(diary, "2023-01-01", "My New Year's Resolution", "I resolve to be more productive this year.");
    add_entry(diary, "2023-01-02", "My First Day of Work", "I started my new job today. It's going to be a challenge, but I'm excited to learn new things.");
    add_entry(diary, "2023-01-03", "My First Date", "I went on my first date with someone new. It was a lot of fun, and I'm hoping to see them again.");

    // Print the digital diary
    print_diary(diary);

    printf("What entry do you want me to get\n");
    int index;
    scanf("%d", &index);

    // Get an entry from the digital diary
    DiaryEntry* entry = get_entry(diary, index);

    // Print the entry
    printf("Date: %s\n", entry->date);
    printf("Title: %s\n", entry->title);
    printf("Entry: %s\n\n", entry->entry);

    // Free the memory allocated for the digital diary
    free_digital_diary(diary);

    return 0;
}