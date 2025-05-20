//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Light{
  int id;
  int state; // 0 for off, 1 for on
  struct Light *next;
} Light;

typedef struct Room{
  char name[50];
  Light *lights;
} Room;

Room* createRoom(char* name){
  Room *newRoom = (Room*) malloc(sizeof(Room));
  strcpy(newRoom->name, name);
  newRoom->lights = NULL;

  return newRoom;
}

void addLight(Room* room, int id){
  Light *newLight = (Light*) malloc(sizeof(Light));
  newLight->id = id;
  newLight->state = 0;
  newLight->next = NULL;

  if (room->lights == NULL){
    room->lights = newLight;
  } else {
    Light *currentLight = room->lights;
    while (currentLight->next != NULL){
      currentLight = currentLight->next;
    }
    currentLight->next = newLight;
  }
}

Light* getLight(Room* room, int id){
  Light *currentLight = room->lights;
  while (currentLight != NULL){
    if (currentLight->id == id){
      return currentLight;
    }
    currentLight = currentLight->next;
  }
  return NULL;
}

void toggleLight(Room* room, int id){
  Light *light = getLight(room, id);
  if (light != NULL){
    light->state = !light->state;
    printf("Light %d in %s now %s\n", light->id, room->name, light->state? "on" : "off");
  }
}

void printStatus(Room* room){
  printf("Status of %s:\n", room->name);
  Light *currentLight = room->lights;
  while (currentLight != NULL){
    printf("Light %d is %s\n", currentLight->id, currentLight->state? "on" : "off");
    currentLight = currentLight->next;
  }
  printf("\n");
}

int main(){
  Room *livingRoom = createRoom("Living Room");
  addLight(livingRoom, 1);
  addLight(livingRoom, 2);

  Room *bedroom = createRoom("Bedroom");
  addLight(bedroom, 1);
  addLight(bedroom, 2);
  addLight(bedroom, 3);

  toggleLight(livingRoom, 1);
  toggleLight(livingRoom, 2);
  toggleLight(livingRoom, 3);

  toggleLight(bedroom, 1);
  toggleLight(bedroom, 2);
  toggleLight(bedroom, 3);

  printStatus(livingRoom);
  printStatus(bedroom);

  return 0;
}