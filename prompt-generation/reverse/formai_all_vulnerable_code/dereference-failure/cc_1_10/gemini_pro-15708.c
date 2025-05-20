//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
  time_t timestamp;
  char *text;
};

struct diary {
  int num_entries;
  struct entry *entries;
};

struct diary *create_diary() {
  struct diary *diary = malloc(sizeof(struct diary));
  diary->num_entries = 0;
  diary->entries = NULL;
  return diary;
}

void free_diary(struct diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    free(diary->entries[i].text);
  }
  free(diary->entries);
  free(diary);
}

void add_entry(struct diary *diary, char *text) {
  diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(struct entry));
  diary->entries[diary->num_entries].timestamp = time(NULL);
  diary->entries[diary->num_entries].text = strdup(text);
  diary->num_entries++;
}

void print_diary(struct diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    printf("%s", ctime(&diary->entries[i].timestamp));
    printf("%s\n", diary->entries[i].text);
  }
}

int main() {
  struct diary *diary = create_diary();

  add_entry(diary, "Dear Diary,\n\nIt's been a great day! I went to the park with my friends and we had a lot of fun playing soccer and frisbee. The weather was perfect and the company was even better.\n\nI'm so grateful for these moments and I'm so happy to have friends like them.\n\nLove,\n\nMe");

  add_entry(diary, "Dear Diary,\n\nI had a tough day at work today. I made a mistake on a project and my boss was really mad at me. I felt really bad and I didn't know what to do.\n\nI went for a walk to clear my head and I started to feel a little better. I realized that everyone makes mistakes and that I should just learn from this and move on.\n\nI'm feeling a lot better now and I'm ready to face tomorrow.\n\nLove,\n\nMe");

  print_diary(diary);

  free_diary(diary);

  return 0;
}