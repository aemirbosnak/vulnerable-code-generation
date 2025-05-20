//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Ephemeral diary structure
struct Diary {
  char *entry;
  time_t timestamp;
};

// Ephemeral diary functions
void write_entry(struct Diary *diary, const char *entry) {
  diary->entry = malloc(strlen(entry) + 1);
  strcpy(diary->entry, entry);
  diary->timestamp = time(NULL);
}

void read_entry(const struct Diary *diary) {
  printf("%s\n", diary->entry);
}

void destroy_entry(struct Diary *diary) {
  free(diary->entry);
  diary->entry = NULL;
  diary->timestamp = 0;
}

int main() {
  // Create a new diary
  struct Diary diary;
  diary.entry = NULL;
  diary.timestamp = 0;

  // Write an entry to the diary
  write_entry(&diary, "This is my first diary entry!");

  // Read the entry from the diary
  read_entry(&diary);

  // Pause for a moment
  printf("Pausing for a moment... Press any key to continue.\n");
  getchar();

  // Destroy the diary entry
  destroy_entry(&diary);

  // Destroy the diary
  free(diary.entry);
  diary.entry = NULL;
  diary.timestamp = 0;

  return 0;
}