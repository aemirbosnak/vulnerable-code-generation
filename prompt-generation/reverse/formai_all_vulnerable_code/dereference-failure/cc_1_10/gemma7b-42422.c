//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CASTLES 10

typedef struct Castle {
  char name[20];
  int x, y;
  int health;
  int army_size;
  struct Castle *next;
} Castle;

Castle *castle_list = NULL;

void add_castle(char *name, int x, int y, int health, int army_size) {
  Castle *new_castle = malloc(sizeof(Castle));
  strcpy(new_castle->name, name);
  new_castle->x = x;
  new_castle->y = y;
  new_castle->health = health;
  new_castle->army_size = army_size;
  new_castle->next = NULL;

  if (castle_list == NULL) {
    castle_list = new_castle;
  } else {
    Castle *prev = castle_list;
    while (prev->next) {
      prev = prev->next;
    }
    prev->next = new_castle;
  }
}

void simulate_weather() {
  int rain_chance = rand() % 10;
  int wind_speed = rand() % 5;
  int temperature = rand() % 20;

  printf("The weather today is:");
  if (rain_chance > 5) {
    printf(" Rainy");
  } else if (wind_speed > 2) {
    printf(" Windy");
  } else {
    printf(" Pleasant");
  }

  printf(", with a temperature of %d degrees.", temperature);
  printf("\n");
}

int main() {
  add_castle("Castle A", 10, 10, 100, 100);
  add_castle("Castle B", 20, 20, 80, 80);
  add_castle("Castle C", 30, 30, 60, 60);

  simulate_weather();

  return 0;
}