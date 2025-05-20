//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Room {
    char* name;
    char* description;
    int floor;
    int door_count;
    int ghost_count;
    int exit_count;
} Room;

typedef struct Building {
    char* name;
    Room** rooms;
    int num_of_rooms;
    int num_of_floors;
} Building;

void print_building(Building* building) {
    printf("Building Name: %s\n", building->name);
    printf("Number of Floors: %d\n", building->num_of_floors);
    printf("Number of Rooms: %d\n", building->num_of_rooms);
    printf("\n");
}

void print_room(Room* room) {
    printf("Name: %s\n", room->name);
    printf("Description: %s\n", room->description);
    printf("Floor: %d\n", room->floor);
    printf("Door Count: %d\n", room->door_count);
    printf("Ghost Count: %d\n", room->ghost_count);
    printf("Exit Count: %d\n", room->exit_count);
    printf("\n");
}

int main() {
    // Create a building
    Building* building = malloc(sizeof(Building));
    building->name = "The Haunted House";
    building->num_of_rooms = 10;
    building->num_of_floors = 3;
    building->rooms = malloc(sizeof(Room*) * building->num_of_rooms);

    // Populate the building with rooms
    for (int i = 0; i < building->num_of_rooms; i++) {
        Room* room = malloc(sizeof(Room));
        room->name = malloc(sizeof(char) * 50);
        room->description = malloc(sizeof(char) * 500);
        room->floor = rand() % 10 + 1;
        room->door_count = rand() % 4 + 1;
        room->ghost_count = rand() % 4 + 1;
        room->exit_count = rand() % 3 + 1;
        sprintf(room->name, "Room %d", i + 1);
        sprintf(room->description, "This is a room %d", i + 1);
        building->rooms[i] = room;
    }

    // Print the building
    print_building(building);

    // Print a random room
    int random_room = rand() % building->num_of_rooms;
    print_room(building->rooms[random_room]);

    // Free allocated memory
    for (int i = 0; i < building->num_of_rooms; i++) {
        free(building->rooms[i]->name);
        free(building->rooms[i]->description);
    }
    free(building->rooms);
    free(building->name);
    free(building);

    return 0;
}