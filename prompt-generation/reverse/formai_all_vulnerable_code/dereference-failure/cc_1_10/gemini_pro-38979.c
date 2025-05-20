//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a diary entry
typedef struct {
  char date[11];  // Date in the format "YYYY-MM-DD"
  char time[6];   // Time in the format "HH:MM"
  char title[51]; // Title of the entry (max 50 characters)
  char body[1001]; // Body of the entry (max 1000 characters)
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry* createEntry(char* date, char* time, char* title, char* body) {
  DiaryEntry* entry = (DiaryEntry*)malloc(sizeof(DiaryEntry));
  strcpy(entry->date, date);
  strcpy(entry->time, time);
  strcpy(entry->title, title);
  strcpy(entry->body, body);
  return entry;
}

// Function to print a diary entry
void printEntry(DiaryEntry* entry) {
  printf("Date: %s\n", entry->date);
  printf("Time: %s\n", entry->time);
  printf("Title: %s\n", entry->title);
  printf("Body: %s\n\n", entry->body);
}

// Function to add a new entry to the diary
void addEntry(DiaryEntry** diary, int* diarySize, DiaryEntry* newEntry) {
  *diary = (DiaryEntry*)realloc(*diary, (*diarySize + 1) * sizeof(DiaryEntry));
  (*diary)[*diarySize] = *newEntry;
  (*diarySize)++;
}

// Function to search for an entry by title
int searchEntry(DiaryEntry* diary, int diarySize, char* title) {
  for (int i = 0; i < diarySize; i++) {
    if (strcmp(diary[i].title, title) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to delete an entry by index
void deleteEntry(DiaryEntry** diary, int* diarySize, int index) {
  for (int i = index; i < *diarySize - 1; i++) {
    (*diary)[i] = (*diary)[i + 1];
  }
  *diary = (DiaryEntry*)realloc(*diary, (*diarySize - 1) * sizeof(DiaryEntry));
  (*diarySize)--;
}

// Function to load the diary from a file
int loadDiary(DiaryEntry** diary, int* diarySize, char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return -1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    if (line[0] == '\n') {
      continue;
    }

    char date[11], time[6], title[51], body[1001];
    sscanf(line, "%s %s %s %[^\n]", date, time, title, body);

    DiaryEntry* entry = createEntry(date, time, title, body);
    addEntry(diary, diarySize, entry);
  }

  fclose(file);

  return 0;
}

// Function to save the diary to a file
int saveDiary(DiaryEntry* diary, int diarySize, char* filename) {
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    return -1;
  }

  for (int i = 0; i < diarySize; i++) {
    fprintf(file, "%s %s %s %s\n", diary[i].date, diary[i].time, diary[i].title, diary[i].body);
  }

  fclose(file);

  return 0;
}

// Main function
int main() {
  // Initialize the diary
  DiaryEntry* diary = NULL;
  int diarySize = 0;

  // Load the diary from a file
  if (loadDiary(&diary, &diarySize, "diary.txt") == -1) {
    printf("Error loading diary from file.\n");
    return 1;
  }

  // Add a new entry to the diary
  DiaryEntry* newEntry = createEntry("2023-03-08", "14:30", "My awesome day", "Today was a great day! I went to the park and played with my friends. I also got a new bike, which is really cool.");
  addEntry(&diary, &diarySize, newEntry);

  // Print the diary
  printf("**Diary**\n\n");
  for (int i = 0; i < diarySize; i++) {
    printEntry(&diary[i]);
  }

  // Search for an entry by title
  char* searchTitle = "My awesome day";
  int index = searchEntry(diary, diarySize, searchTitle);
  if (index == -1) {
    printf("Entry with title '%s' not found.\n", searchTitle);
  } else {
    printf("Entry found:\n");
    printEntry(&diary[index]);
  }

  // Delete an entry by index
  int deleteIndex = 0;
  deleteEntry(&diary, &diarySize, deleteIndex);

  // Save the diary to a file
  if (saveDiary(diary, diarySize, "diary.txt") == -1) {
    printf("Error saving diary to file.\n");
    return 1;
  }

  // Free the memory allocated for the diary
  for (int i = 0; i < diarySize; i++) {
    free(&diary[i]);
  }
  free(diary);

  return 0;
}