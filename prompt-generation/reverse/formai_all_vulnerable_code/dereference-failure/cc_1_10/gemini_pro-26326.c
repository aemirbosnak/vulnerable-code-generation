//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a diary entry
typedef struct {
  char date[11];
  char time[9];
  char entry[1024];
} diary_entry;

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the file name of the diary
#define DIARY_FILE "diary.txt"

// Function to create a new diary entry
diary_entry* create_entry(char* date, char* time, char* entry) {
  diary_entry* new_entry = malloc(sizeof(diary_entry));
  strcpy(new_entry->date, date);
  strcpy(new_entry->time, time);
  strcpy(new_entry->entry, entry);
  return new_entry;
}

// Function to add a new diary entry to the diary file
void add_entry(diary_entry* entry) {
  FILE* diary = fopen(DIARY_FILE, "a");
  fprintf(diary, "%s %s\n%s\n", entry->date, entry->time, entry->entry);
  fclose(diary);
}

// Function to print a diary entry
void print_entry(diary_entry* entry) {
  printf("%s %s\n%s\n", entry->date, entry->time, entry->entry);
}

// Function to print all diary entries
void print_all_entries() {
  FILE* diary = fopen(DIARY_FILE, "r");
  char line[1024];
  while (fgets(line, sizeof(line), diary)) {
    char* date = strtok(line, " ");
    char* time = strtok(NULL, "\n");
    char* entry = strtok(NULL, "\n");
    diary_entry* new_entry = create_entry(date, time, entry);
    print_entry(new_entry);
    free(new_entry);
  }
  fclose(diary);
}

// Function to delete a diary entry
void delete_entry(char* date, char* time) {
  FILE* diary = fopen(DIARY_FILE, "r");
  FILE* temp = fopen("temp.txt", "w");
  char line[1024];
  while (fgets(line, sizeof(line), diary)) {
    char* date = strtok(line, " ");
    char* time = strtok(NULL, "\n");
    char* entry = strtok(NULL, "\n");
    if (strcmp(date, date) != 0 || strcmp(time, time) != 0) {
      fprintf(temp, "%s %s\n%s\n", date, time, entry);
    }
  }
  fclose(diary);
  fclose(temp);
  remove(DIARY_FILE);
  rename("temp.txt", DIARY_FILE);
}

// Function to search for a diary entry
void search_entry(char* keyword) {
  FILE* diary = fopen(DIARY_FILE, "r");
  char line[1024];
  while (fgets(line, sizeof(line), diary)) {
    char* date = strtok(line, " ");
    char* time = strtok(NULL, "\n");
    char* entry = strtok(NULL, "\n");
    if (strstr(entry, keyword) != NULL) {
      diary_entry* new_entry = create_entry(date, time, entry);
      print_entry(new_entry);
      free(new_entry);
    }
  }
  fclose(diary);
}

// Main function
int main() {
  // Create a new diary entry
  diary_entry* entry1 = create_entry("2023-03-08", "10:00", "Today was a great day!");

  // Add the new diary entry to the diary file
  add_entry(entry1);

  // Print all diary entries
  print_all_entries();

  // Delete a diary entry
  delete_entry("2023-03-08", "10:00");

  // Search for a diary entry
  search_entry("great");

  return 0;
}