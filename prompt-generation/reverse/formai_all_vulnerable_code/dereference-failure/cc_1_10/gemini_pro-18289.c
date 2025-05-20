//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1000

struct DiaryEntry {
    time_t timestamp;
    char *text;
};

struct DigitalDiary {
    struct DiaryEntry *entries[MAX_ENTRIES];
    int num_entries;
};

struct DigitalDiary *create_diary() {
    struct DigitalDiary *diary = malloc(sizeof(struct DigitalDiary));
    diary->num_entries = 0;
    return diary;
}

void add_entry(struct DigitalDiary *diary, char *text) {
    if (diary->num_entries == MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    struct DiaryEntry *entry = malloc(sizeof(struct DiaryEntry));
    entry->timestamp = time(NULL);
    entry->text = strdup(text);

    diary->entries[diary->num_entries++] = entry;
}

void print_diary(struct DigitalDiary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        struct DiaryEntry *entry = diary->entries[i];
        printf("%s\n", ctime(&entry->timestamp));
        printf("%s\n\n", entry->text);
    }
}

void free_diary(struct DigitalDiary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i]->text);
        free(diary->entries[i]);
    }

    free(diary);
}

int main() {
  struct DigitalDiary *my_diary = create_diary();

  // Add some entries to the diary
  add_entry(my_diary, "Dear diary, today was a great day!");
  add_entry(my_diary, "I went for a walk in the park and saw a beautiful sunset.");
  add_entry(my_diary, "I also met a new friend and we had a really great time.");

  // Print the diary
  print_diary(my_diary);

  // Free the diary
  free_diary(my_diary);

  return 0;
}