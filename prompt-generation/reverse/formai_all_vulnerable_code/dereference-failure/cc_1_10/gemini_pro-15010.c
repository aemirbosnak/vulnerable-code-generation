//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define MAX_ITEMS 5

typedef struct {
    char *name;
    char *description;
    int num_items;
    char *items[MAX_ITEMS];
} Room;

typedef struct {
    char *name;
    char *description;
    int num_rooms;
    Room *rooms[NUM_ROOMS];
} House;

House *create_house() {
    House *house = malloc(sizeof(House));
    house->name = "Cyberpunk Mansion";
    house->description = "A sprawling mansion in the heart of Night City, filled with neon lights and dark secrets.";
    house->num_rooms = NUM_ROOMS;

    for (int i = 0; i < NUM_ROOMS; i++) {
        Room *room = malloc(sizeof(Room));
        room->name = (char *)malloc(10);
        sprintf(room->name, "Room %d", i);
        room->description = (char *)malloc(50);
        sprintf(room->description, "A dimly lit room with a single window.");
        room->num_items = rand() % MAX_ITEMS;

        for (int j = 0; j < room->num_items; j++) {
            room->items[j] = (char *)malloc(10);
            sprintf(room->items[j], "Item %d", j);
        }

        house->rooms[i] = room;
    }

    return house;
}

void print_house(House *house) {
    printf("Welcome to %s!\n", house->name);
    printf("%s\n", house->description);
    printf("Rooms:\n");
    for (int i = 0; i < house->num_rooms; i++) {
        printf("  %s\n", house->rooms[i]->name);
        printf("    %s\n", house->rooms[i]->description);
        printf("    Items:\n");
        for (int j = 0; j < house->rooms[i]->num_items; j++) {
            printf("      %s\n", house->rooms[i]->items[j]);
        }
    }
}

int main() {
    srand(time(NULL));
    House *house = create_house();
    print_house(house);
    return 0;
}