//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 10

typedef struct {
    char name[50];
    char room_number[10];
    int check_in_time;
    int check_out_time;
} Guest;

typedef struct {
    char name[20];
    int capacity;
    int current_occupancy;
} Room;

// Function to create a new guest
Guest* create_guest(char* name, int check_in_time) {
    Guest* g = (Guest*) malloc(sizeof(Guest));
    strcpy(g->name, name);
    g->check_in_time = check_in_time;
    return g;
}

// Function to create a new room
Room* create_room(char* name, int capacity) {
    Room* r = (Room*) malloc(sizeof(Room));
    strcpy(r->name, name);
    r->capacity = capacity;
    r->current_occupancy = 0;
    return r;
}

// Function to check if a room is available
int is_room_available(Room* r) {
    return r->current_occupancy < r->capacity;
}

// Function to check if a guest has checked out
int has_guest_checked_out(Guest* g) {
    return g->check_out_time != 0;
}

// Function to check if a guest is staying in a particular room
int is_guest_in_room(Guest* g, Room* r) {
    return strcmp(g->room_number, r->name) == 0;
}

// Function to assign a guest to a room
void assign_guest_to_room(Guest* g, Room* r) {
    strcpy(g->room_number, r->name);
    r->current_occupancy++;
}

// Function to print the list of guests and their room numbers
void print_guests(Guest* guests) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name != NULL) {
            printf("%d: %s (%s)\n", i + 1, guests[i].name, guests[i].room_number);
        }
    }
}

// Function to print the list of rooms and their current occupancy
void print_rooms(Room* rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].name != NULL) {
            printf("%d: %s (%d/%d)\n", i + 1, rooms[i].name, rooms[i].current_occupancy, rooms[i].capacity);
        }
    }
}

int main() {
    // Create some guests and rooms
    Guest* guests[MAX_GUESTS];
    Room* rooms[MAX_ROOMS];

    // Create guests
    guests[0] = create_guest("John Doe", 123456789);
    guests[1] = create_guest("Jane Doe", 987654321);
    guests[2] = create_guest("Bob Smith", 876543210);

    // Create rooms
    rooms[0] = create_room("Room 1", 5);
    rooms[1] = create_room("Room 2", 10);
    rooms[2] = create_room("Room 3", 15);

    // Assign guests to rooms
    assign_guest_to_room(guests[0], rooms[0]);
    assign_guest_to_room(guests[1], rooms[1]);
    assign_guest_to_room(guests[2], rooms[2]);

    // Print the list of guests and their room numbers
    print_guests(guests);

    // Print the list of rooms and their current occupancy
    print_rooms(rooms);

    // Check if a room is available
    if (is_room_available(rooms[0])) {
        printf("Room 1 is available.\n");
    } else {
        printf("Room 1 is not available.\n");
    }

    // Check if a guest has checked out
    if (has_guest_checked_out(guests[0])) {
        printf("Guest 1 has checked out.\n");
    } else {
        printf("Guest 1 has not checked out.\n");
    }

    // Check if a guest is staying in a particular room
    if (is_guest_in_room(guests[1], rooms[1])) {
        printf("Guest 2 is staying in Room 2.\n");
    } else {
        printf("Guest 2 is not staying in Room 2.\n");
    }

    return 0;
}