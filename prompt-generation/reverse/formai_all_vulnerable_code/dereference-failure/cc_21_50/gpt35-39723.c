//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Define a struct for a diary entry */
struct diary_entry {
  char date[11]; // Format: mm/dd/yyyy
  char time[6]; // Format: hh:mm
  char title[50];
  char entry[200];
};

int main() {
  int choice; // User choice variable
  struct diary_entry *entries = NULL; // Pointer to an array of diary entries
  int num_entries = 0; // Number of diary entries
  int i; // Loop counter

  printf("Welcome to your Digital Diary!\n");

  // Loop until user decides to exit
  while (1) {
    printf("Choose an option:\n");
    printf("1. Add new entry\n");
    printf("2. Display all entries\n");
    printf("3. Search entries by date\n");
    printf("4. Search entries by keyword\n");
    printf("5. Delete an entry\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: // Add new entry
        entries = (struct diary_entry *) realloc(entries, (num_entries+1) * sizeof(struct diary_entry)); // Allocate memory for new entry
        printf("Enter the date of your entry (mm/dd/yyyy): ");
        scanf("%s", entries[num_entries].date);
        printf("Enter the time of your entry (hh:mm): ");
        scanf("%s", entries[num_entries].time);
        printf("Enter the title of your entry: ");
        getchar(); // Clear input buffer
        fgets(entries[num_entries].title, 50, stdin);
        printf("Enter your entry: ");
        fgets(entries[num_entries].entry, 200, stdin);
        printf("Entry added successfully!\n");
        num_entries++; // Increment number of entries
        break;

      case 2: // Display all entries
        if (num_entries == 0) {
          printf("No entries yet!\n");
        }
        else {
          for (i = 0; i < num_entries; i++) {
            printf("Date: %s\n", entries[i].date);
            printf("Time: %s\n", entries[i].time);
            printf("Title: %s", entries[i].title);
            printf("Entry: %s", entries[i].entry);
            printf("--------------------\n");
          }
        }
        break;

      case 3: // Search entries by date
        if (num_entries == 0) {
          printf("No entries yet!\n");
        }
        else {
          char search_date[11]; // Date to search for
          int found = 0; // Flag to indicate if at least one entry is found

          printf("Enter the date to search for (mm/dd/yyyy): ");
          scanf("%s", search_date);

          for (i = 0; i < num_entries; i++) {
            if (strcmp(entries[i].date, search_date) == 0) { // If date matches
              printf("Date: %s\n", entries[i].date);
              printf("Time: %s\n", entries[i].time);
              printf("Title: %s", entries[i].title);
              printf("Entry: %s", entries[i].entry);
              printf("--------------------\n");
              found = 1;
            }
          }

          if (!found) {
            printf("No entries found for that date!\n");
          }
        }
        break;

      case 4: // Search entries by keyword
        if (num_entries == 0) {
          printf("No entries yet!\n");
        }
        else {
          char search_word[50]; // Keyword to search for
          int found = 0; // Flag to indicate if at least one entry is found

          printf("Enter the keyword to search for: ");
          getchar(); // Clear input buffer
          fgets(search_word, 50, stdin);
          search_word[strlen(search_word)-1] = '\0'; // Remove newline character

          for (i = 0; i < num_entries; i++) {
            if (strstr(entries[i].title, search_word) || strstr(entries[i].entry, search_word)) { // If keyword is found in title or entry
              printf("Date: %s\n", entries[i].date);
              printf("Time: %s\n", entries[i].time);
              printf("Title: %s", entries[i].title);
              printf("Entry: %s", entries[i].entry);
              printf("--------------------\n");
              found = 1;
            }
          }

          if (!found) {
            printf("No entries found for that keyword!\n");
          }
        }
        break;

      case 5: // Delete an entry
        if (num_entries == 0) {
          printf("No entries yet!\n");
        }
        else {
          int deletion_choice; // User choice for which entry to delete
          
          // Display all entries
          printf("Enter the number of the entry to delete:\n");
          for (i = 0; i < num_entries; i++) {
            printf("%d. %s, %s\n", i+1, entries[i].title, entries[i].date);
          }
          scanf("%d", &deletion_choice);

          if (deletion_choice > num_entries) {
            printf("Invalid choice!\n");
          }
          else {
            for (i = deletion_choice-1; i < num_entries-1; i++) { // Shift all entries after the deleted one by 1
              entries[i] = entries[i+1];
            }
            entries = (struct diary_entry *) realloc(entries, (num_entries-1) * sizeof(struct diary_entry)); // Free memory allocated for deleted entry
            num_entries--; // Decrement number of entries
            printf("Entry deleted successfully!\n");
          }
        }
        break;

      case 6: // Exit
        printf("Thanks for using Digital Diary!\n");
        free(entries); // Free memory allocated for diary entries
        exit(0);

      default:
        printf("Invalid choice!\n");
        break;
    }
  }

  return 0;
}