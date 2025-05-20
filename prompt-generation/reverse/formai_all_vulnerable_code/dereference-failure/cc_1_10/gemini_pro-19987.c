//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_EXITS 4

typedef struct {
  char *name;
  char *description;
  int exits[MAX_EXITS];
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;

void create_room(char *name, char *description) {
  rooms[num_rooms].name = malloc(strlen(name) + 1);
  strcpy(rooms[num_rooms].name, name);
  rooms[num_rooms].description = malloc(strlen(description) + 1);
  strcpy(rooms[num_rooms].description, description);
  for (int i = 0; i < MAX_EXITS; i++) {
    rooms[num_rooms].exits[i] = -1;
  }
  num_rooms++;
}

void add_exit(int room1, int room2) {
  for (int i = 0; i < MAX_EXITS; i++) {
    if (rooms[room1].exits[i] == -1) {
      rooms[room1].exits[i] = room2;
      return;
    }
  }
}

void print_room(int room) {
  printf("%s\n", rooms[room].name);
  printf("%s\n", rooms[room].description);
  printf("Exits:");
  for (int i = 0; i < MAX_EXITS; i++) {
    if (rooms[room].exits[i] != -1) {
      printf(" %s", rooms[rooms[room].exits[i]].name);
    }
  }
  printf("\n");
}

int main() {
  // Create rooms
  create_room("Foyer", "You are in a small foyer. There is a door to the north.");
  create_room("Living Room", "You are in a large living room. There is a door to the south.");
  create_room("Kitchen", "You are in a small kitchen. There is a door to the east.");

  // Add exits
  add_exit(0, 1);
  add_exit(1, 0);
  add_exit(1, 2);
  add_exit(2, 1);

  // Game loop
  int current_room = 0;
  while (1) {
    // Print room
    print_room(current_room);

    // Get player input
    char input[100];
    printf("> ");
    fgets(input, 100, stdin);

    // Parse command
    if (strcmp(input, "north\n") == 0) {
      current_room = rooms[current_room].exits[0];
    } else if (strcmp(input, "south\n") == 0) {
      current_room = rooms[current_room].exits[1];
    } else if (strcmp(input, "east\n") == 0) {
      current_room = rooms[current_room].exits[2];
    } else if (strcmp(input, "west\n") == 0) {
      current_room = rooms[current_room].exits[3];
    } else if (strcmp(input, "quit\n") == 0) {
      break;
    }
  }

  return 0;
}