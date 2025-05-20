//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10
#define MAX_WALL_NUM 20

typedef struct Room {
  int num;
  struct Room* next;
  struct Wall* walls;
} Room;

typedef struct Wall {
  int num;
  struct Wall* next;
  struct Room* to_room;
} Wall;

Room* generate_room(int num) {
  Room* new_room = malloc(sizeof(Room));
  new_room->num = num;
  new_room->next = NULL;
  new_room->walls = NULL;
  return new_room;
}

Wall* generate_wall(int num, Room* to_room) {
  Wall* new_wall = malloc(sizeof(Wall));
  new_wall->num = num;
  new_wall->next = NULL;
  new_wall->to_room = to_room;
  return new_wall;
}

void generate_maze(int seed) {
  srand(seed);
  int num_rooms = rand() % MAX_ROOM_NUM + 1;
  Room* head = generate_room(0);

  for (int i = 0; i < num_rooms; i++) {
    Room* new_room = generate_room(i + 1);
    new_room->next = head;
    head = new_room;
  }

  for (int i = 0; i < MAX_WALL_NUM; i++) {
    Wall* new_wall = generate_wall(rand() % num_rooms, head);
    new_wall->next = head->walls;
    head->walls = new_wall;
  }
}

int main() {
  generate_maze(time(NULL));
  return 0;
}