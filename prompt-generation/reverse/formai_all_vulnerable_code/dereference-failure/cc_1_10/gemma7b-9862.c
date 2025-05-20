//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct Room {
  char name[20];
  struct Room* next;
  struct Monster* monsters;
} Room;

typedef struct Monster {
  char name[20];
  int hp;
  int attack;
} Monster;

Room* generate_room(int num) {
  Room* room = malloc(sizeof(Room));
  room->name[0] = '\0';
  sprintf(room->name, "Room %d", num);
  room->next = NULL;
  room->monsters = NULL;

  return room;
}

Monster* generate_monster(int num) {
  Monster* monster = malloc(sizeof(Monster));
  monster->name[0] = '\0';
  sprintf(monster->name, "Monster %d", num);
  monster->hp = rand() % 10 + 1;
  monster->attack = rand() % 5 + 1;

  return monster;
}

void main() {
  srand(time(NULL));

  Room* rooms = generate_room(1);
  rooms->monsters = generate_monster(1);

  printf("You are in the %s.\n", rooms->name);
  printf("There is a %s with %d HP and an attack of %d.\n", rooms->monsters->name, rooms->monsters->hp, rooms->monsters->attack);

  free(rooms);
  free(rooms->monsters);
}