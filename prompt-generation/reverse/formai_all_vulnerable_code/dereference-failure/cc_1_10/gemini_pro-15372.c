//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rooms in the house
#define NUM_ROOMS 10

// Define the maximum number of items in a room
#define MAX_ITEMS 5

// Define the maximum length of a string
#define MAX_STRING_LENGTH 20

// Define the structure of a room
typedef struct room {
    char name[MAX_STRING_LENGTH];
    char description[MAX_STRING_LENGTH];
    int num_items;
    char items[MAX_ITEMS][MAX_STRING_LENGTH];
} room;

// Define the structure of the house
typedef struct house {
    room rooms[NUM_ROOMS];
} house;

// Create a new house
house* create_house() {
    house* h = malloc(sizeof(house));
    
    // Initialize the rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        sprintf(h->rooms[i].name, "Room %d", i + 1);
        sprintf(h->rooms[i].description, "This is room %d.", i + 1);
        h->rooms[i].num_items = 0;
    }
    
    return h;
}

// Destroy the house
void destroy_house(house* h) {
    free(h);
}

// Add an item to a room
void add_item(house* h, int room_index, char* item) {
    if (room_index < 0 || room_index >= NUM_ROOMS) {
        printf("Invalid room index.\n");
        return;
    }
    
    if (h->rooms[room_index].num_items >= MAX_ITEMS) {
        printf("Room is full.\n");
        return;
    }
    
    strcpy(h->rooms[room_index].items[h->rooms[room_index].num_items], item);
    h->rooms[room_index].num_items++;
}

// Remove an item from a room
void remove_item(house* h, int room_index, char* item) {
    if (room_index < 0 || room_index >= NUM_ROOMS) {
        printf("Invalid room index.\n");
        return;
    }
    
    for (int i = 0; i < h->rooms[room_index].num_items; i++) {
        if (strcmp(h->rooms[room_index].items[i], item) == 0) {
            h->rooms[room_index].num_items--;
            for (int j = i; j < h->rooms[room_index].num_items; j++) {
                strcpy(h->rooms[room_index].items[j], h->rooms[room_index].items[j + 1]);
            }
            return;
        }
    }
    
    printf("Item not found.\n");
}

// Print the house
void print_house(house* h) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d: %s\n", i + 1, h->rooms[i].name);
        printf("Description: %s\n", h->rooms[i].description);
        printf("Items: ");
        for (int j = 0; j < h->rooms[i].num_items; j++) {
            printf("%s ", h->rooms[i].items[j]);
        }
        printf("\n\n");
    }
}

// Main function
int main() {
    // Create a new house
    house* h = create_house();
    
    // Add some items to the house
    add_item(h, 0, "bed");
    add_item(h, 0, "dresser");
    add_item(h, 1, "table");
    add_item(h, 1, "chairs");
    add_item(h, 2, "couch");
    add_item(h, 2, "tv");
    
    // Print the house
    print_house(h);
    
    // Destroy the house
    destroy_house(h);
    
    return 0;
}