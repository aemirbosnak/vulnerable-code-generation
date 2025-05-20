//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char entry[1024];
    struct diary *next;
} diary_entry;

typedef struct {
    diary_entry *entries;
    struct diary *next;
} diary;

diary *create_diary() {
    diary *diary = malloc(sizeof(diary));
    diary->entries = NULL;
    diary->next = NULL;
    return diary;
}

diary_entry *add_entry(diary *diary, const char *entry) {
    diary_entry *new_entry = malloc(sizeof(diary_entry));
    strcpy(new_entry->entry, entry);
    new_entry->next = NULL;
    if (diary->entries == NULL) {
        diary->entries = new_entry;
        diary->next = new_entry;
    } else {
        diary_entry *last_entry = diary->entries;
        while (last_entry->next!= NULL) {
            last_entry = last_entry->next;
        }
        last_entry->next = new_entry;
    }
    return new_entry;
}

void display_diary(diary *diary) {
    diary_entry *entry = diary->entries;
    while (entry!= NULL) {
        printf("%s\n", entry->entry);
        entry = entry->next;
    }
}

int main() {
    diary *diary = create_diary();
    diary_entry *entry = add_entry(diary, "Today I woke up feeling happy.");
    diary_entry *entry2 = add_entry(diary, "I had a great day at work.");
    diary_entry *entry3 = add_entry(diary, "I went to the gym and lifted some weights.");
    diary_entry *entry4 = add_entry(diary, "I had a delicious dinner and watched a movie.");
    diary_entry *entry5 = add_entry(diary, "I went to bed feeling content.");
    display_diary(diary);
    return 0;
}