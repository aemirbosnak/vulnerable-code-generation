//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char title[100];
    char content[1000];
    time_t timestamp;
} DiaryEntry;

typedef struct {
    DiaryEntry *entries;
    int num_entries;
} Diary;

void add_entry(Diary *diary, const char *title, const char *content) {
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(DiaryEntry));
    strcpy(diary->entries[diary->num_entries].title, title);
    strcpy(diary->entries[diary->num_entries].content, content);
    diary->entries[diary->num_entries].timestamp = time(NULL);
    diary->num_entries++;
}

void print_entry(const DiaryEntry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

void print_diary(const Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        print_entry(&diary->entries[i]);
        printf("\n");
    }
}

int main() {
    Diary diary;
    diary.entries = NULL;
    diary.num_entries = 0;

    add_entry(&diary, "My first entry", "This is my first entry in my digital diary.");
    add_entry(&diary, "My second entry", "This is my second entry in my digital diary.");
    add_entry(&diary, "My third entry", "This is my third entry in my digital diary.");

    print_diary(&diary);

    return 0;
}