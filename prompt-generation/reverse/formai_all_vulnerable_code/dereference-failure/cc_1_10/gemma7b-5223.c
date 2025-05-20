//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10

typedef struct Planet {
  char name[20];
  int x, y, z;
  int population;
  struct Planet* next;
} Planet;

void explore_space(Planet** planets)
{
  int i, rand_num;
  Planet* current_planet = planets[0];

  printf("Exploring the cosmos...\n");

  for (i = 0; i < 10; i++)
  {
    rand_num = rand() % MAX_PLANETS;
    current_planet = planets[rand_num];

    printf("Current planet: %s\n", current_planet->name);
    printf("Population: %d\n", current_planet->population);
    printf("Coordinates: (%d, %d, %d)\n", current_planet->x, current_planet->y, current_planet->z);

    sleep(1);
  }
}

int main()
{
  Planet* planets = NULL;

  // Create a list of planets
  for (int i = 0; i < MAX_PLANETS; i++)
  {
    planets = malloc(sizeof(Planet));
    planets->name[0] = 'a' + i;
    planets->x = rand() % 1000;
    planets->y = rand() % 1000;
    planets->z = rand() % 1000;
    planets->population = rand() % 10000;
    planets->next = planets;
  }

  explore_space(&planets);

  return 0;
}