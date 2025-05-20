//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
typedef struct entry {
    char *text;
    time_t timestamp;
} entry_t;

// Diary structure
typedef struct diary {
    entry_t *entries;
    int num_entries;
    int capacity;
} diary_t;

// Create a new diary
diary_t *diary_new() {
    diary_t *diary = malloc(sizeof(diary_t));
    diary->entries = NULL;
    diary->num_entries = 0;
    diary->capacity = 0;
    return diary;
}

// Add a new entry to the diary
void diary_add_entry(diary_t *diary, char *text) {
    // Resize the entries array if needed
    if (diary->num_entries == diary->capacity) {
        diary->capacity = diary->capacity == 0 ? 1 : diary->capacity * 2;
        diary->entries = realloc(diary->entries, diary->capacity * sizeof(entry_t));
    }

    // Add the new entry
    diary->entries[diary->num_entries].text = strdup(text);
    diary->entries[diary->num_entries].timestamp = time(NULL);
    diary->num_entries++;
}

// Print the diary
void diary_print(diary_t *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s", diary->entries[i].text);
    }
}

// Free the memory allocated for the diary
void diary_free(diary_t *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].text);
    }
    free(diary->entries);
    free(diary);
}

int main() {
    // Create a new diary
    diary_t *diary = diary_new();

    // Add some entries to the diary
    diary_add_entry(diary, "Dear diary,\n\nI am so grateful for everything in my life. I am grateful for my health, my family, my friends, and my home. I am grateful for the opportunity to learn and grow every day. I am grateful for the beauty of nature and the wonder of the universe.\n\nI am so lucky to be alive, and I am determined to make the most of every day. I want to live a life full of purpose and meaning. I want to make a difference in the world, and I want to leave the earth a better place than I found it.\n\nThank you for listening, diary. I am so grateful for your presence in my life.");
    diary_add_entry(diary, "\nDear diary,\n\nToday was a good day. I woke up feeling refreshed and full of energy. I went for a run and enjoyed the beautiful weather. I spent the afternoon reading and writing. I had a delicious dinner with my family. And I ended the day by watching a movie with my friends.\n\nI am so grateful for all of the good things in my life. I am grateful for my health, my family, my friends, and my home. I am grateful for the opportunity to pursue my passions and live a life that is full of meaning and purpose.\n\nThank you, diary, for being here for me. I am so grateful for your presence in my life.");
    diary_add_entry(diary, "\nDear diary,\n\nToday was a challenging day. I had a lot of work to do, and I felt overwhelmed at times. But I persevered, and I was able to accomplish everything that I needed to do.\n\nI am grateful for the challenges in my life. They help me to grow and become stronger. I am grateful for the opportunity to learn and improve. I am grateful for the people in my life who support me and help me to overcome my challenges.\n\nThank you, diary, for being here for me. I am so grateful for your presence in my life.");

    // Print the diary
    diary_print(diary);

    // Free the memory allocated for the diary
    diary_free(diary);

    return 0;
}