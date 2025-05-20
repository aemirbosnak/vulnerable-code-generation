//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
  int num;
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
} Room;

Room** generate_maze(int num_rooms) {
  Room** maze = malloc(num_rooms * sizeof(Room*));
  for (int i = 0; i < num_rooms; i++) {
    maze[i] = malloc(sizeof(Room));
    maze[i]->num = i + 1;
    maze[i]->north = NULL;
    maze[i]->south = NULL;
    maze[i]->east = NULL;
    maze[i]->west = NULL;
  }

  return maze;
}

void traverse_maze(Room* current_room) {
  printf("You are in room %d.\n", current_room->num);

  if (current_room->north) {
    printf("You can go north to room %d.\n", current_room->north->num);
  }

  if (current_room->south) {
    printf("You can go south to room %d.\n", current_room->south->num);
  }

  if (current_room->east) {
    printf("You can go east to room %d.\n", current_room->east->num);
  }

  if (current_room->west) {
    printf("You can go west to room %d.\n", current_room->west->num);
  }

  printf("Please enter your next move: ");
  int move = getchar();

  switch (move) {
    case 'n':
      traverse_maze(current_room->north);
      break;
    case 's':
      traverse_maze(current_room->south);
      break;
    case 'e':
      traverse_maze(current_room->east);
      break;
    case 'w':
      traverse_maze(current_room->west);
      break;
    default:
      printf("Invalid move.\n");
  }
}

int main() {
  int num_rooms = rand() % MAX_ROOMS + 1;
  Room** maze = generate_maze(num_rooms);

  traverse_maze(maze[0]);

  return 0;
}