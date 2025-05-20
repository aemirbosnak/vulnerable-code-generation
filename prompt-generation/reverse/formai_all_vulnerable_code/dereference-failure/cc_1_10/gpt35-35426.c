//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare a struct for the lights
typedef struct {
    char* name;
    bool state;
} Light;

// Declare a struct for the rooms
typedef struct {
    char* name;
    Light* lights;
    int numLights;
} Room;

// Declare a struct for the house
typedef struct {
    char* name;
    Room* rooms;
    int numRooms;
} House;

// Declare functions
void turnAllLightsOff(House* house);
void turnAllLightsOn(House* house);
void toggleLight(Room* room, int lightIndex);
void printHouseState(House* house);

int main() {
    // Create a new house
    House myHouse;
    myHouse.name = "My House";
    myHouse.numRooms = 2;
    myHouse.rooms = (Room*) malloc(myHouse.numRooms * sizeof(Room));
    
    // Create the first room
    Room livingRoom;
    livingRoom.name = "Living Room";
    livingRoom.numLights = 2;
    livingRoom.lights = (Light*) malloc(livingRoom.numLights * sizeof(Light));
    
    // Set the living room lights
    Light livingRoomLight1;
    livingRoomLight1.name = "Ceiling Light";
    livingRoomLight1.state = false;
    
    Light livingRoomLight2;
    livingRoomLight2.name = "Table Lamp";
    livingRoomLight2.state = true;
    
    livingRoom.lights[0] = livingRoomLight1;
    livingRoom.lights[1] = livingRoomLight2;
    
    // Add the living room to the house
    myHouse.rooms[0] = livingRoom;
    
    // Create the second room
    Room bedroom;
    bedroom.name = "Bedroom";
    bedroom.numLights = 1;
    bedroom.lights = (Light*) malloc(bedroom.numLights * sizeof(Light));
    
    // Set the bedroom lights
    Light bedroomLight1;
    bedroomLight1.name = "Bedside Lamp";
    bedroomLight1.state = true;
    
    bedroom.lights[0] = bedroomLight1;
    
    // Add the bedroom to the house
    myHouse.rooms[1] = bedroom;
    
    // Print the state of the house
    printHouseState(&myHouse);
    
    // Toggle the living room table lamp
    toggleLight(&myHouse.rooms[0], 1);
    
    // Turn on all lights in the house
    turnAllLightsOn(&myHouse);
    
    // Print the state of the house
    printHouseState(&myHouse);
    
    // Turn off all lights in the house
    turnAllLightsOff(&myHouse);
    
    // Print the state of the house
    printHouseState(&myHouse);
    
    // Free memory
    free(livingRoom.lights);
    free(bedroom.lights);
    free(myHouse.rooms);
    
    return 0;
}

// Function definitions
void turnAllLightsOff(House* house) {
    for (int i = 0; i < house->numRooms; i++) {
        for (int j = 0; j < house->rooms[i].numLights; j++) {
            house->rooms[i].lights[j].state = false;
        }
    }
}

void turnAllLightsOn(House* house) {
    for (int i = 0; i < house->numRooms; i++) {
        for (int j = 0; j < house->rooms[i].numLights; j++) {
            house->rooms[i].lights[j].state = true;
        }
    }
}

void toggleLight(Room* room, int lightIndex) {
    room->lights[lightIndex].state = !(room->lights[lightIndex].state);
}

void printHouseState(House* house) {
    printf("House: %s\n", house->name);
    for (int i = 0; i < house->numRooms; i++) {
        printf("Room: %s\n", house->rooms[i].name);
        for (int j = 0; j < house->rooms[i].numLights; j++) {
            printf("Light: %s - State: %s\n", house->rooms[i].lights[j].name, house->rooms[i].lights[j].state ? "On" : "Off");
        }
    }
    printf("\n");
}