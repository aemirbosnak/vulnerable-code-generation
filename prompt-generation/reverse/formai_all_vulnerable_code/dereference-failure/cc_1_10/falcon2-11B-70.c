//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a hotel room
struct hotel_room {
    int room_number;
    char room_type[10];
    int price_per_night;
    int occupied;
};

// Define a function to create a new hotel room
struct hotel_room* create_room(int room_number, char room_type[10], int price_per_night) {
    struct hotel_room* new_room = (struct hotel_room*) malloc(sizeof(struct hotel_room));
    strcpy(new_room->room_type, room_type);
    new_room->price_per_night = price_per_night;
    new_room->occupied = 0;
    new_room->room_number = room_number;
    return new_room;
}

// Define a function to display a hotel room
void display_room(struct hotel_room* room) {
    printf("Room %d is a %s room, and costs $%.2f per night.\n", room->room_number, room->room_type, room->price_per_night);
}

// Define a function to check if a hotel room is occupied
int is_room_occupied(struct hotel_room* room) {
    return room->occupied;
}

// Define a function to book a hotel room
void book_room(struct hotel_room* room, int days) {
    room->occupied = 1;
    printf("Room %d is now occupied for %d days.\n", room->room_number, days);
}

// Define a function to check out a hotel room
void check_out_room(struct hotel_room* room) {
    room->occupied = 0;
    printf("Room %d is now available.\n", room->room_number);
}

int main() {
    // Create a new hotel room
    struct hotel_room* room1 = create_room(101, "Standard", 80);
    
    // Display the hotel room
    display_room(room1);
    
    // Check if the hotel room is occupied
    int is_occupied = is_room_occupied(room1);
    printf("Is room %d occupied? %s\n", room1->room_number, is_occupied? "Yes" : "No");
    
    // Book the hotel room for 3 days
    book_room(room1, 3);
    
    // Display the updated hotel room
    display_room(room1);
    
    // Check if the hotel room is occupied again
    is_occupied = is_room_occupied(room1);
    printf("Is room %d occupied? %s\n", room1->room_number, is_occupied? "Yes" : "No");
    
    // Check out the hotel room
    check_out_room(room1);
    
    // Display the updated hotel room
    display_room(room1);
    
    return 0;
}