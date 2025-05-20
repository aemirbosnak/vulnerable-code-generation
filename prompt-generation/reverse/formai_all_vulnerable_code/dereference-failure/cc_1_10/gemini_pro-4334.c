//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char *date;
  char *entry;
} DiaryEntry;

DiaryEntry *create_entry(char *date, char *entry) {
  DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
  new_entry->date = strdup(date);
  new_entry->entry = strdup(entry);
  return new_entry;
}

void free_entry(DiaryEntry *entry) {
  free(entry->date);
  free(entry->entry);
  free(entry);
}

int main() {
  // Initialize the diary.
  DiaryEntry diary[10];
  int num_entries = 0;

  // Get the current date.
  time_t now = time(NULL);
  struct tm *tm_now = localtime(&now);
  char date[100];
  strftime(date, sizeof(date), "%Y-%m-%d", tm_now);

  // Create a new diary entry.
  DiaryEntry *new_entry = create_entry(date, "I survived another day in this hellhole.");
  diary[num_entries++] = *new_entry;
  free_entry(new_entry);

  // Get the user's input.
  char input[100];
  printf("Enter your diary entry for today: ");
  fgets(input, sizeof(input), stdin);

  // Add the user's input to the diary.
  new_entry = create_entry(date, input);
  diary[num_entries++] = *new_entry;
  free_entry(new_entry);

  // Print the diary.
  for (int i = 0; i < num_entries; i++) {
    printf("%s: %s\n", diary[i].date, diary[i].entry);
  }

  return 0;
}