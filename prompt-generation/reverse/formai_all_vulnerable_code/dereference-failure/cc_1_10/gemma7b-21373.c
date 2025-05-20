//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Claude Shannon
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
  int health;
  struct Monster* next;
} Monster;

void generateRooms(Room* head) {
  for (int i = 0; i < MAX_ROOMS; i++) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->name[0] = 'A' + i;
    newRoom->next = head;
    head = newRoom;
  }
}

void generateMonsters(Monster* head) {
  for (int i = 0; i < MAX_MONSTERS; i++) {
    Monster* newMonster = malloc(sizeof(Monster));
    newMonster->name[0] = 'M' + i;
    newMonster->health = rand() % 10 + 1;
    newMonster->next = head;
    head = newMonster;
  }
}

int main() {
  srand(time(NULL));

  Room* rooms = NULL;
  generateRooms(rooms);

  Monster* monsters = NULL;
  generateMonsters(monsters);

  // Play the game
  // ...

  return 0;
}