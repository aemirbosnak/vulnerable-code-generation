//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_WIDTH 80
#define DUNGEON_HEIGHT 21

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  char symbol;
  int hp;
  int atk;
  int def;
} Entity;

typedef struct {
  Entity **entities;
  int num_entities;
} Dungeon;

Dungeon *dungeon_new() {
  Dungeon *dungeon = malloc(sizeof(Dungeon));
  dungeon->entities = malloc(sizeof(Entity *) * DUNGEON_WIDTH * DUNGEON_HEIGHT);
  dungeon->num_entities = 0;
  return dungeon;
}

void dungeon_free(Dungeon *dungeon) {
  for (int i = 0; i < DUNGEON_WIDTH * DUNGEON_HEIGHT; i++) {
    free(dungeon->entities[i]);
  }
  free(dungeon->entities);
  free(dungeon);
}

void dungeon_generate(Dungeon *dungeon) {
  for (int i = 0; i < DUNGEON_WIDTH * DUNGEON_HEIGHT; i++) {
    int x = i % DUNGEON_WIDTH;
    int y = i / DUNGEON_WIDTH;

    dungeon->entities[i] = malloc(sizeof(Entity));
    dungeon->entities[i]->symbol = '.';
    dungeon->entities[i]->hp = 0;
    dungeon->entities[i]->atk = 0;
    dungeon->entities[i]->def = 0;

    if (rand() % 100 < 20) {
      dungeon->entities[i]->symbol = '#';
      dungeon->entities[i]->hp = 100;
      dungeon->entities[i]->atk = 10;
      dungeon->entities[i]->def = 10;
    }

    if (rand() % 100 < 10) {
      dungeon->entities[i]->symbol = '@';
      dungeon->entities[i]->hp = 100;
      dungeon->entities[i]->atk = 10;
      dungeon->entities[i]->def = 10;
    }
  }
}

void dungeon_print(Dungeon *dungeon) {
  for (int i = 0; i < DUNGEON_WIDTH * DUNGEON_HEIGHT; i++) {
    int x = i % DUNGEON_WIDTH;
    int y = i / DUNGEON_WIDTH;

    printf("%c", dungeon->entities[i]->symbol);

    if (x == DUNGEON_WIDTH - 1) {
      printf("\n");
    }
  }
}

int main() {
  srand(time(NULL));

  Dungeon *dungeon = dungeon_new();
  dungeon_generate(dungeon);
  dungeon_print(dungeon);

  dungeon_free(dungeon);

  return 0;
}