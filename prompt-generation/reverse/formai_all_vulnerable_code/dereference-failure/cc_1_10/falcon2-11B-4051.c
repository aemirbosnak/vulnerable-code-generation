//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 50
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
  int x, y, width, height, is_blocked;
} Room;

typedef struct {
  char *name;
  Room *rooms;
  int num_rooms;
} Game;

Game create_game() {
  Game game;
  game.num_rooms = MAX_ROOM;
  game.rooms = malloc(MAX_ROOM * sizeof(Room));
  srand(time(NULL));
  for (int i = 0; i < MAX_ROOM; i++) {
    Room *room = &game.rooms[i];
    room->x = rand() % MAX_WIDTH;
    room->y = rand() % MAX_HEIGHT;
    room->width = rand() % (MAX_WIDTH / 2);
    room->height = rand() % (MAX_HEIGHT / 2);
    room->is_blocked = 0;
  }
  return game;
}

void print_rooms(Game game) {
  for (int i = 0; i < game.num_rooms; i++) {
    Room *room = &game.rooms[i];
    printf("Room %d (x=%d, y=%d, width=%d, height=%d):\n", i, room->x, room->y, room->width, room->height);
    if (room->is_blocked) {
      printf("    Blocked\n");
    } else {
      for (int j = 0; j < room->width; j++) {
        for (int k = 0; k < room->height; k++) {
          if (j < room->width && k < room->height &&!room->is_blocked) {
            printf("    x=%d, y=%d\n", j, k);
          }
        }
      }
    }
  }
}

int main() {
  Game game = create_game();
  print_rooms(game);
  return 0;
}