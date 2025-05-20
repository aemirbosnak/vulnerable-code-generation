//FormAI DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    time_t timestamp;
    char* title;
    char* content;
};

struct Diary {
    int num_entries;
    struct DiaryEntry** entries;
};

struct Diary* diary_create() {
    struct Diary* diary = malloc(sizeof(struct Diary));
    diary->num_entries = 0;
    diary->entries = malloc(MAX_ENTRIES * sizeof(struct DiaryEntry*));
    return diary;
}

void diary_add_entry(struct Diary* diary, char* title, char* content) {
    if(diary->num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }
    struct DiaryEntry* entry = malloc(sizeof(struct DiaryEntry));
    entry->timestamp = time(NULL);
    entry->title = malloc(strlen(title) + 1);
    strcpy(entry->title, title);
    entry->content = malloc(strlen(content) + 1);
    strcpy(entry->content, content);
    diary->entries[diary->num_entries] = entry;
    diary->num_entries++;
}

void diary_print(struct Diary* diary) {
    printf("----- DIARY ENTRIES -----\n");
    for(int i = 0; i < diary->num_entries; i++) {
        struct DiaryEntry* entry = diary->entries[i];
        printf("Entry %d:\n", i+1);
        printf("Title: %s\n", entry->title);
        printf("Content: %s\n", entry->content);
        printf("Timestamp: %s", ctime(&entry->timestamp));
        printf("-------\n");
    }
}

void diary_destroy(struct Diary* diary) {
    for(int i = 0; i < diary->num_entries; i++) {
        struct DiaryEntry* entry = diary->entries[i];
        free(entry->title);
        free(entry->content);
        free(entry);
    }
    free(diary->entries);
    free(diary);
}

int main() {
    struct Diary* my_diary = diary_create();
    diary_add_entry(my_diary, "First Entry", "This is my first diary entry!");
    diary_add_entry(my_diary, "Second Entry", "Today was a good day.");
    diary_add_entry(my_diary, "Third Entry", "I need to remember to buy groceries tomorrow.");
    diary_print(my_diary);
    diary_destroy(my_diary);
    return 0;
}