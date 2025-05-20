//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Entry structure
typedef struct Entry {
    time_t timestamp;
    char *content;
} Entry;

// Diary structure
typedef struct Diary {
    Entry *entries;
    int num_entries;
} Diary;

// Create a new diary
Diary *new_diary() {
    Diary *diary = malloc(sizeof(Diary));
    diary->entries = NULL;
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to the diary
void add_entry(Diary *diary, char *content) {
    Entry *entry = malloc(sizeof(Entry));
    entry->timestamp = time(NULL);
    entry->content = strdup(content);
    diary->entries = realloc(diary->entries, sizeof(Entry) * (diary->num_entries + 1));
    diary->entries[diary->num_entries++] = *entry;
}

// Print the diary
void print_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n", ctime(&diary->entries[i].timestamp));
        printf("%s\n\n", diary->entries[i].content);
    }
}

// Free the diary
void free_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].content);
    }
    free(diary->entries);
    free(diary);
}

// Main function
int main() {
    Diary *diary = new_diary();

    add_entry(diary, "Dear diary,\n\nToday was a great day! I went for a walk in the park and saw some beautiful flowers. I also met a new friend named Sarah. She's really nice and we had a lot to talk about.");
    add_entry(diary, "Dear diary,\n\nToday was a tough day. I had a fight with my best friend and I'm not sure what to do. I feel really sad and alone.");
    add_entry(diary, "Dear diary,\n\nToday was a good day. I got a promotion at work and I'm really excited about it. I also went out to dinner with my family and had a great time.");

    print_diary(diary);

    free_diary(diary);

    return 0;
}