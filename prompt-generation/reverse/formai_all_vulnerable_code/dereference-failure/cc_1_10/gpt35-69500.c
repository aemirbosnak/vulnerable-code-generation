//FormAI DATASET v1.0 Category: Digital Diary ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct DiaryEntry {
  char date[20];
  char time[20];
  char content[200];
  struct DiaryEntry* next;
};

struct Diary {
  struct DiaryEntry* head;
};

struct Diary* createDiary() {
  struct Diary* diary = (struct Diary*) malloc(sizeof(struct Diary));
  diary->head = NULL;
  return diary;
}

void destroyDiary(struct Diary* diary) {
  struct DiaryEntry* current = diary->head;
  struct DiaryEntry* next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(diary);
}

void printDiary(struct Diary* diary) {
  printf("========== DIARY ==========\n");
  struct DiaryEntry* current = diary->head;
  while (current != NULL) {
    printf("%s %s\n", current->date, current->time);
    printf("%s\n", current->content);
    printf("---------------------------\n");
    current = current->next;
  }
}

void addEntry(struct Diary* diary, char* content) {
  time_t now = time(NULL);
  struct tm* now_tm = localtime(&now);
  char date[20];
  char time[20];
  strftime(date, sizeof(date), "%Y-%m-%d", now_tm);
  strftime(time, sizeof(time), "%H:%M:%S", now_tm);
  struct DiaryEntry* newEntry = (struct DiaryEntry*) malloc(sizeof(struct DiaryEntry));
  strcpy(newEntry->date, date);
  strcpy(newEntry->time, time);
  strcpy(newEntry->content, content);
  newEntry->next = diary->head;
  diary->head = newEntry;
}

int main() {
  struct Diary* diary = createDiary();

  addEntry(diary, "Hello World!");
  addEntry(diary, "This is a Digital Diary example program.");
  addEntry(diary, "It uses a linked list to store diary entries.");
  addEntry(diary, "Entries are displayed in reverse order.");
  addEntry(diary, "New entries are added to the beginning of the list.");
  addEntry(diary, "Thank you for using this program!");

  printDiary(diary);

  destroyDiary(diary);

  return 0;
}