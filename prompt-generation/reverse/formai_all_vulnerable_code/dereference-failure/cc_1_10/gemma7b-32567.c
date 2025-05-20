//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Path 5

typedef struct Room {
  int x, y;
  struct Room* next;
} Room;

Room* createMaze(int width, int height) {
  Room* head = malloc(sizeof(Room));
  head->x = 0;
  head->y = 0;
  head->next = NULL;

  srand(time(NULL));

  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      Room* newRoom = malloc(sizeof(Room));
      newRoom->x = c;
      newRoom->y = r;
      newRoom->next = NULL;

      if (rand() % MAX_Rooms == 0) {
        head->next = newRoom;
        head = newRoom;
      }
    }
  }

  return head;
}

void traverseMaze(Room* room) {
  // Traverse the maze and print the rooms
  while (room) {
    printf("(%d, %d)\n", room->x, room->y);
    room = room->next;
  }
}

int main() {
  Room* maze = createMaze(5, 5);
  traverseMaze(maze);

  return 0;
}