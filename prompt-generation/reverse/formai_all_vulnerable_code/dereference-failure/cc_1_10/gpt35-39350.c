//FormAI DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printMenu() {
  printf("\n\nC Digital Diary\n\n");
  printf("1. Add Entry\n");
  printf("2. View Entries\n");
  printf("3. Search Entry\n");
  printf("4. Delete Entry\n");
  printf("5. Exit\n");
}

void addEntry(FILE *file) {
  fflush(stdin);
  printf("\nEnter date in format dd/mm/yyyy: ");
  char date[11];
  fgets(date, 11, stdin);

  printf("Enter title: ");
  char title[100];
  fgets(title, 100, stdin);

  printf("Enter content: ");
  char content[5000];
  fgets(content, 5000, stdin);

  fprintf(file, "%s|%s|%s", date, title, content);
  printf("\nEntry added successfully.");
}

void viewEntries(FILE *file) {
  printf("\nAll Entries\n\n");
  char line[5111];
  while(fgets(line, sizeof(line), file)) {
    printf("%s", line);
  }
}

void searchEntry(FILE *file) {
  printf("\nEnter date in format dd/mm/yyyy: ");
  char searchDate[11];
  fgets(searchDate, 11, stdin);

  printf("\nSearch Results\n\n");
  int count = 0;
  char line[5111];
  while(fgets(line, sizeof(line), file)) {
    char *date = strtok(line, "|");
    if(strcmp(date, searchDate) == 0) {
      printf("%s", line);
      count++;
    }
  }
  if(count == 0) {
    printf("\nNo entries found for date: %s", searchDate);
  }
}

void deleteEntry(FILE *file) {
  fflush(stdin);
  printf("\nEnter date in format dd/mm/yyyy: ");
  char searchDate[11];
  fgets(searchDate, 11, stdin);

  FILE *temp;
  temp = fopen("temp.txt", "w");

  int count = 0;
  char line[5111];
  while(fgets(line, sizeof(line), file)) {
    char *date = strtok(line, "|");
    if(strcmp(date, searchDate) == 0) {
      count++;
      printf("\nEntry deleted\n\n");
    } else {
      fprintf(temp, "%s", line);
    }
  }
  if(count == 0) {
    printf("\nNo entries found for date: %s", searchDate);
  }
  fclose(file);
  fclose(temp);
  remove("diary.txt");
  rename("temp.txt", "diary.txt");
  file = fopen("diary.txt", "a+");
}

int main() {
  FILE *file;
  file = fopen("diary.txt", "a+");
  if(file == NULL) {
    printf("Error opening file!");
    exit(1);
  }

  int choice;
  do {
    printMenu();
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addEntry(file);
        break;
      case 2:
        viewEntries(file);
        break;
      case 3:
        searchEntry(file);
        break;
      case 4:
        deleteEntry(file);
        break;
      case 5:
        printf("\nExiting program.");
        break;
      default:
        printf("\nInvalid choice. Please try again.");
    }
  } while(choice != 5);

  fclose(file);
  return 0;
}