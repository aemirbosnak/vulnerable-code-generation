//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1024

typedef struct {
    char* title;
    char* content;
    time_t timestamp;
} DiaryEntry;

typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
} Diary;

Diary* create_diary() {
    Diary* diary = malloc(sizeof(Diary));
    diary->num_entries = 0;
    return diary;
}

void add_entry(Diary* diary, char* title, char* content) {
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Error: Diary is full\n");
        return;
    }

    DiaryEntry* entry = &diary->entries[diary->num_entries++];
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->timestamp = time(NULL);
}

void print_entry(DiaryEntry* entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s\n\n", ctime(&entry->timestamp));
}

void print_diary(Diary* diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        print_entry(&diary->entries[i]);
    }
}

int main() {
    Diary* diary = create_diary();

    add_entry(diary, "My First Entry", "This is my first entry in my digital diary.");
    add_entry(diary, "Second Entry", "I'm really enjoying using this diary.");
    add_entry(diary, "Third Entry", "I'm starting to get the hang of this.");

    print_diary(diary);

    return 0;
}