//FormAI DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 50

struct diaryEntry {
  char date[11];
  char time[6];
  char content[1001];
};
typedef struct diaryEntry DiaryEntry;

int countEntries = 0;
DiaryEntry entries[MAX_ENTRIES];

void displayMenu() {
  printf("Digital Diary\n");
  printf("1. Add Entry\n");
  printf("2. View All Entries\n");
  printf("3. Search Entries\n");
  printf("4. Exit\n");
}

void addEntry() {
  if (countEntries == MAX_ENTRIES) {
    printf("Diary is full. Cannot add more entries.\n");
  } else {
    DiaryEntry entry;
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    sprintf(entry.date, "%02d/%02d/%d", localTime->tm_mday, localTime->tm_mon+1, localTime->tm_year+1900);
    sprintf(entry.time, "%02d:%02d", localTime->tm_hour, localTime->tm_min);
    printf("Enter the content of the diary entry (max 1000 characters):\n");
    getchar();
    fgets(entry.content, 1001, stdin);
    entry.content[strcspn(entry.content, "\n")] = '\0';
    entries[countEntries++] = entry;
    printf("Entry added successfully.\n");
  }
}

void viewAllEntries() {
  if (countEntries == 0) {
    printf("No entries found.\n");
  } else {
    printf("All Entries:\n");
    for (int i = 0; i < countEntries; i++) {
      printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
    }
  }
}

void searchEntries() {
  if (countEntries == 0) {
    printf("No entries found.\n");
  } else {
    char term[1001];
    printf("Enter the search term (max 1000 characters):\n");
    getchar();
    fgets(term, 1001, stdin);
    term[strcspn(term, "\n")] = '\0';
    printf("Search Results:\n");
    int flag = 0;
    for (int i = 0; i < countEntries; i++) {
      if (strstr(entries[i].content, term) != NULL) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
        flag = 1;
      }
    }
    if (flag == 0) {
      printf("No matching entries found.\n");
    }
  }
}

int main() {
  int choice;
  do {
    displayMenu();
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch(choice) {
      case 1: addEntry(); break;
      case 2: viewAllEntries(); break;
      case 3: searchEntries(); break;
      case 4: printf("Goodbye!\n"); break;
      default: printf("Invalid choice. Try again.\n"); break;
    }
  } while (choice != 4);
  return 0;
}