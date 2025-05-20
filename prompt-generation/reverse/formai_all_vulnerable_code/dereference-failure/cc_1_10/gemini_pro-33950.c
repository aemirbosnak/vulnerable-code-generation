//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rooms in the house
#define NUM_ROOMS 10

// Define the maximum number of items in a room
#define MAX_ITEMS 5

// Define the maximum length of a room name
#define MAX_ROOM_NAME_LENGTH 20

// Define the maximum length of an item name
#define MAX_ITEM_NAME_LENGTH 20

// Define the structure of a room
typedef struct {
    char name[MAX_ROOM_NAME_LENGTH];
    char description[256];
    int num_items;
    char items[MAX_ITEMS][MAX_ITEM_NAME_LENGTH];
} room;

// Define the structure of the house
typedef struct {
    room rooms[NUM_ROOMS];
} house;

// Create a new house
house* create_house() {
    house* h = malloc(sizeof(house));
    for (int i = 0; i < NUM_ROOMS; i++) {
        sprintf(h->rooms[i].name, "Room %d", i + 1);
        sprintf(h->rooms[i].description, "This is room %d.", i + 1);
        h->rooms[i].num_items = 0;
        for (int j = 0; j < MAX_ITEMS; j++) {
            h->rooms[i].items[j][0] = '\0';
        }
    }
    return h;
}

// Add an item to a room
void add_item_to_room(house* h, int room_index, char* item_name) {
    if (h->rooms[room_index].num_items < MAX_ITEMS) {
        strcpy(h->rooms[room_index].items[h->rooms[room_index].num_items], item_name);
        h->rooms[room_index].num_items++;
    }
}

// Remove an item from a room
void remove_item_from_room(house* h, int room_index, char* item_name) {
    for (int i = 0; i < h->rooms[room_index].num_items; i++) {
        if (strcmp(h->rooms[room_index].items[i], item_name) == 0) {
            for (int j = i; j < h->rooms[room_index].num_items - 1; j++) {
                strcpy(h->rooms[room_index].items[j], h->rooms[room_index].items[j + 1]);
            }
            h->rooms[room_index].num_items--;
            break;
        }
    }
}

// Print the house
void print_house(house* h) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d:\n", i + 1);
        printf("  %s\n", h->rooms[i].description);
        printf("  Items:\n");
        for (int j = 0; j < h->rooms[i].num_items; j++) {
            printf("    %s\n", h->rooms[i].items[j]);
        }
    }
}

// Free the memory allocated for the house
void free_house(house* h) {
    free(h);
}

// Main function
int main() {
    // Create a new house
    house* h = create_house();

    // Add some items to the house
    add_item_to_room(h, 0, "A dusty old book");
    add_item_to_room(h, 1, "A broken mirror");
    add_item_to_room(h, 2, "A rocking chair");
    add_item_to_room(h, 3, "A grandfather clock");
    add_item_to_room(h, 4, "A suit of armor");
    add_item_to_room(h, 5, "A painting of a beautiful woman");
    add_item_to_room(h, 6, "A fireplace");
    add_item_to_room(h, 7, "A grandfather clock");
    add_item_to_room(h, 8, "A suit of armor");
    add_item_to_room(h, 9, "A painting of a beautiful woman");

    // Print the house
    print_house(h);

    // Free the memory allocated for the house
    free_house(h);

    return 0;
}