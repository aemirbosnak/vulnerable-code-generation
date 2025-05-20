//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_ROWS 20
#define MAX_COLS 40

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point top_left;
  Point bottom_right;
} Rectangle;

typedef struct {
  int x, y;
  char symbol;
} Cell;

Cell **generate_map(int rows, int cols) {
  Cell **map = malloc(rows * sizeof(Cell *));
  for (int i = 0; i < rows; i++) {
    map[i] = malloc(cols * sizeof(Cell));
    for (int j = 0; j < cols; j++) {
      map[i][j].symbol = '.';
    }
  }
  return map;
}

void generate_room(int x, int y, int width, int height, Cell **map) {
  for (int i = x; i < x + width; i++) {
    for (int j = y; j < y + height; j++) {
      map[j][i].symbol = '#';
    }
  }
}

void generate_rooms(Cell **map, int num_rooms) {
  int room_width, room_height;
  srand(time(NULL));
  for (int i = 0; i < num_rooms; i++) {
    room_width = rand() % 10 + 5;
    room_height = rand() % 10 + 5;
    int room_x = rand() % (MAX_ROWS - room_width) + 1;
    int room_y = rand() % (MAX_COLS - room_height) + 1;
    generate_room(room_x, room_y, room_width, room_height, map);
  }
}

void print_map(Cell **map, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c", map[i][j].symbol);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  Cell **map = generate_map(MAX_ROWS, MAX_COLS);
  generate_rooms(map, 10);
  print_map(map, MAX_ROWS, MAX_COLS);
  return 0;
}