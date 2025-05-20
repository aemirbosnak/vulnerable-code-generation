//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

typedef struct {
  int x;
  int y;
} Node;

Node *get_neighbours(int *map, int x, int y) {
  Node *neighbours = malloc(4 * sizeof(Node));
  int count = 0;
  if ((x - 1) >= 0 && *(map + (x - 1) * COL + y) == 0) {
    (neighbours + count)->x = x - 1;
    (neighbours + count)->y = y;
    count++;
  }
  if ((x + 1) < ROW && *(map + (x + 1) * COL + y) == 0) {
    (neighbours + count)->x = x + 1;
    (neighbours + count)->y = y;
    count++;
  }
  if ((y - 1) >= 0 && *(map + x * COL + (y - 1)) == 0) {
    (neighbours + count)->x = x;
    (neighbours + count)->y = y - 1;
    count++;
  }
  if ((y + 1) < COL && *(map + x * COL + (y + 1)) == 0) {
    (neighbours + count)->x = x;
    (neighbours + count)->y = y + 1;
    count++;
  }
  if (count == 0) {
    free(neighbours);
    return NULL;
  }
  return neighbours;
}

void print_map(int *map, int x, int y) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if (*(map + i * COL + j) == 1) {
        printf("+ ");
      } else if (*(map + i * COL + j) == 2) {
        if (i == x && j == y) {
          printf("@ ");
        } else {
          printf("X ");
        }
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void reconstruct_path(int *map, Node *came_from, Node current) {
  if (current.x == 0 && current.y == 0) {
    return;
  }
  *(map + current.x * COL + current.y) = 2;
  Node next = *(came_from + current.x * COL + current.y);
  reconstruct_path(map, came_from, next);
}

void A_star(int *map, Node start, Node end) {
  int *closed_set = calloc(ROW * COL, sizeof(int));
  int *open_set = calloc(ROW * COL, sizeof(int));
  *(open_set + start.x * COL + start.y) = 1;

  Node *came_from = malloc(ROW * COL * sizeof(Node));

  int *g_score = malloc(ROW * COL * sizeof(int));
  for (int i = 0; i < ROW * COL; i++) {
    *(g_score + i) = ROW * COL + 1;
  }
  *(g_score + start.x * COL + start.y) = 0;

  int *f_score = malloc(ROW * COL * sizeof(int));
  for (int i = 0; i < ROW * COL; i++) {
    *(f_score + i) = ROW * COL + 1;
  }
  *(f_score + start.x * COL + start.y) = abs(start.x - end.x) + abs(start.y - end.y);

  while (1) {
    int min_score = ROW * COL + 1;
    Node current;
    for (int i = 0; i < ROW * COL; i++) {
      if (*(open_set + i) == 1 && *(f_score + i) < min_score) {
        min_score = *(f_score + i);
        current.x = i / COL;
        current.y = i % COL;
      }
    }

    if (current.x == end.x && current.y == end.y) {
      printf("Path found!\n");
      reconstruct_path(map, came_from, end);
      break;
    }

    *(open_set + current.x * COL + current.y) = 0;
    *(closed_set + current.x * COL + current.y) = 1;

    Node *neighbours = get_neighbours(map, current.x, current.y);
    for (int i = 0; i < 4; i++) {
      if (neighbours == NULL) {
        break;
      }
      Node neighbour = *(neighbours + i);
      if (*(closed_set + neighbour.x * COL + neighbour.y) == 1) {
        continue;
      }
      int tentative_g_score = *(g_score + current.x * COL + current.y) + 1;
      if (*(open_set + neighbour.x * COL + neighbour.y) == 0) {
        *(open_set + neighbour.x * COL + neighbour.y) = 1;
      } else if (tentative_g_score >= *(g_score + neighbour.x * COL + neighbour.y)) {
        continue;
      }

      *(came_from + neighbour.x * COL + neighbour.y) = current;
      *(g_score + neighbour.x * COL + neighbour.y) = tentative_g_score;
      *(f_score + neighbour.x * COL + neighbour.y) =
          tentative_g_score + abs(neighbour.x - end.x) + abs(neighbour.y - end.y);
    }
    free(neighbours);
  }

  free(closed_set);
  free(open_set);
  free(came_from);
  free(g_score);
  free(f_score);
}

int main(void) {
  int map[ROW][COL] = {
      {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
      {0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
      {0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
      {0, 1, 1, 0, 0, 1, 0, 0, 1, 0},
      {1, 1, 0, 1, 0, 0, 1, 0, 0, 0},
      {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}
  };
  Node start = {0, 0};
  Node end = {9, 9};
  printf("Original map:\n");
  print_map(map, -1, -1);
  printf("\n");
  A_star((int *) map, start, end);
  printf("\n");
  printf("Result:\n");
  print_map(map, -1, -1);
  return 0;
}