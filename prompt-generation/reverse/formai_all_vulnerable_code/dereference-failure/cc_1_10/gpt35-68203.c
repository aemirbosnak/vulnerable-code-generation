//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Diary {
  int day;
  int month;
  int year;
  char *title;
  char *content;
};

struct Diary create_entry(int day, int month, int year, char *title, char *content) {
  struct Diary entry;
  entry.day = day;
  entry.month = month;
  entry.year = year;

  entry.title = (char *) malloc(strlen(title) + 1);
  strcpy(entry.title, title);

  entry.content = (char *) malloc(strlen(content) + 1);
  strcpy(entry.content, content);

  return entry;
}

void print_entry(struct Diary entry) {
  printf("\n\nDate: %d/%d/%d\n", entry.day, entry.month, entry.year);
  printf("Title: %s\n", entry.title);
  printf("Content: %s\n\n", entry.content);
}

int main() {
  struct Diary diary[365];
  printf("\n\nWelcome to your digital diary!\n\n");

  while(1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Create new diary entry\n");
    printf("2. View previous entries\n");
    printf("3. Exit the program\n");
    printf("Enter your choice (1-3): ");

    int choice;
    scanf("%d", &choice);

    if(choice == 1) {
      printf("\nEnter the date (DD MM YYYY): ");
      int day, month, year;
      scanf("%d %d %d", &day, &month, &year);

      printf("Enter a title for your entry: ");
      char title[50];
      getchar();
      fgets(title, sizeof(title), stdin);
      title[strcspn(title, "\n")] = 0;

      printf("Enter your entry: ");
      char content[1000];
      fgets(content, sizeof(content), stdin);
      content[strcspn(content, "\n")] = 0;

      struct Diary entry = create_entry(day, month, year, title, content);
      int index = day + (month * 30) + (year * 365) - 1;
      diary[index] = entry;

      printf("\n\nEntry created successfully!\n\n");
    }
    else if(choice == 2) {
      printf("\n\nPrevious entries:\n\n");

      for(int i = 0; i < 365; i++) {
        if(diary[i].title != NULL) {
          print_entry(diary[i]);
        }
      }
    }
    else if(choice == 3) {
      printf("\n\nGoodbye!\n\n");
      exit(0);
    }
    else {
      printf("\nInvalid choice! Please choose between 1-3.\n");
    }
  }

  return 0;
}