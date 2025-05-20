//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

struct diary_entry {
  char *title;
  char *content;
  time_t timestamp;
};

struct digital_diary {
  struct diary_entry *entries;
  int num_entries;
};

void print_diary_entry(struct diary_entry *entry) {
  printf("Title: %s\n", entry->title);
  printf("Content: %s\n", entry->content);
  printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

void add_diary_entry(struct digital_diary *diary, char *title, char *content) {
  struct diary_entry *entry = malloc(sizeof(struct diary_entry));
  entry->title = strdup(title);
  entry->content = strdup(content);
  entry->timestamp = time(NULL);

  diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(struct diary_entry));
  diary->entries[diary->num_entries++] = *entry;
}

void print_digital_diary(struct digital_diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    print_diary_entry(&diary->entries[i]);
    printf("\n");
  }
}

int main() {
  struct digital_diary diary;
  diary.entries = NULL;
  diary.num_entries = 0;

  add_diary_entry(&diary, "My First Entry", "This is my first entry in my digital diary.");
  add_diary_entry(&diary, "My Second Entry", "This is my second entry in my digital diary.");
  add_diary_entry(&diary, "My Third Entry", "This is my third entry in my digital diary.");

  print_digital_diary(&diary);

  return 0;
}