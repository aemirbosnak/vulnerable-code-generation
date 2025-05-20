//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

#define MAX_ROOMS 5

typedef struct room {
  int x, y;
  struct room* next;
} room;

room* generateMaze(int numRooms) {
  srand(time(NULL));
  room* head = malloc(sizeof(room));
  head->x = rand() % WIDTH;
  head->y = rand() % HEIGHT;
  head->next = NULL;

  for (int i = 1; i < numRooms; i++) {
    room* newRoom = malloc(sizeof(room));
    newRoom->x = rand() % WIDTH;
    newRoom->y = rand() % HEIGHT;
    newRoom->next = NULL;

    head->next = newRoom;
    head = newRoom;
  }

  return head;
}

void drawMaze(room* head) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (head->x == x && head->y == y) {
        printf("%c", WALL_CHAR);
      } else {
        printf("%c", EMPTY_CHAR);
      }
    }
    printf("\n");
  }
}

int main() {
  room* maze = generateMaze(MAX_ROOMS);
  drawMaze(maze);

  return 0;
}