//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct Entry {
  char *title;
  char *content;
  int date;
};

struct Diary {
  struct Entry entries[MAX_ENTRIES];
  int num_entries;
};

struct Diary *create_diary() {
  struct Diary *diary = malloc(sizeof(struct Diary));
  diary->num_entries = 0;
  return diary;
}

void add_entry(struct Diary *diary, char *title, char *content, int date) {
  if (diary->num_entries >= MAX_ENTRIES) {
    printf("Error: Diary is full!\n");
    return;
  }

  struct Entry *entry = &diary->entries[diary->num_entries++];
  entry->title = strdup(title);
  entry->content = strdup(content);
  entry->date = date;
}

void print_entry(struct Entry *entry) {
  printf("Title: %s\n", entry->title);
  printf("Content: %s\n", entry->content);
  printf("Date: %d\n", entry->date);
  printf("\n");
}

void print_diary(struct Diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    print_entry(&diary->entries[i]);
  }
}

int main() {
  struct Diary *diary = create_diary();

  add_entry(diary, "My First Entry",
                 "This is my first entry in my digital diary. I'm so excited to start writing about my life!", 20230308);
  add_entry(diary, "A Day in the Life",
                 "Today I woke up early and went for a run. It was a beautiful day, and I felt great. After my run, I had breakfast and then went to work. I had a lot of meetings today, but they were all productive. After work, I went to the gym and then had dinner with friends. It was a great day!", 20230309);
  add_entry(diary, "A Difficult Day",
                 "Today was a difficult day. I had a fight with my best friend, and I'm not sure how to fix it. I also had a lot of stress at work, and I'm feeling overwhelmed. I just need to take some time to relax and clear my head.", 20230310);

  print_diary(diary);

  return 0;
}