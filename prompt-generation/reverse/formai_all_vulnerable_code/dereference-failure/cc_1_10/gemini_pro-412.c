//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diary_entry {
    char *title;
    char *date;
    char *content;
} diary_entry;

typedef struct digital_diary {
    int num_entries;
    diary_entry **entries;
} digital_diary;

digital_diary *create_diary() {
    digital_diary *diary = malloc(sizeof(digital_diary));
    diary->num_entries = 0;
    diary->entries = NULL;
    return diary;
}

void add_entry(digital_diary *diary, char *title, char *date, char *content) {
    diary->num_entries++;
    diary->entries = realloc(diary->entries, diary->num_entries * sizeof(diary_entry *));
    diary_entry *entry = malloc(sizeof(diary_entry));
    entry->title = malloc(strlen(title) + 1);
    strcpy(entry->title, title);
    entry->date = malloc(strlen(date) + 1);
    strcpy(entry->date, date);
    entry->content = malloc(strlen(content) + 1);
    strcpy(entry->content, content);
    diary->entries[diary->num_entries - 1] = entry;
}

void print_entry(diary_entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Date: %s\n", entry->date);
    printf("Content: %s\n", entry->content);
}

void print_diary(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        print_entry(diary->entries[i]);
        printf("\n");
    }
}

void free_entry(diary_entry *entry) {
    free(entry->title);
    free(entry->date);
    free(entry->content);
    free(entry);
}

void free_diary(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free_entry(diary->entries[i]);
    }
    free(diary->entries);
    free(diary);
}

int main() {
    digital_diary *diary = create_diary();
    add_entry(diary, "My First Entry", "2023-01-01", "This is my first entry in my digital diary. I'm so excited to start keeping track of my thoughts and experiences this way.");
    add_entry(diary, "My Second Entry", "2023-01-02", "I went for a walk in the park today. It was a beautiful day, and I enjoyed seeing all the people and animals enjoying the weather.");
    add_entry(diary, "My Third Entry", "2023-01-03", "I had a great time at my friend's birthday party last night. We ate cake, danced, and played games. I'm so glad I have such wonderful friends.");
    print_diary(diary);
    free_diary(diary);
    return 0;
}