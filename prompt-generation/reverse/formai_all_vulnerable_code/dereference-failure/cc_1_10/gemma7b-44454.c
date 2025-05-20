//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SECRET_KEY_LENGTH 16
#define NUM_CONSPIRACY_THEORIES 5

typedef struct ConspiracyTheory {
  char* title;
  char* description;
  int evidence_points;
  struct ConspiracyTheory* next;
} ConspiracyTheory;

ConspiracyTheory* createConspiracyTheory(char* title, char* description, int evidence_points) {
  ConspiracyTheory* theory = malloc(sizeof(ConspiracyTheory));
  theory->title = strdup(title);
  theory->description = strdup(description);
  theory->evidence_points = evidence_points;
  theory->next = NULL;
  return theory;
}

ConspiracyTheory* generateConspiracyTheoryList() {
  srand(time(NULL));
  ConspiracyTheory* head = NULL;
  for (int i = 0; i < NUM_CONSPIRACY_THEORIES; i++) {
    char* title = "Theory #" + rand() % 10;
    char* description = "This theory alleges that..." + rand() % 200;
    int evidence_points = rand() % 10 + 1;
    ConspiracyTheory* theory = createConspiracyTheory(title, description, evidence_points);
    if (head == NULL) {
      head = theory;
    } else {
      theory->next = head;
      head = theory;
    }
  }
  return head;
}

void printConspiracyTheory(ConspiracyTheory* theory) {
  printf("Title: %s\n", theory->title);
  printf("Description: %s\n", theory->description);
  printf("Evidence Points: %d\n", theory->evidence_points);
  printf("\n");
}

int main() {
  ConspiracyTheory* head = generateConspiracyTheoryList();
  printConspiracyTheory(head);
  return 0;
}