//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Room struct
struct Room {
    int id;
    char description[100];
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
    int visited;
    int ghost_present;
};

void generate_rooms(struct Room *rooms) {
    // Room descriptions
    char *descriptions[5] = {
        "You find yourself in a dimly lit room, the air is cold and stagnant.",
        "You enter a room with an old piano in the corner, covered with dust.",
        "You come across a room with a large fireplace, cold and empty.",
        "You enter a room with old portraits on the walls, staring at you from every angle.",
        "Finally, you come across a room with a large wooden table in the center."};

    // Starting room
    struct Room *current_room = &rooms[0];
    current_room->visited = 1;

    // Generate routes between rooms
    for (int i = 0; i < 5; i++) {
        struct Room *room = &rooms[i];
        room->id = i;
        room->ghost_present = rand() % 2; // 50% chance of a ghost

        // Set room description
        int index = rand() % 5;
        sprintf(room->description, "%s", descriptions[index]);

        // Set room directions
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                if (i != 0) {
                    room->north = &rooms[i-1];
                } else {
                    room->north = &rooms[i+1];
                }
                break;
            case 1:
                if (i != 4) {
                    room->south = &rooms[i+1];
                } else {
                    room->south = &rooms[i-1];
                }
                break;
            case 2:
                if (i != 0) {
                    room->west = &rooms[i-1];
                } else {
                    room->west = &rooms[i+1];
                }
                break;
            case 3:
                if (i != 4) {
                    room->east = &rooms[i+1];
                } else {
                    room->east = &rooms[i-1];
                }
                break;
        }
    }
}

void print_room(struct Room *room) {
    printf("Room %d\n", room->id);
    printf("%s\n", room->description);
    if (room->ghost_present) {
        printf("There is a ghost in the room!\n");
    }
}

int main() {
    srand(time(NULL));

    // Allocate memory for rooms
    struct Room *rooms = malloc(sizeof(struct Room) * 5);

    // Generate rooms
    generate_rooms(rooms);

    // Game loop
    while (1) {
        struct Room *current_room = &rooms[rand() % 5];
        if (!current_room->visited) {
            current_room->visited = 1;
            print_room(current_room);
        }
    }

    return 0;
}