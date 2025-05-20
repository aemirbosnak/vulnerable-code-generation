//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACY_THEORIES 10

typedef struct ConspiracyTheory {
  char *title;
  char *description;
  char **evidence;
  int suspicious_characters;
  struct ConspiracyTheory *next;
} ConspiracyTheory;

ConspiracyTheory *createConspiracyTheory(char *title, char *description, char **evidence, int suspicious_characters) {
  ConspiracyTheory *newTheory = malloc(sizeof(ConspiracyTheory));
  newTheory->title = strdup(title);
  newTheory->description = strdup(description);
  newTheory->evidence = evidence;
  newTheory->suspicious_characters = suspicious_characters;
  newTheory->next = NULL;
  return newTheory;
}

ConspiracyTheory *addConspiracyTheory(ConspiracyTheory *head, char *title, char *description, char **evidence, int suspicious_characters) {
  ConspiracyTheory *newTheory = createConspiracyTheory(title, description, evidence, suspicious_characters);
  if (head == NULL) {
    head = newTheory;
  } else {
    newTheory->next = head;
    head = newTheory;
  }
  return head;
}

void printConspiracyTheory(ConspiracyTheory *theory) {
  printf("**Title:** %s\n", theory->title);
  printf("**Description:** %s\n", theory->description);
  printf("**Evidence:**\n");
  for (int i = 0; theory->evidence[i] != NULL; i++) {
    printf("- %s\n", theory->evidence[i]);
  }
  printf("**Suspicious Characters:** %d\n", theory->suspicious_characters);
  printf("\n");
}

int main() {
  time_t t = time(NULL);
  srand(t);

  ConspiracyTheory *head = NULL;
  for (int i = 0; i < MAX_CONSPIRACY_THEORIES; i++) {
    char *title = "Conspiracy Theory #" + rand() % MAX_CONSPIRACY_THEORIES;
    char *description = "A nefarious plot involving..." + rand() % 1000;
    char **evidence = malloc(10 * sizeof(char *));
    evidence[0] = "A mysterious coded message";
    evidence[1] = "A suspicious financial transaction";
    evidence[2] = "A series of cryptic emails";
    evidence[3] = "A trail of blood";
    evidence[4] = "A hidden compartment";
    evidence[5] = "A forged document";
    evidence[6] = "A secret meeting";
    evidence[7] = "A coded rendezvous";
    evidence[8] = "A mysterious package";
    evidence[9] = "A disappearing asset";
    int suspicious_characters = rand() % 5 + 1;

    addConspiracyTheory(head, title, description, evidence, suspicious_characters);
  }

  printConspiracyTheory(head);

  return 0;
}