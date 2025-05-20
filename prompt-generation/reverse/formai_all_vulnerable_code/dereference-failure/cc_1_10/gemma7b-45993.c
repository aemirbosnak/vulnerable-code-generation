//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 20
#define MAX_WALL_NUM 50

typedef struct Room {
  int num;
  struct Room* next;
  struct Wall** walls;
} Room;

typedef struct Wall {
  int num;
  struct Wall* next;
  struct Room* room1;
  struct Room* room2;
} Wall;

void generateMaze(int seed) {
  srand(seed);
  int numRooms = rand() % MAX_ROOM_NUM + 1;
  int numWalls = rand() % MAX_WALL_NUM + 1;

  // Create rooms
  Room** rooms = malloc(numRooms * sizeof(Room));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->num = i + 1;
    rooms[i]->next = NULL;
    rooms[i]->walls = NULL;
  }

  // Create walls
  Wall** walls = malloc(numWalls * sizeof(Wall));
  for (int i = 0; i < numWalls; i++) {
    walls[i] = malloc(sizeof(Wall));
    walls[i]->num = i + 1;
    walls[i]->next = NULL;
    walls[i]->room1 = NULL;
    walls[i]->room2 = NULL;
  }

  // Connect rooms and walls
  for (int i = 0; i < numWalls; i++) {
    walls[i]->room1 = rooms[rand() % numRooms];
    walls[i]->room2 = rooms[rand() % numRooms];
  }

  // Print the maze
  for (int i = 0; i < numRooms; i++) {
    printf("Room %d:\n", rooms[i]->num);
    for (int j = 0; j < rooms[i]->walls; j++) {
      printf("  Wall %d to Room %d\n", walls[j]->num, walls[j]->room2->num);
    }
  }
}

int main() {
  generateMaze(time(NULL));
  return 0;
}