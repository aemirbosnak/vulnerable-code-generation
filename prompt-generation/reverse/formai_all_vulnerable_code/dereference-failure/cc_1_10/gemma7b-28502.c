//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: synchronous
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

#define MAX_ROOMS 10

typedef struct room {
  int x, y;
  struct room* next;
} room;

room* generate_maze(int seed) {
  srand(seed);

  room* head = NULL;
  room* current = NULL;

  for (int i = 0; i < MAX_ROOMS; i++) {
    room* new_room = malloc(sizeof(room));
    new_room->x = rand() % MAZE_WIDTH;
    new_room->y = rand() % MAZE_HEIGHT;

    if (head == NULL) {
      head = new_room;
      current = new_room;
    } else {
      current->next = new_room;
      current = new_room;
    }
  }

  return head;
}

void draw_maze(room* head) {
  for (int y = 0; y < MAZE_HEIGHT; y++) {
    for (int x = 0; x < MAZE_WIDTH; x++) {
      room* current = head;
      while (current) {
        if (current->x == x && current->y == y) {
          if (current->next) {
            printf(" ");
          } else {
            printf("#");
          }
        } else {
          printf("#");
        }
      }
      printf("\n");
    }
  }
}

int main() {
  room* head = generate_maze(time(NULL));
  draw_maze(head);

  return 0;
}