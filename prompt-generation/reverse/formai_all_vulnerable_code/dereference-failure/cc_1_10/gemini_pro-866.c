//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIARY_ENTRIES 100
#define MAX_ENTRY_LENGTH 1024

// Structure to store a diary entry
typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry* create_diary_entry(char* entry) {
    // Allocate memory for the new entry
    DiaryEntry* new_entry = malloc(sizeof(DiaryEntry));

    // Set the timestamp to the current time
    new_entry->timestamp = time(NULL);

    // Copy the entry text into the new entry
    strcpy(new_entry->entry, entry);

    // Return the new entry
    return new_entry;
}

// Function to add a new diary entry to the diary
void add_diary_entry(DiaryEntry* diary, DiaryEntry* new_entry) {
    // Find the first empty slot in the diary
    int i;
    for (i = 0; i < MAX_DIARY_ENTRIES; i++) {
        if (diary[i].timestamp == 0) {
            break;
        }
    }

    // If there are no empty slots, reallocate the diary to make more space
    if (i == MAX_DIARY_ENTRIES) {
        diary = realloc(diary, sizeof(DiaryEntry) * (MAX_DIARY_ENTRIES + 10));
    }

    // Copy the new entry into the empty slot
    diary[i] = *new_entry;
}

// Function to print a diary entry
void print_diary_entry(DiaryEntry* entry) {
    // Print the timestamp
    printf("%s", ctime(&entry->timestamp));

    // Print the entry text
    printf("%s\n", entry->entry);
}

// Function to print the entire diary
void print_diary(DiaryEntry* diary) {
    // Print each entry in the diary
    int i;
    for (i = 0; i < MAX_DIARY_ENTRIES; i++) {
        if (diary[i].timestamp != 0) {
            print_diary_entry(&diary[i]);
        }
    }
}

// Main function
int main() {
    // Create a new diary
    DiaryEntry* diary = malloc(sizeof(DiaryEntry) * MAX_DIARY_ENTRIES);

    // Add some sample entries to the diary
    add_diary_entry(diary, create_diary_entry("Dear Diary,\n\nToday was a good day. I woke up feeling refreshed and excited to start the day. I had a delicious breakfast of oatmeal and berries, and then I went for a walk in the park. The weather was perfect, and I enjoyed the fresh air and sunshine. After my walk, I came home and worked on my writing for a few hours. I'm really enjoying the story I'm working on, and I'm making good progress. In the evening, I met up with some friends for dinner. We had a great time catching up and laughing together. I'm so grateful for my friends and family. I feel so lucky to have them in my life.\n\nLove,\n[Your name]"));
    add_diary_entry(diary, create_diary_entry("Dear Diary,\n\nToday was a challenging day. I had a big presentation at work, and I was really nervous. But I prepared as much as I could, and I think it went well. I'm still waiting to hear back from my boss, but I'm hoping for the best. After work, I went to the gym to blow off some steam. I had a great workout, and I feel much better now. I'm going to relax for the rest of the evening and watch some TV. I'm hoping tomorrow will be a better day.\n\nLove,\n[Your name]"));

    // Print the diary
    print_diary(diary);

    // Free the memory allocated for the diary
    free(diary);

    return 0;
}