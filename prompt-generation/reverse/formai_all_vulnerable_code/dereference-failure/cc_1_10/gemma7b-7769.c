//Gemma-7B DATASET v1.0 Category: System administration ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 256

typedef struct CoffeeMug {
  char* name;
  int capacity;
  double price;
} CoffeeMug;

typedef struct SurrealistDatabase {
  CoffeeMug** mugs;
  int numMugs;
  int nextMugIndex;
} SurrealistDatabase;

SurrealistDatabase* initialiseSurrealistDatabase(int numMugs) {
  SurrealistDatabase* database = malloc(sizeof(SurrealistDatabase));
  database->mugs = malloc(numMugs * sizeof(CoffeeMug));
  database->numMugs = numMugs;
  database->nextMugIndex = 0;

  return database;
}

void addMugToSurrealistDatabase(SurrealistDatabase* database, CoffeeMug* mug) {
  database->mugs[database->nextMugIndex++] = mug;
}

int main() {
  SurrealistDatabase* database = initialiseSurrealistDatabase(10);

  CoffeeMug* mug1 = malloc(sizeof(CoffeeMug));
  mug1->name = "The Mug of Perpetual Contemplation";
  mug1->capacity = 200;
  mug1->price = 10.00;
  addMugToSurrealistDatabase(database, mug1);

  CoffeeMug* mug2 = malloc(sizeof(CoffeeMug));
  mug2->name = "The Mug of Quantum Fluctuations";
  mug2->capacity = 300;
  mug2->price = 15.00;
  addMugToSurrealistDatabase(database, mug2);

  CoffeeMug* mug3 = malloc(sizeof(CoffeeMug));
  mug3->name = "The Mug of Perpetual Motion";
  mug3->capacity = 400;
  mug3->price = 20.00;
  addMugToSurrealistDatabase(database, mug3);

  printf("Surrealist Database:\n");
  for (int i = 0; i < database->numMugs; i++) {
    printf("  - Mug name: %s\n", database->mugs[i]->name);
    printf("  - Mug capacity: %d\n", database->mugs[i]->capacity);
    printf("  - Mug price: %.2lf\n", database->mugs[i]->price);
  }

  return 0;
}