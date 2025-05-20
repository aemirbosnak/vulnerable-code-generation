//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define PLAYER_SIZE 2
#define MONSTER_SIZE 3

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void initialize_map(Cell **map) {
  for (int x = 0; x < MAP_SIZE; x++) {
    for (int y = 0; y < MAP_SIZE; y++) {
      map[x][y].x = x;
      map[x][y].y = y;
      map[x][y].state = 0;
    }
  }
}

void place_player(Cell **map, int x, int y) {
  map[x][y].state = PLAYER_SIZE;
}

void place_monster(Cell **map, int x, int y) {
  map[x][y].state = MONSTER_SIZE;
}

int main() {
  srand(time(NULL));

  Cell **map = (Cell **)malloc(MAP_SIZE * sizeof(Cell *));
  for (int i = 0; i < MAP_SIZE; i++) {
    map[i] = (Cell *)malloc(MAP_SIZE * sizeof(Cell));
  }

  initialize_map(map);
  place_player(map, 5, 5);
  place_monster(map, 2, 2);

  int player_x = 5;
  int player_y = 5;

  char input;

  while (1) {
    printf("Enter your move (w/a/s/d): ");
    scanf("%c", &input);

    switch (input) {
      case 'w':
        if (map[player_x][player_y - 1].state == 0) {
          player_y--;
        } else {
          printf("Move not allowed.\n");
        }
        break;
      case 'a':
        if (map[player_x - 1][player_y].state == 0) {
          player_x--;
        } else {
          printf("Move not allowed.\n");
        }
        break;
      case 's':
        if (map[player_x][player_y + 1].state == 0) {
          player_y++;
        } else {
          printf("Move not allowed.\n");
        }
        break;
      case 'd':
        if (map[player_x + 1][player_y].state == 0) {
          player_x++;
        } else {
          printf("Move not allowed.\n");
        }
        break;
      default:
        printf("Invalid input.\n");
    }

    if (map[player_x][player_y].state == MONSTER_SIZE) {
      printf("You have been slain! Game over.\n");
      break;
    }
  }

  free(map);

  return 0;
}