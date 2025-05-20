//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define ROOM_COUNT 50

typedef struct Room {
  int x, y;
  struct Room* next;
} Room;

Room* create_room(int x, int y) {
  Room* room = malloc(sizeof(Room));
  room->x = x;
  room->y = y;
  room->next = NULL;
  return room;
}

void generate_maze() {
  srand(time(NULL));

  Room* head = create_room(0, 0);
  Room* tail = head;

  for (int i = 0; i < ROOM_COUNT; i++) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;

    Room* new_room = create_room(x, y);

    if (tail) {
      tail->next = new_room;
      tail = new_room;
    } else {
      head = new_room;
      tail = new_room;
    }
  }

  tail = head;
  while (tail) {
    printf("(%d, %d)\n", tail->x, tail->y);
    tail = tail->next;
  }
}

int main() {
  generate_maze();

  return 0;
}