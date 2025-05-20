//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10
#define MAX_SOUNDS 5
#define MAX_ITEMS 3

typedef struct Ghost {
  char name[20];
  int sound_index;
  int item_index;
  struct Ghost* next;
} Ghost;

typedef struct Sound {
  char name[20];
  int duration;
  struct Sound* next;
} Sound;

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

Ghost* createGhost(char* name, int sound_index, int item_index) {
  Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->sound_index = sound_index;
  ghost->item_index = item_index;
  ghost->next = NULL;
  return ghost;
}

Sound* createSound(char* name, int duration) {
  Sound* sound = (Sound*)malloc(sizeof(Sound));
  strcpy(sound->name, name);
  sound->duration = duration;
  sound->next = NULL;
  return sound;
}

Item* createItem(char* name, int quantity) {
  Item* item = (Item*)malloc(sizeof(Item));
  strcpy(item->name, name);
  item->quantity = quantity;
  item->next = NULL;
  return item;
}

void simulateHauntedHouse() {
  // Create a list of ghosts, sounds, and items
  Ghost* ghosts = createGhost("Mr. Jones", 2, 1);
  Sound* sounds = createSound("Screaming", 5);
  Item* items = createItem("Bloody Knife", 3);

  // Simulate the haunted house
  srand(time(NULL));
  for (int i = 0; i < MAX_GHOULS; i++) {
    int sound_index = rand() % MAX_SOUNDS;
    int item_index = rand() % MAX_ITEMS;
    ghosts->next = createGhost("Mrs. Smith", sound_index, item_index);
    ghosts = ghosts->next;
  }

  for (int i = 0; i < MAX_SOUNDS; i++) {
    sounds->next = createSound("Whispering", rand() % 3);
    sounds = sounds->next;
  }

  for (int i = 0; i < MAX_ITEMS; i++) {
    items->next = createItem("Broken Sword", rand() % 5);
    items = items->next;
  }

  // Interact with the ghosts, sounds, and items
  // ...
}

int main() {
  simulateHauntedHouse();
  return 0;
}