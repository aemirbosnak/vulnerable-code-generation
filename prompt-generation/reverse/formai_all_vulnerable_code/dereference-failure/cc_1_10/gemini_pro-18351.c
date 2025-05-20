//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char *entry;
  time_t timestamp;
} DiaryEntry;

typedef struct {
  DiaryEntry *entries;
  int num_entries;
  int capacity;
} DigitalDiary;

DigitalDiary *create_digital_diary() {
  DigitalDiary *diary = malloc(sizeof(DigitalDiary));
  diary->entries = NULL;
  diary->num_entries = 0;
  diary->capacity = 0;
  return diary;
}

void destroy_digital_diary(DigitalDiary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    free(diary->entries[i].entry);
  }
  free(diary->entries);
  free(diary);
}

void add_entry_to_diary(DigitalDiary *diary, char *entry) {
  if (diary->num_entries == diary->capacity) {
    diary->capacity *= 2;
    diary->entries = realloc(diary->entries, diary->capacity * sizeof(DiaryEntry));
  }

  DiaryEntry new_entry;
  new_entry.entry = strdup(entry);
  new_entry.timestamp = time(NULL);
  diary->entries[diary->num_entries++] = new_entry;
}

void print_diary(DigitalDiary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    printf("%s\n", diary->entries[i].entry);
  }
}

int main() {
  DigitalDiary *diary = create_digital_diary();

  add_entry_to_diary(diary, "Today I went to the park.");
  add_entry_to_diary(diary, "I saw a lot of beautiful flowers.");
  add_entry_to_diary(diary, "I also met a new friend.");

  print_diary(diary);

  destroy_digital_diary(diary);

  return 0;
}