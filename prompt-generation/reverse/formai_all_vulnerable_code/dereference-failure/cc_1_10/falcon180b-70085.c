//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROOM_COUNT 10
#define MAX_ITEMS 100
#define MAX_ROOMS 10
#define MAX_ITEMS_PER_ROOM 10
#define MAX_ITEMS_PER_ROOM_COUNT 10

typedef struct {
    char *name;
    int value;
} Item;

typedef struct {
    char *name;
    int value;
    int is_scary;
} Room;

int main() {
    srand(time(NULL));

    Room rooms[ROOM_COUNT] = {
        {"Foyer", 0, 0},
        {"Living Room", 1, 0},
        {"Dining Room", 2, 0},
        {"Kitchen", 3, 0},
        {"Library", 4, 1},
        {"Study", 5, 1},
        {"Bedroom", 6, 1},
        {"Bathroom", 7, 0},
        {"Attic", 8, 2},
        {"Basement", 9, 2}
    };

    Item items[MAX_ITEMS] = {
        {"Candle", 1},
        {"Book", 2},
        {"Knife", 3},
        {"Painting", 4},
        {"Mirror", 5},
        {"Ghost", 6},
        {"Spider", 7},
        {"Bat", 8},
        {"Skeleton", 9},
        {"Witch", 10}
    };

    int item_counts[MAX_ITEMS_PER_ROOM_COUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int room_count = 0;
    int item_count = 0;

    for (int i = 0; i < ROOM_COUNT; i++) {
        printf("You enter the %s.\n", rooms[i].name);

        for (int j = 0; j < item_counts[item_count]; j++) {
            int index = rand() % MAX_ITEMS;
            printf("You see a %s.\n", items[index].name);

            if (iscntrl(items[index].name[0])) {
                printf("The %s is haunted!\n", items[index].name);
            }
        }

        item_count++;
        room_count++;

        if (room_count == MAX_ITEMS_PER_ROOM_COUNT) {
            printf("\n");
            room_count = 0;
        }
    }

    return 0;
}