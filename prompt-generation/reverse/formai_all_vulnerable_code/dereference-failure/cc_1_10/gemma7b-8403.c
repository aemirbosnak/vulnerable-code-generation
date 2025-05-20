//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ROOM_NUM 20

typedef struct Room
{
  int x, y;
  int room_num;
  struct Room* next;
} Room;

Room* generate_map()
{
  srand(time(NULL));
  Room* head = malloc(sizeof(Room));
  head->x = 0;
  head->y = 0;
  head->room_num = 1;
  head->next = NULL;

  for (int i = 0; i < MAP_SIZE; i++)
  {
    for (int j = 0; j < MAP_SIZE; j++)
    {
      Room* new_room = malloc(sizeof(Room));
      new_room->x = i;
      new_room->y = j;
      new_room->room_num = head->room_num + 1;
      new_room->next = head->next;
      head->next = new_room;
    }
  }

  return head;
}

void print_map(Room* room)
{
  for (int i = 0; i < MAP_SIZE; i++)
  {
    for (int j = 0; j < MAP_SIZE; j++)
    {
      if (room->x == i && room->y == j)
      {
        printf("R");
      }
      else
      {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main()
{
  Room* map = generate_map();
  print_map(map);

  return 0;
}