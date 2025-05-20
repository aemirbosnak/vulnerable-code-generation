//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_THINGS 10

typedef struct Thing {
  char name[20];
  int x, y;
  int hp, mp;
  struct Thing *next;
} Thing;

Thing *things = NULL;

void addThing(char *name, int x, int y, int hp, int mp) {
  Thing *newThing = malloc(sizeof(Thing));
  strcpy(newThing->name, name);
  newThing->x = x;
  newThing->y = y;
  newThing->hp = hp;
  newThing->mp = mp;
  newThing->next = things;
  things = newThing;
}

void moveThing(Thing *thing, int dx, int dy) {
  thing->x += dx;
  thing->y += dy;
}

void attackThing(Thing *attacker, Thing *defender) {
  defender->hp -= attacker->mp;
  if (defender->hp <= 0) {
    printf("%s has slain %s!\n", attacker->name, defender->name);
    free(defender);
  }
}

int main() {
  srand(time(NULL));

  addThing("The Great Space Whale", 0, 0, 100, 50);
  addThing("The Flying Cheese", 10, 10, 50, 20);
  addThing("The Quantum Cat", 20, 0, 20, 30);

  moveThing(things, 5, 5);
  moveThing(things->next, -2, 3);
  attackThing(things, things->next);

  return 0;
}