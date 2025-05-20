//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: funny
#define DIARY_PATH "./diary.txt"
#define NOT_IMPORTANT_THING "My life is a potato and I'm the queen of it"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables, because why not?
char *diary_contents;
int diary_length;

// Function to read the diary from file
char *read_diary() {
  FILE *diary_file = fopen(DIARY_PATH, "r");
  if (diary_file == NULL) {
    printf("Oops! Seems like you don't have a diary yet. Don't worry, I'll create one for you! Just don't tell anyone, okay?");
    diary_contents = malloc(strlen(NOT_IMPORTANT_THING) + 1);
    strcpy(diary_contents, NOT_IMPORTANT_THING);
    return diary_contents;
  }

  // Get the size of the file
  fseek(diary_file, 0, SEEK_END);
  diary_length = ftell(diary_file);
  rewind(diary_file);

  // Allocate memory for the diary contents
  diary_contents = malloc(diary_length + 1);

  // Read the diary contents into the allocated memory
  fread(diary_contents, diary_length, 1, diary_file);

  // Close the diary file
  fclose(diary_file);

  return diary_contents;
}

// Function to write the diary to file
void write_diary(char *contents) {
  FILE *diary_file = fopen(DIARY_PATH, "w");
  if (diary_file == NULL) {
    printf("Oops! Something went wrong while trying to write to your diary. Maybe you should check if you have the right permissions?");
    return;
  }

  // Write the diary contents to the file
  fwrite(contents, strlen(contents), 1, diary_file);

  // Close the diary file
  fclose(diary_file);
}

// Function to add a new entry to the diary
void add_entry(char *entry) {
  // Get the current diary contents
  char *current_contents = read_diary();

  // Allocate memory for the new diary contents
  char *new_contents = malloc(strlen(current_contents) + strlen(entry) + 2);

  // Concatenate the current contents and the new entry
  strcpy(new_contents, current_contents);
  strcat(new_contents, "\n");
  strcat(new_contents, entry);

  // Write the new diary contents to the file
  write_diary(new_contents);

  // Free the allocated memory
  free(current_contents);
  free(new_contents);
}

// Function to print the diary
void print_diary() {
  printf("\nHere's what's in your diary:\n");

  // Get the diary contents
  char *contents = read_diary();

  // Print the diary contents
  printf("%s\n", contents);

  // Free the allocated memory
  free(contents);
}

// Function to clear the diary
void clear_diary() {
  // Get the current diary contents
  char *current_contents = read_diary();

  // Check if the diary is empty
  if (strlen(current_contents) == 0) {
    printf("Your diary is already empty, silly! Try adding something to it instead.");
  } else {
    // Write an empty string to the file to clear it
    write_diary("");

    printf("Your diary is now empty. Don't worry, I won't tell anyone.");
  }

  // Free the allocated memory
  free(current_contents);
}

// Function to main menu
void main_menu() {
  int choice;

  do {
    printf("\n\n**Digital Diary**\n");
    printf("1. Read Diary\n");
    printf("2. Add Entry\n");
    printf("3. Clear Diary\n");
    printf("4. Quit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        print_diary();
        break;
      case 2:
        printf("Enter your entry: ");
        char entry[1024];
        scanf(" %[^\n]%*c", entry);
        add_entry(entry);
        break;
      case 3:
        clear_diary();
        break;
      case 4:
        printf("Goodbye! Remember, your secrets are safe with me. Unless someone finds this code, that is.");
        break;
      default:
        printf("Invalid choice. Try again.");
    }
  } while (choice != 4);
}

// Main function
int main() {
  // Read the diary from file
  // create_diary();
  read_diary();

  // Main menu
  main_menu();

  return 0;
}