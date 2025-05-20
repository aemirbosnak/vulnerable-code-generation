//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_DIRECTIONS 4

typedef struct room {
  char* name;
  char* description;
  struct room* directions[MAX_DIRECTIONS];
} room;

room* create_room(char* name, char* description) {
  room* r = malloc(sizeof(room));
  r->name = strdup(name);
  r->description = strdup(description);
  for (int i = 0; i < MAX_DIRECTIONS; i++) {
    r->directions[i] = NULL;
  }
  return r;
}

void destroy_room(room* r) {
  free(r->name);
  free(r->description);
  free(r);
}

void connect_rooms(room* r1, room* r2, int direction) {
  r1->directions[direction] = r2;
  r2->directions[opposite_direction(direction)] = r1;
}

int opposite_direction(int direction) {
  switch (direction) {
    case 0:
      return 2;
    case 1:
      return 3;
    case 2:
      return 0;
    case 3:
      return 1;
  }
  return -1;
}

void print_room(room* r) {
  printf("%s\n", r->name);
  printf("%s\n", r->description);
  printf("Exits:");
  for (int i = 0; i < MAX_DIRECTIONS; i++) {
    if (r->directions[i] != NULL) {
      printf(" %s", r->directions[i]->name);
    }
  }
  printf("\n");
}

int main() {
  room* rooms[MAX_ROOMS];

  rooms[0] = create_room("The Lobby", "A large, open room with a high ceiling. A grand staircase leads up to the second floor.");
  rooms[1] = create_room("The Library", "A cozy room with floor-to-ceiling bookshelves. A large fireplace crackles in the corner.");
  rooms[2] = create_room("The Dining Room", "A formal dining room with a long, mahogany table. A chandelier hangs from the ceiling.");
  rooms[3] = create_room("The Kitchen", "A large, industrial kitchen with stainless steel appliances. A chef is busy preparing a meal.");
  rooms[4] = create_room("The Master Bedroom", "A spacious bedroom with a king-sized bed. A large window overlooks the garden.");
  rooms[5] = create_room("The Guest Bedroom", "A smaller bedroom with a double bed. A desk and chair are in the corner.");
  rooms[6] = create_room("The Bathroom", "A large bathroom with a marble bathtub, shower, and toilet.");
  rooms[7] = create_room("The Attic", "A dusty attic with boxes and old furniture. A small window provides a view of the stars.");
  rooms[8] = create_room("The Basement", "A dark, damp basement with a dirt floor. A few old tools are scattered around.");
  rooms[9] = create_room("The Garden", "A beautiful garden with flowers, trees, and a small pond. A stone path leads to a gazebo.");

  connect_rooms(rooms[0], rooms[1], 0);
  connect_rooms(rooms[0], rooms[2], 1);
  connect_rooms(rooms[0], rooms[3], 2);
  connect_rooms(rooms[1], rooms[4], 2);
  connect_rooms(rooms[1], rooms[5], 3);
  connect_rooms(rooms[2], rooms[6], 3);
  connect_rooms(rooms[3], rooms[7], 1);
  connect_rooms(rooms[3], rooms[8], 2);
  connect_rooms(rooms[4], rooms[9], 0);
  connect_rooms(rooms[5], rooms[9], 1);
  connect_rooms(rooms[6], rooms[9], 2);

  room* current_room = rooms[0];

  while (1) {
    print_room(current_room);
    printf("Which direction do you want to go? ");
    char direction[10];
    scanf("%s", direction);
    int dir = -1;
    if (strcmp(direction, "north") == 0) {
      dir = 0;
    } else if (strcmp(direction, "east") == 0) {
      dir = 1;
    } else if (strcmp(direction, "south") == 0) {
      dir = 2;
    } else if (strcmp(direction, "west") == 0) {
      dir = 3;
    }
    if (dir != -1 && current_room->directions[dir] != NULL) {
      current_room = current_room->directions[dir];
    } else {
      printf("You can't go that way.\n");
    }
  }

  for (int i = 0; i < MAX_ROOMS; i++) {
    destroy_room(rooms[i]);
  }

  return 0;
}