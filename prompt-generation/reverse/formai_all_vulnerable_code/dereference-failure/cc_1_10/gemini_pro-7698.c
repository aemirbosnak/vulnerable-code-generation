//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    time_t timestamp;
    char *text;
} DiaryEntry;

// Create a new diary entry
DiaryEntry *new_entry(time_t timestamp, char *text) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->timestamp = timestamp;
    entry->text = strdup(text);
    return entry;
}

// Free a diary entry
void free_entry(DiaryEntry *entry) {
    free(entry->text);
    free(entry);
}

// Add a new entry to the diary
void add_entry(DiaryEntry **entries, int *num_entries, time_t timestamp, char *text) {
    entries[*num_entries] = new_entry(timestamp, text);
    (*num_entries)++;
}

// Print the diary
void print_diary(DiaryEntry **entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", asctime(localtime(&entries[i]->timestamp)));
        printf("%s\n\n", entries[i]->text);
    }
}

// Main function
int main() {
    // Create an array of diary entries
    DiaryEntry *entries[MAX_ENTRIES];

    // Initialize the number of diary entries to 0
    int num_entries = 0;

    // Add some sample entries to the diary
    add_entry(entries, &num_entries, time(NULL), "Dear Diary,\n\nToday was a great day! I woke up feeling refreshed and full of energy. I went for a walk in the park and enjoyed the beautiful weather. I also met some new friends and had some great conversations. I'm so grateful for all the good things in my life.");
    add_entry(entries, &num_entries, time(NULL), "Dear Diary,\n\nToday was a bit of a bummer. I had a fight with my friend and I'm feeling really down. I don't know what to do. I just want to crawl into a hole and hide. I hope tomorrow is a better day.");
    add_entry(entries, &num_entries, time(NULL), "Dear Diary,\n\nToday was a good day. I went to the library and read some books. I also worked on my new project and made some good progress. I'm feeling really good about the future. I know that I can achieve anything I set my mind to.");

    // Print the diary
    print_diary(entries, num_entries);

    // Free the diary entries
    for (int i = 0; i < num_entries; i++) {
        free_entry(entries[i]);
    }

    return 0;
}