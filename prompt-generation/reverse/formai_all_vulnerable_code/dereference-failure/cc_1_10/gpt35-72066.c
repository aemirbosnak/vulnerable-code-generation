//FormAI DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct Room {
  char* roomName;
  int numOfLights;
  int* lightStatus;
  int numOfWindows;
  int* windowStatus;
  int numOfDoors;
  int* doorStatus;
} Room;

int getRoomIndex(Room* rooms, int numOfRooms, char* roomName) {
  int i;
  for (i = 0; i < numOfRooms; i++) {
    if (strcmp(rooms[i].roomName, roomName) == 0) {
      return i;
    }
  }
  return -1;
}

void printStatus(Room* rooms, int roomIndex) {
  printf("\nRoom Name: %s\n", rooms[roomIndex].roomName);
  printf("Number of Lights: %d\n", rooms[roomIndex].numOfLights);
  printf("Light Status: ");
  int i;
  for (i = 0; i < rooms[roomIndex].numOfLights; i++) {
    printf("%d ", rooms[roomIndex].lightStatus[i]);
  }
  printf("\nNumber of Windows: %d\n", rooms[roomIndex].numOfWindows);
  printf("Window Status: ");
  for (i = 0; i < rooms[roomIndex].numOfWindows; i++) {
    printf("%d ", rooms[roomIndex].windowStatus[i]);
  }
  printf("\nNumber of Doors: %d\n", rooms[roomIndex].numOfDoors);
  printf("Door Status: ");
  for (i = 0; i < rooms[roomIndex].numOfDoors; i++) {
    printf("%d ", rooms[roomIndex].doorStatus[i]);
  }
  printf("\n\n");
}

int main() {
  int numOfRooms = 2;
  Room* rooms = malloc(numOfRooms * sizeof(Room));

  // Room 1 - Bedroom
  rooms[0].roomName = "Bedroom";
  rooms[0].numOfLights = 2;
  rooms[0].lightStatus = calloc(rooms[0].numOfLights, sizeof(int));
  rooms[0].numOfWindows = 1;
  rooms[0].windowStatus = calloc(rooms[0].numOfWindows, sizeof(int));
  rooms[0].numOfDoors = 1;
  rooms[0].doorStatus = calloc(rooms[0].numOfDoors, sizeof(int));

  // Room 2 - Living Room
  rooms[1].roomName = "Living Room";
  rooms[1].numOfLights = 3;
  rooms[1].lightStatus = calloc(rooms[1].numOfLights, sizeof(int));
  rooms[1].numOfWindows = 2;
  rooms[1].windowStatus = calloc(rooms[1].numOfWindows, sizeof(int));
  rooms[1].numOfDoors = 2;
  rooms[1].doorStatus = calloc(rooms[1].numOfDoors, sizeof(int));

  printStatus(rooms, 0); // Bedroom status
  printStatus(rooms, 1); // Living Room status

  // Turning on the lights in both rooms
  int i;
  for (i = 0; i < rooms[0].numOfLights; i++) {
    rooms[0].lightStatus[i] = 1;
  }
  for (i = 0; i < rooms[1].numOfLights; i++) {
    rooms[1].lightStatus[i] = 1;
  }

  // Opening the windows in the bedroom
  rooms[0].windowStatus[0] = 1;

  // Locking the doors in the living room
  rooms[1].doorStatus[0] = 1;
  rooms[1].doorStatus[1] = 1;

  printStatus(rooms, getRoomIndex(rooms, numOfRooms, "Bedroom"));
  printStatus(rooms, getRoomIndex(rooms, numOfRooms, "Living Room"));

  free(rooms);
  return 0;
}