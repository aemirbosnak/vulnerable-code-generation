//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct Room {
    char name[20];
    int width;
    int height;
    int num_doors;
    int num_windows;
    int num_ghosts;
    int num_traps;
} Room;

typedef struct House {
    char name[20];
    int num_rooms;
    Room **rooms;
} House;

void add_room(House *house, char *room_name, int width, int height, int num_doors, int num_windows, int num_ghosts, int num_traps) {
    Room *new_room = malloc(sizeof(Room));
    strcpy(new_room->name, room_name);
    new_room->width = width;
    new_room->height = height;
    new_room->num_doors = num_doors;
    new_room->num_windows = num_windows;
    new_room->num_ghosts = num_ghosts;
    new_room->num_traps = num_traps;

    int room_index = house->num_rooms;
    house->rooms = realloc(house->rooms, (room_index + 1) * sizeof(Room *));
    house->rooms[room_index] = new_room;

    house->num_rooms++;
}

void display_house(House *house) {
    printf("House Name: %s\n", house->name);
    printf("Number of Rooms: %d\n", house->num_rooms);
    for (int i = 0; i < house->num_rooms; i++) {
        printf("Room %d:\n", i + 1);
        printf("Name: %s\n", house->rooms[i]->name);
        printf("Width: %d\n", house->rooms[i]->width);
        printf("Height: %d\n", house->rooms[i]->height);
        printf("Number of Doors: %d\n", house->rooms[i]->num_doors);
        printf("Number of Windows: %d\n", house->rooms[i]->num_windows);
        printf("Number of Ghosts: %d\n", house->rooms[i]->num_ghosts);
        printf("Number of Traps: %d\n", house->rooms[i]->num_traps);
        printf("\n");
    }
}

int main() {
    House *house = malloc(sizeof(House));
    strcpy(house->name, "Haunted House");

    add_room(house, "Foyer", 10, 10, 1, 1, 0, 0);
    add_room(house, "Kitchen", 10, 10, 0, 1, 1, 1);
    add_room(house, "Living Room", 20, 20, 1, 0, 0, 1);
    add_room(house, "Bedroom", 10, 10, 0, 1, 1, 0);
    add_room(house, "Bathroom", 5, 5, 0, 1, 0, 0);

    display_house(house);

    free(house);

    return 0;
}