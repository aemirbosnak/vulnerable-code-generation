//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_SHIP_SIZE 10

typedef struct Ship
{
  char name[MAX_NAME_LENGTH];
  int size;
  struct Ship* next;
} Ship;

void createShip(Ship** head)
{
  *head = malloc(sizeof(Ship));
  (*head)->name[0] = '\0';
  (*head)->size = 0;
  (*head)->next = NULL;
}

void addShip(Ship* head, char* name, int size)
{
  Ship* newShip = malloc(sizeof(Ship));
  newShip->name[0] = '\0';
  newShip->size = size;
  newShip->next = NULL;

  if (head == NULL)
  {
    head = newShip;
  }
  else
  {
    head->next = newShip;
  }

  strcpy(newShip->name, name);
  head = newShip;
}

int main()
{
  Ship* fleet = NULL;
  createShip(&fleet);

  addShip(fleet, "The Dreadnought", 5);
  addShip(fleet, "The Dauntless", 3);
  addShip(fleet, "The Lightning", 7);

  time_t t = time(NULL);
  srand(t);

  int battleRound = 0;
  while (fleet->next)
  {
    int targetShipIndex = rand() % (fleet->next->size);
    Ship* targetShip = fleet->next;

    for (int i = 0; i < targetShipIndex; i++)
    {
      if (targetShip->next)
      {
        targetShip = targetShip->next;
      }
      else
      {
        targetShip = NULL;
      }
    }

    if (targetShip)
    {
      printf("The %s has been destroyed!\n", targetShip->name);
      free(targetShip);
    }

    battleRound++;
  }

  printf("The battle has ended after %d rounds.\n", battleRound);

  return 0;
}