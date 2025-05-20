//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct diary_entry {
  time_t timestamp;
  char content[1024];
} diary_entry;

typedef struct digital_diary {
  char *filename;
  FILE *file;
  size_t size;
  diary_entry *entries;
} digital_diary;

// Creates a new digital diary
digital_diary *create_diary(const char *filename) {
  digital_diary *diary = malloc(sizeof(digital_diary));
  diary->filename = strdup(filename);
  diary->file = fopen(filename, "w+");
  diary->size = 0;
  diary->entries = NULL;
  return diary;
}

// Opens an existing digital diary
digital_diary *open_diary(const char *filename) {
  digital_diary *diary = malloc(sizeof(digital_diary));
  diary->filename = strdup(filename);
  diary->file = fopen(filename, "r+");
  if (diary->file == NULL) {
    return NULL;
  }
  fseek(diary->file, 0, SEEK_END);
  diary->size = ftell(diary->file) / sizeof(diary_entry);
  diary->entries = malloc(diary->size * sizeof(diary_entry));
  fseek(diary->file, 0, SEEK_SET);
  fread(diary->entries, sizeof(diary_entry), diary->size, diary->file);
  return diary;
}

// Closes a digital diary
void close_diary(digital_diary *diary) {
  if (diary->file != NULL) {
    fclose(diary->file);
  }
  free(diary->filename);
  free(diary->entries);
  free(diary);
}

// Adds a new entry to a digital diary
void add_entry(digital_diary *diary, const char *content) {
  diary_entry entry = {time(NULL), content};
  fseek(diary->file, 0, SEEK_END);
  fwrite(&entry, sizeof(diary_entry), 1, diary->file);
  diary->size++;
  diary->entries = realloc(diary->entries, diary->size * sizeof(diary_entry));
  memcpy(&diary->entries[diary->size - 1], &entry, sizeof(diary_entry));
}

// Gets an entry from a digital diary
diary_entry get_entry(digital_diary *diary, size_t index) {
  if (index >= diary->size) {
    return (diary_entry){0, ""};
  }
  return diary->entries[index];
}

// Prints a digital diary
void print_diary(digital_diary *diary) {
  for (size_t i = 0; i < diary->size; i++) {
    diary_entry entry = diary->entries[i];
    printf("[%s] %s\n", ctime(&entry.timestamp), entry.content);
  }
}

int main() {
  digital_diary *diary = create_diary("my_diary.txt");
  add_entry(diary, "Today was a good day.");
  add_entry(diary, "I went for a walk in the park.");
  add_entry(diary, "I saw a beautiful sunset.");
  print_diary(diary);
  close_diary(diary);
  return 0;
}