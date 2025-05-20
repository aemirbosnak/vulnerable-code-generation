//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Diary entry structure
struct entry {
    char *date;
    char *title;
    char *content;
};

// Diary structure
struct diary {
    struct entry *entries;
    int num_entries;
};

// Create a new diary
struct diary *create_diary() {
    struct diary *diary = malloc(sizeof(struct diary));
    diary->entries = NULL;
    diary->num_entries = 0;
    return diary;
}

// Add an entry to the diary
void add_entry(struct diary *diary, char *date, char *title, char *content) {
    // Create a new entry
    struct entry *entry = malloc(sizeof(struct entry));
    entry->date = malloc(strlen(date) + 1);
    entry->title = malloc(strlen(title) + 1);
    entry->content = malloc(strlen(content) + 1);
    strcpy(entry->date, date);
    strcpy(entry->title, title);
    strcpy(entry->content, content);

    // Add the entry to the diary
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(struct entry));
    diary->entries[diary->num_entries] = *entry;
    diary->num_entries++;
}

// Print the diary
void print_diary(struct diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n", diary->entries[i].date);
        printf("%s\n", diary->entries[i].title);
        printf("%s\n\n", diary->entries[i].content);
    }
}

// Free the diary
void free_diary(struct diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].date);
        free(diary->entries[i].title);
        free(diary->entries[i].content);
    }
    free(diary->entries);
    free(diary);
}

int main() {
    // Create a new diary
    struct diary *diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "2023-03-08", "My first entry", "This is my first entry in my digital diary. I'm excited to start using it to track my thoughts and experiences.");
    add_entry(diary, "2023-03-09", "A day in the life", "Today I woke up early and went for a run. Then I had breakfast and worked on my new project. In the afternoon I went to the gym and had dinner with friends.");
    add_entry(diary, "2023-03-10", "A lesson learned", "Today I learned that it's important to be patient and persistent. I was working on a difficult problem, and I almost gave up. But I kept at it, and eventually I found the solution.");

    // Print the diary
    print_diary(diary);

    // Free the diary
    free_diary(diary);

    return 0;
}