//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Connections 5

typedef struct Room {
  char name[20];
  struct Room** connections;
  int numConnections;
} Room;

Room** generateMaze(int numRooms) {
  Room** rooms = (Room**)malloc(numRooms * sizeof(Room));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = (Room*)malloc(sizeof(Room));
    rooms[i]->name[0] = '\0';
    rooms[i]->connections = NULL;
    rooms[i]->numConnections = 0;
  }

  // Connect rooms randomly
  for (int i = 0; i < numRooms; i++) {
    for (int j = 0; j < rooms[i]->numConnections; j++) {
      rooms[i]->connections[j] = rooms[rand() % numRooms];
    }
  }

  return rooms;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the maze
  Room** maze = generateMaze(MAX_Rooms);

  // Print the maze
  for (int i = 0; i < MAX_Rooms; i++) {
    printf("Room: %s\n", maze[i]->name);
    printf("Connections:");
    for (int j = 0; j < maze[i]->numConnections; j++) {
      printf(" %s", maze[i]->connections[j]->name);
    }
    printf("\n");
  }

  return 0;
}