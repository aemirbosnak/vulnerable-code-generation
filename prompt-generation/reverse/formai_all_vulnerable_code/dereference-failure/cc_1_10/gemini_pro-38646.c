//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The main character of our story
struct Character {
  char *name;
  int age;
  int bravery;
  int sanity;
};

// The haunted house
struct House {
  char *name;
  int num_rooms;
  struct Room *rooms;
};

// A room in the haunted house
struct Room {
  char *name;
  int danger_level;
  int sanity_loss;
};

// Function to create a new character
struct Character *create_character(char *name, int age, int bravery, int sanity) {
  struct Character *character = malloc(sizeof(struct Character));
  character->name = name;
  character->age = age;
  character->bravery = bravery;
  character->sanity = sanity;
  return character;
}

// Function to create a new house
struct House *create_house(char *name, int num_rooms) {
  struct House *house = malloc(sizeof(struct House));
  house->name = name;
  house->num_rooms = num_rooms;
  house->rooms = malloc(sizeof(struct Room) * num_rooms);
  return house;
}

// Function to create a new room
struct Room *create_room(char *name, int danger_level, int sanity_loss) {
  struct Room *room = malloc(sizeof(struct Room));
  room->name = name;
  room->danger_level = danger_level;
  room->sanity_loss = sanity_loss;
  return room;
}

// Function to print the character's status
void print_character(struct Character *character) {
  printf("Name: %s\n", character->name);
  printf("Age: %d\n", character->age);
  printf("Bravery: %d\n", character->bravery);
  printf("Sanity: %d\n", character->sanity);
}

// Function to print the house's status
void print_house(struct House *house) {
  printf("Name: %s\n", house->name);
  printf("Number of rooms: %d\n", house->num_rooms);
  for (int i = 0; i < house->num_rooms; i++) {
    printf("Room %d:\n", i + 1);
    printf("  Name: %s\n", house->rooms[i].name);
    printf("  Danger level: %d\n", house->rooms[i].danger_level);
    printf("  Sanity loss: %d\n", house->rooms[i].sanity_loss);
  }
}

// Function to simulate the character exploring the house
void explore_house(struct Character *character, struct House *house) {
  // Loop through each room in the house
  for (int i = 0; i < house->num_rooms; i++) {
    // Print the room's name
    printf("You enter the %s.\n", house->rooms[i].name);

    // Check if the room is dangerous
    if (house->rooms[i].danger_level > character->bravery) {
      // The room is too dangerous! The character loses sanity.
      character->sanity -= house->rooms[i].sanity_loss;
      printf("The room is too dangerous! You lose %d sanity.\n", house->rooms[i].sanity_loss);
    } else {
      // The room is safe. The character gains bravery.
      character->bravery += house->rooms[i].danger_level;
      printf("The room is safe. You gain %d bravery.\n", house->rooms[i].danger_level);
    }

    // Check if the character has lost all of their sanity
    if (character->sanity <= 0) {
      // The character has lost all of their sanity! They have gone insane.
      printf("You have lost all of your sanity! You have gone insane.\n");
      break;
    }
  }
}

int main() {
  // Create a new character
  struct Character *character = create_character("John Doe", 25, 50, 100);

  // Create a new house
  struct House *house = create_house("Haunted Mansion", 5);

  // Create the rooms in the house
  house->rooms[0] = *create_room("Foyer", 1, 10);
  house->rooms[1] = *create_room("Living Room", 2, 20);
  house->rooms[2] = *create_room("Dining Room", 3, 30);
  house->rooms[3] = *create_room("Master Bedroom", 4, 40);
  house->rooms[4] = *create_room("Attic", 5, 50);

  // Print the character's status
  printf("Character:\n");
  print_character(character);

  // Print the house's status
  printf("House:\n");
  print_house(house);

  // Simulate the character exploring the house
  explore_house(character, house);

  // Print the character's status after exploring the house
  printf("Character after exploring the house:\n");
  print_character(character);

  return 0;
}