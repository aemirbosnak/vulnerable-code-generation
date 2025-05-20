//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ATTACKERS 10

typedef struct Attacker {
  char name[20];
  int score;
  struct Attacker* next;
} Attacker;

Attacker* head = NULL;

void addAttacker(char* name, int score) {
  Attacker* newAttacker = malloc(sizeof(Attacker));
  strcpy(newAttacker->name, name);
  newAttacker->score = score;
  newAttacker->next = NULL;

  if (head == NULL) {
    head = newAttacker;
  } else {
    Attacker* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newAttacker;
  }
}

void printAttackers() {
  Attacker* current = head;
  while (current) {
    printf("%s (%d points)\n", current->name, current->score);
    current = current->next;
  }
}

void detectIntruder() {
  char* password = "SECRET";
  char input[20];

  printf("Enter password: ");
  scanf("%s", input);

  if (strcmp(input, password) == 0) {
    printf("Access granted.\n");
  } else {
    printf("Incorrect password.\n");
  }
}

int main() {
  addAttacker("John Doe", 50);
  addAttacker("Jane Doe", 60);
  addAttacker("Evil Hacker", 70);

  detectIntruder();

  printAttackers();

  return 0;
}