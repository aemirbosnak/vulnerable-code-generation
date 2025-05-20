//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define MAX_ROOMS 5

typedef struct Room {
  int x, y;
  struct Room* next;
} Room;

Room** generateRooms(int numRooms) {
  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = malloc(sizeof(Room));
  }

  // Generate room positions
  for (int i = 0; i < numRooms; i++) {
    rooms[i]->x = rand() % WIDTH;
    rooms[i]->y = rand() % HEIGHT;
  }

  // Connect rooms
  for (int i = 0; i < numRooms - 1; i++) {
    rooms[i]->next = rooms[rand() % numRooms];
  }

  return rooms;
}

int main() {
  srand(time(NULL));

  // Generate a maze
  Room** rooms = generateRooms(MAX_ROOMS);

  // Print the maze
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i]->x == x && rooms[i]->y == y) {
          printf("O ");
        } else {
          printf(". ");
        }
      }
    }
    printf("\n");
  }

  return 0;
}