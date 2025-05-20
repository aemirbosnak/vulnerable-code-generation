//FormAI DATASET v1.0 Category: Smart home light control ; Style: ephemeral
// Smart Home Light Control Program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_OF_ROOMS 3

// Struct to represent a room in the house
typedef struct Room {
    char *name;
    bool lightsOn;
} Room;

// Function to get user input for the room name
char* getRoomName() {
    char *name = (char*)malloc(sizeof(char) * 20);
    printf("Enter name of room: ");
    scanf("%s", name);
    printf("\n");
    return name;
}

// Function to turn on the lights in a room
void turnOnLights(Room *room) {
    room->lightsOn = true;
    printf("Turned on lights in %s\n", room->name);
}

// Function to turn off the lights in a room
void turnOffLights(Room *room) {
    room->lightsOn = false;
    printf("Turned off lights in %s\n", room->name);
}

// Function to find a room by name in the list of rooms
Room* findRoomByName(Room *rooms, char *name) {
    for(int i = 0; i < NUM_OF_ROOMS; i++) {
        if(strcmp(rooms[i].name, name) == 0) {
            return &rooms[i];
        }
    }
    return NULL;
}

// Main function
int main() {
    Room rooms[NUM_OF_ROOMS] = {
        { "living room", false },
        { "bedroom", false },
        { "kitchen", false }
    };

    char *roomName;
    int choice;

    while(true) {
        printf("Menu:\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                roomName = getRoomName();
                Room *roomToTurnOn = findRoomByName(rooms, roomName);
                if(roomToTurnOn != NULL) {
                    turnOnLights(roomToTurnOn);
                } else {
                    printf("Could not find room with name %s\n", roomName);
                }
                break;
            case 2:
                roomName = getRoomName();
                Room *roomToTurnOff = findRoomByName(rooms, roomName);
                if(roomToTurnOff != NULL) {
                    turnOffLights(roomToTurnOff);
                } else {
                    printf("Could not find room with name %s\n", roomName);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}