//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct Room {
  int x, y;
  char name[20];
  struct Room* next;
} Room;

typedef struct Monster {
  int x, y;
  char name[20];
  struct Monster* next;
} Monster;

Room** create_room(int num_rooms) {
  Room** rooms = malloc(num_rooms * sizeof(Room*));
  for (int i = 0; i < num_rooms; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->x = rand() % 10;
    rooms[i]->y = rand() % 10;
    rooms[i]->name[0] = 'a' + i;
    rooms[i]->next = NULL;
  }
  return rooms;
}

Monster** create_monster(int num_monsters) {
  Monster** monsters = malloc(num_monsters * sizeof(Monster*));
  for (int i = 0; i < num_monsters; i++) {
    monsters[i] = malloc(sizeof(Monster));
    monsters[i]->x = rand() % 10;
    monsters[i]->y = rand() % 10;
    monsters[i]->name[0] = 'm' + i;
    monsters[i]->next = NULL;
  }
  return monsters;
}

void destroy_room(Room* room) {
  free(room);
}

void destroy_monster(Monster* monster) {
  free(monster);
}

int main() {
  srand(time(NULL));

  int num_rooms = rand() % MAX_ROOMS + 1;
  Room** rooms = create_room(num_rooms);

  int num_monsters = rand() % MAX_MONSTERS + 1;
  Monster** monsters = create_monster(num_monsters);

  for (int i = 0; i < num_rooms; i++) {
    printf("Room %c: (%d, %d)\n", rooms[i]->name[0], rooms[i]->x, rooms[i]->y);
  }

  for (int i = 0; i < num_monsters; i++) {
    printf("Monster %c: (%d, %d)\n", monsters[i]->name[0], monsters[i]->x, monsters[i]->y);
  }

  for (int i = 0; i < num_rooms; i++) {
    destroy_room(rooms[i]);
  }

  for (int i = 0; i < num_monsters; i++) {
    destroy_monster(monsters[i]);
  }

  return 0;
}