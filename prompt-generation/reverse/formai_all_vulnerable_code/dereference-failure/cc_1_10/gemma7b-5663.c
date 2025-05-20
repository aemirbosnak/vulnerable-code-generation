//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define MAP_SIZE 10

typedef struct MapPoint {
  int x;
  int y;
  struct MapPoint* next;
} MapPoint;

MapPoint* createMapPoint(int x, int y) {
  MapPoint* point = malloc(sizeof(MapPoint));
  point->x = x;
  point->y = y;
  point->next = NULL;
  return point;
}

void printMap(MapPoint* point) {
  while (point) {
    printf("(%d, %d) ", point->x, point->y);
    point = point->next;
  }
  printf("\n");
}

int main() {
  time_t t;
  srand(time(&t));

  MapPoint* map = createMapPoint(0, 0);
  map->next = createMapPoint(10, 10);
  map->next->next = createMapPoint(20, 20);

  printMap(map);

  int direction = rand() % 4;
  switch (direction) {
    case NORTH:
      map->y++;
      break;
    case EAST:
      map->x++;
      break;
    case SOUTH:
      map->y--;
      break;
    case WEST:
      map->x--;
      break;
  }

  printMap(map);

  return 0;
}