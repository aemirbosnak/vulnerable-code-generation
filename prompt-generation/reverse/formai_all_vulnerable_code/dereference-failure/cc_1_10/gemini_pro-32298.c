//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structures
typedef struct Entry {
  char *text;
  time_t timestamp;
} Entry;

typedef struct Diary {
  Entry *entries;
  int num_entries;
} Diary;

// Function declarations
Diary *create_diary();
void add_entry(Diary *diary, char *text);
void print_diary(Diary *diary);
void save_diary(Diary *diary, char *filename);
void load_diary(Diary *diary, char *filename);
void free_diary(Diary *diary);

// Main function
int main() {
  // Create a new diary
  Diary *diary = create_diary();

  // Add some entries to the diary
  add_entry(diary, "Today I went for a walk in the park.");
  add_entry(diary, "I saw a lot of beautiful flowers and birds.");
  add_entry(diary, "I also met a new friend.");

  // Print the diary
  print_diary(diary);

  // Save the diary to a file
  save_diary(diary, "my_diary.txt");

  // Load the diary from a file
  load_diary(diary, "my_diary.txt");

  // Print the diary again
  print_diary(diary);

  // Free the diary
  free_diary(diary);

  return 0;
}

// Function definitions
Diary *create_diary() {
  Diary *diary = malloc(sizeof(Diary));
  diary->entries = NULL;
  diary->num_entries = 0;
  return diary;
}

void add_entry(Diary *diary, char *text) {
  diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(Entry));
  diary->entries[diary->num_entries].text = strdup(text);
  diary->entries[diary->num_entries].timestamp = time(NULL);
  diary->num_entries++;
}

void print_diary(Diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    printf("%s\n", diary->entries[i].text);
  }
}

void save_diary(Diary *diary, char *filename) {
  FILE *f = fopen(filename, "w");
  if (f == NULL) {
    perror("Error opening file");
    return;
  }

  for (int i = 0; i < diary->num_entries; i++) {
    fprintf(f, "%s\n", diary->entries[i].text);
  }

  fclose(f);
}

void load_diary(Diary *diary, char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    perror("Error opening file");
    return;
  }

  char line[1024];
  while (fgets(line, sizeof(line), f)) {
    add_entry(diary, line);
  }

  fclose(f);
}

void free_diary(Diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    free(diary->entries[i].text);
  }
  free(diary->entries);
  free(diary);
}