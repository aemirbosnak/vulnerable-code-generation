//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>

int main() {
  // initialize variables
  int choice;
  char date[11], title[50], entry[1000];

  // welcome message
  printf("***Welcome to Your Digital Diary!***\n");

  // display menu
  do {
    printf("\nMenu:\n1. Create a new diary entry\n2. View a diary entry\n3. Exit program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Option 1: create new entry
    if (choice == 1) {
      printf("\n--- Create New Entry ---\n");
      printf("Enter the date in format (dd/mm/yyyy): ");
      scanf("%s", date);
      getchar(); // clear buffer
      printf("Enter the title of the entry: ");
      fgets(title, sizeof(title), stdin);
      printf("Enter your entry: ");
      fgets(entry, sizeof(entry), stdin);

      // write entry to file
      FILE *fp;
      fp = fopen("digital_diary.txt", "a");
      fprintf(fp, "%s %s\n%s\n", date, title, entry);
      fclose(fp);

      printf("\nEntry saved successfully!");
    }

    // Option 2: view previous entry
    else if (choice == 2) {
      printf("\n--- View Diary Entries ---\n");

      // read entries from file
      FILE *fp;
      fp = fopen("digital_diary.txt", "r");
      char line[1000];
      while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
      }
      fclose(fp);
    }

    // Option 3: exit program
    else if (choice == 3) {
      printf("\nGoodbye!");
      break;
    }

    // invalid input
    else {
      printf("\nInvalid input. Please try again.");
    }

  } while (choice != 3);

  return 0;
}