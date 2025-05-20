//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define MAX_ITEMS 5

typedef struct room {
    char *description;
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
    int num_items;
    char *items[MAX_ITEMS];
} room;

room *create_room(char *description) {
    room *new_room = malloc(sizeof(room));
    new_room->description = description;
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    new_room->num_items = 0;
    return new_room;
}

void add_item(room *room, char *item) {
    room->items[room->num_items] = item;
    room->num_items++;
}

void connect_rooms(room *room1, room *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            room2->south = room1;
            break;
        case 's':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'e':
            room1->east = room2;
            room2->west = room1;
            break;
        case 'w':
            room1->west = room2;
            room2->east = room1;
            break;
    }
}

void print_room(room *room) {
    printf("%s\n", room->description);
    if (room->num_items > 0) {
        printf("Items: ");
        for (int i = 0; i < room->num_items; i++) {
            printf("%s ", room->items[i]);
        }
        printf("\n");
    }
}

void play_game(room *start_room) {
    room *current_room = start_room;

    while (1) {
        print_room(current_room);

        printf("Which direction would you like to go? (n/s/e/w) ");
        char direction;
        scanf(" %c", &direction);

        switch (direction) {
            case 'n':
                if (current_room->north) {
                    current_room = current_room->north;
                } else {
                    printf("There is no door in that direction.\n");
                }
                break;
            case 's':
                if (current_room->south) {
                    current_room = current_room->south;
                } else {
                    printf("There is no door in that direction.\n");
                }
                break;
            case 'e':
                if (current_room->east) {
                    current_room = current_room->east;
                } else {
                    printf("There is no door in that direction.\n");
                }
                break;
            case 'w':
                if (current_room->west) {
                    current_room = current_room->west;
                } else {
                    printf("There is no door in that direction.\n");
                }
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
        }
    }
}

int main() {
    srand(time(NULL));

    room *kitchen = create_room("You are in the kitchen. The floor is covered in broken dishes and the walls are stained with blood.");
    room *living_room = create_room("You are in the living room. The furniture is overturned and the windows are boarded up.");
    room *dining_room = create_room("You are in the dining room. The table is set for a feast, but the food is rotten and crawling with maggots.");
    room *master_bedroom = create_room("You are in the master bedroom. The bed is unmade and the sheets are stained with something dark.");
    room *guest_bedroom = create_room("You are in the guest bedroom. The bed is empty and the closet is bare.");

    add_item(kitchen, "knife");
    add_item(kitchen, "axe");
    add_item(living_room, "baseball bat");
    add_item(living_room, "shotgun");
    add_item(dining_room, "candlesticks");
    add_item(dining_room, "poison");
    add_item(master_bedroom, "rope");
    add_item(master_bedroom, "chains");
    add_item(guest_bedroom, "teddy bear");
    add_item(guest_bedroom, "doll");

    connect_rooms(kitchen, living_room, 'n');
    connect_rooms(kitchen, dining_room, 'e');
    connect_rooms(living_room, master_bedroom, 'n');
    connect_rooms(living_room, guest_bedroom, 'w');
    connect_rooms(dining_room, kitchen, 'w');
    connect_rooms(dining_room, master_bedroom, 'e');
    connect_rooms(master_bedroom, living_room, 's');
    connect_rooms(master_bedroom, dining_room, 'w');
    connect_rooms(guest_bedroom, living_room, 'e');

    play_game(kitchen);

    return 0;
}