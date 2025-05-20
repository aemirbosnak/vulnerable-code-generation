//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int room_number;
    char *room_type;
    int is_occupied;
    char *guest_name;
    char *guest_phone;
    char *guest_email;
} room;

typedef struct {
    int number_of_rooms;
    room *rooms;
} hotel;

// Function to create a new hotel
hotel *create_hotel(int number_of_rooms) {
    hotel *new_hotel = (hotel *)malloc(sizeof(hotel));
    new_hotel->number_of_rooms = number_of_rooms;
    new_hotel->rooms = (room *)malloc(sizeof(room) * number_of_rooms);
    return new_hotel;
}

// Function to free the memory allocated for a hotel
void destroy_hotel(hotel *hotel) {
    free(hotel->rooms);
    free(hotel);
}

// Function to add a new room to a hotel
void add_room(hotel *hotel, int room_number, char *room_type) {
    room new_room = {room_number, room_type, 0, NULL, NULL, NULL};
    hotel->rooms[room_number - 1] = new_room;
}

// Function to check in a guest
void check_in_guest(hotel *hotel, int room_number, char *guest_name, char *guest_phone, char *guest_email) {
    room *room = &hotel->rooms[room_number - 1];
    room->is_occupied = 1;
    room->guest_name = guest_name;
    room->guest_phone = guest_phone;
    room->guest_email = guest_email;
}

// Function to check out a guest
void check_out_guest(hotel *hotel, int room_number) {
    room *room = &hotel->rooms[room_number - 1];
    room->is_occupied = 0;
    room->guest_name = NULL;
    room->guest_phone = NULL;
    room->guest_email = NULL;
}

// Function to print the hotel information
void print_hotel_info(hotel *hotel) {
    for (int i = 0; i < hotel->number_of_rooms; i++) {
        room *room = &hotel->rooms[i];
        printf("Room %d: %s\n", room->room_number, room->room_type);
        if (room->is_occupied) {
            printf("Occupied by: %s\n", room->guest_name);
            printf("Phone: %s\n", room->guest_phone);
            printf("Email: %s\n", room->guest_email);
        } else {
            printf("Unoccupied\n");
        }
        printf("\n");
    }
}

int main() {
    // Create a new hotel with 10 rooms
    hotel *hotel = create_hotel(10);

    // Add rooms to the hotel
    add_room(hotel, 1, "Standard");
    add_room(hotel, 2, "Standard");
    add_room(hotel, 3, "Standard");
    add_room(hotel, 4, "Deluxe");
    add_room(hotel, 5, "Deluxe");
    add_room(hotel, 6, "Suite");
    add_room(hotel, 7, "Suite");
    add_room(hotel, 8, "Suite");
    add_room(hotel, 9, "Presidential");
    add_room(hotel, 10, "Presidential");

    // Check in some guests
    check_in_guest(hotel, 1, "John Smith", "+1 555-123-4567", "john.smith@example.com");
    check_in_guest(hotel, 2, "Jane Doe", "+1 555-234-5678", "jane.doe@example.com");
    check_in_guest(hotel, 4, "Jack Jones", "+1 555-345-6789", "jack.jones@example.com");
    check_in_guest(hotel, 6, "Jill Roberts", "+1 555-456-7890", "jill.roberts@example.com");

    // Print the hotel information
    print_hotel_info(hotel);

    // Check out some guests
    check_out_guest(hotel, 2);
    check_out_guest(hotel, 4);

    // Print the hotel information again
    print_hotel_info(hotel);

    // Destroy the hotel
    destroy_hotel(hotel);

    return 0;
}