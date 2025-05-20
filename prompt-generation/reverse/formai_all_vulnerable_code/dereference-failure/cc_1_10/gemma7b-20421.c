//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20
#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

#define NUM_ROOMS 5

typedef struct Room {
  int x, y;
  struct Room* next;
} Room;

Room* createRoom(int x, int y) {
  Room* room = malloc(sizeof(Room));
  room->x = x;
  room->y = y;
  room->next = NULL;
  return room;
}

void generateMaze(int seed) {
  srand(seed);

  // Create the maze grid
  int** maze = malloc(MAZE_SIZE * sizeof(int*));
  for (int i = 0; i < MAZE_SIZE; i++) {
    maze[i] = malloc(MAZE_SIZE * sizeof(int));
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze[i][j] = EMPTY_CHAR;
    }
  }

  // Create the rooms
  Room* rooms = NULL;
  for (int i = 0; i < NUM_ROOMS; i++) {
    rooms = createRoom(rand() % MAZE_SIZE, rand() % MAZE_SIZE);
    rooms->next = rooms;
  }

  // Connect the rooms
  for (Room* room = rooms; room; room = room->next) {
    int dx = rand() % 4 - 1;
    int dy = rand() % 4 - 1;
    if (dx && dy) {
      maze[room->x + dx][room->y + dy] = WALL_CHAR;
    }
  }

  // Print the maze
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  generateMaze(time(NULL));
  return 0;
}