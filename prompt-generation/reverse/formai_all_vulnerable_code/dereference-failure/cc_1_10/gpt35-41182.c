//FormAI DATASET v1.0 Category: Digital Diary ; Style: modular
// C Digital Diary Example Program
// Written in a modular style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants for file name and maximum size of entry
#define FILE_NAME "diary.txt"
#define MAX_ENTRY_SIZE 1000

// Function prototypes
void menu();
void add_entry();
void view_entry();
void search_entry();
char* sanitize_input(char*);

int main() {
  menu();
  return 0;
}

// Display the menu options and get user input
void menu() {
  char choice;
  
  do {
    printf("\nC DIGITAL DIARY\n");
    printf("1. Add entry\n");
    printf("2. View entry\n");
    printf("3. Search entry\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch(choice) {
      case '1':
        add_entry();
        break;
      case '2':
        view_entry();
        break;
      case '3':
        search_entry();
        break;
      case '4':
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice, please try again.\n");
    }
  } while(choice != '4');
}

// Add a new entry to the diary file
void add_entry() {
  char entry[MAX_ENTRY_SIZE];
  FILE* file = fopen(FILE_NAME, "a");

  if(file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  printf("Enter your entry (maximum %d characters):\n", MAX_ENTRY_SIZE);
  fgets(entry, MAX_ENTRY_SIZE, stdin);

  // remove new line character
  entry[strcspn(entry, "\n")] = 0;

  // sanitize input
  char* sanitized_entry = sanitize_input(entry);

  fprintf(file, "%s\n", sanitized_entry);
  fclose(file);
  printf("Entry added successfully!\n");
}

// View all entries in the diary file
void view_entry() {
  char c;
  FILE* file = fopen(FILE_NAME, "r");

  if(file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  printf("DIARY ENTRIES\n");
  printf("-----------------------------------\n");

  while((c = fgetc(file)) != EOF) {
    printf("%c", c);
  }

  fclose(file);
}

// Search for entries containing a specific keyword
void search_entry() {
  char keyword[MAX_ENTRY_SIZE];
  char entry[MAX_ENTRY_SIZE];
  FILE* file = fopen(FILE_NAME, "r");

  if(file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  printf("Enter a keyword to search for (maximum %d characters):\n", MAX_ENTRY_SIZE);
  fgets(keyword, MAX_ENTRY_SIZE, stdin);

  // remove new line character
  keyword[strcspn(keyword, "\n")] = 0;

  // sanitize input
  char* sanitized_keyword = sanitize_input(keyword);

  printf("Matching entries:\n");
  printf("-----------------------------------\n");

  // Search for matching entries
  while(fgets(entry, MAX_ENTRY_SIZE, file)) {
    char* sanitized_entry = sanitize_input(entry);

    if(strstr(sanitized_entry, sanitized_keyword)) {
      printf("%s\n", entry);
    }
  }

  fclose(file);
}

// Sanitize user input to remove unwanted characters
char* sanitize_input(char* text) {
  int i, j;
  char* sanitized_text = (char*) malloc(strlen(text) + 1);

  for(i = 0, j = 0; i < strlen(text); i++) {
    if(isalpha(text[i]) || isspace(text[i])) {
      sanitized_text[j] = text[i];
      j++;
    }
  }

  sanitized_text[j] = '\0';
  return sanitized_text;
}