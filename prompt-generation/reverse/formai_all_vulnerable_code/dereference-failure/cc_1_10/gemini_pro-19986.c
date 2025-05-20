//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
typedef struct {
    char timestamp[20];    // Timestamp of the entry
    char title[50];       // Title of the entry
    char content[1024];    // Content of the entry
} Entry;

// Diary structure
typedef struct {
    int num_entries;    // Number of entries in the diary
    Entry entries[100]; // Array of entries
} Diary;

// Function to create a new diary
Diary *create_diary() {
    Diary *diary = malloc(sizeof(Diary));
    if (diary == NULL) {
        printf("Error: Could not allocate memory for diary.\n");
        return NULL;
    }

    diary->num_entries = 0;
    return diary;
}

// Function to add an entry to the diary
void add_entry(Diary *diary, char *title, char *content) {
    // Check if the diary is full
    if (diary->num_entries == 100) {
        printf("Error: Diary is full.\n");
        return;
    }

    // Get the current timestamp
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(diary->entries[diary->num_entries].timestamp, 20, "%Y-%m-%d %H:%M:%S", tm);

    // Copy the title and content into the entry
    strcpy(diary->entries[diary->num_entries].title, title);
    strcpy(diary->entries[diary->num_entries].content, content);

    // Increment the number of entries
    diary->num_entries++;
}

// Function to print the diary
void print_diary(Diary *diary) {
    printf("** Digital Diary **\n");
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Timestamp: %s\n", diary->entries[i].timestamp);
        printf("Title: %s\n", diary->entries[i].title);
        printf("Content: %s\n\n", diary->entries[i].content);
    }
}

// Function to free the memory allocated for the diary
void free_diary(Diary *diary) {
    free(diary);
}

// Main function
int main() {
    // Create a new diary
    Diary *diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "Day 1", "Today was a great day! I woke up feeling refreshed and motivated. I went for a run, had a delicious breakfast, and then spent the morning working on my new project. I'm really excited about this project and I can't wait to see what the future holds.");
    add_entry(diary, "Day 2", "Today was a bit more challenging. I had a meeting that didn't go so well, and I got into an argument with a friend. But I'm trying to stay positive and focus on the good things. I know that tomorrow will be a better day.");
    add_entry(diary, "Day 3", "Today was a great day! I spent the day with my family and friends. We went to the park, had a picnic, and played games. It was so much fun to be surrounded by the people I love. I'm so grateful for my family and friends.");

    // Print the diary
    print_diary(diary);

    // Free the memory allocated for the diary
    free_diary(diary);

    return 0;
}