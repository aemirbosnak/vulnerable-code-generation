//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Knight {
  char name[20];
  int strength, stamina, position;
  struct Knight* next;
} Knight;

Knight* insertKnight(Knight* head, char name, int strength, int stamina) {
  Knight* newKnight = malloc(sizeof(Knight));
  strcpy(newKnight->name, name);
  newKnight->strength = strength;
  newKnight->stamina = stamina;
  newKnight->position = 0;
  newKnight->next = NULL;

  if (head == NULL) {
    head = newKnight;
  } else {
    Knight* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newKnight;
  }

  return head;
}

void battle(Knight* knight1, Knight* knight2) {
  int round = 1;
  while (knight1->stamina > 0 && knight2->stamina > 0) {
    printf("Round %d: ", round++);
    int damage = knight1->strength - knight2->strength;
    if (damage > knight2->stamina) {
      damage = knight2->stamina;
    }
    knight2->stamina -= damage;
    printf("%s deals %d damage to %s.\n", knight1->name, damage, knight2->name);
    if (knight2->stamina <= 0) {
      printf("%s has been defeated!\n", knight2->name);
    }
  }

  if (knight1->stamina > knight2->stamina) {
    printf("%s has won the battle!\n", knight1->name);
  } else {
    printf("%s has won the battle!\n", knight2->name);
  }
}

int main() {
  Knight* head = NULL;
  insertKnight(head, "Sir Robin", 10, 100);
  insertKnight(head, "Sir William", 8, 80);
  insertKnight(head, "Sir Gareth", 9, 90);

  battle(head->next, head);

  return 0;
}