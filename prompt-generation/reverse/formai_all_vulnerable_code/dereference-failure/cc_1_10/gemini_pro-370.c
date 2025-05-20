//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the structure of a room
typedef struct {
    int room_number;
    char room_type[20];
    int price;
    int availability;
} Room;

// Define the structure of a guest
typedef struct {
    char name[50];
    char address[100];
    char phone_number[20];
    int room_number;
    int check_in_date;
    int check_out_date;
} Guest;

// Define the structure of the hotel management system
typedef struct {
    Room rooms[MAX_ROOMS];
    Guest guests[MAX_ROOMS];
    int num_rooms;
    int num_guests;
} HotelManagementSystem;

// Create a new hotel management system
HotelManagementSystem* create_hotel_management_system() {
    HotelManagementSystem* hotel = malloc(sizeof(HotelManagementSystem));
    hotel->num_rooms = 0;
    hotel->num_guests = 0;
    return hotel;
}

// Add a new room to the hotel management system
void add_room(HotelManagementSystem* hotel, Room room) {
    hotel->rooms[hotel->num_rooms] = room;
    hotel->num_rooms++;
}

// Add a new guest to the hotel management system
void add_guest(HotelManagementSystem* hotel, Guest guest) {
    hotel->guests[hotel->num_guests] = guest;
    hotel->num_guests++;
}

// Find a room by room number
Room* find_room_by_room_number(HotelManagementSystem* hotel, int room_number) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (hotel->rooms[i].room_number == room_number) {
            return &hotel->rooms[i];
        }
    }
    return NULL;
}

// Find a guest by name
Guest* find_guest_by_name(HotelManagementSystem* hotel, char* name) {
    for (int i = 0; i < hotel->num_guests; i++) {
        if (strcmp(hotel->guests[i].name, name) == 0) {
            return &hotel->guests[i];
        }
    }
    return NULL;
}

// Check if a room is available
int is_room_available(HotelManagementSystem* hotel, int room_number) {
    Room* room = find_room_by_room_number(hotel, room_number);
    if (room == NULL) {
        return 0;
    }
    return room->availability;
}

// Check in a guest
void check_in_guest(HotelManagementSystem* hotel, Guest guest) {
    Room* room = find_room_by_room_number(hotel, guest.room_number);
    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }
    if (!is_room_available(hotel, guest.room_number)) {
        printf("Room is not available.\n");
        return;
    }
    room->availability = 0;
    add_guest(hotel, guest);
}

// Check out a guest
void check_out_guest(HotelManagementSystem* hotel, char* name) {
    Guest* guest = find_guest_by_name(hotel, name);
    if (guest == NULL) {
        printf("Guest not found.\n");
        return;
    }
    Room* room = find_room_by_room_number(hotel, guest->room_number);
    room->availability = 1;
    for (int i = 0; i < hotel->num_guests; i++) {
        if (strcmp(hotel->guests[i].name, name) == 0) {
            hotel->guests[i] = hotel->guests[hotel->num_guests - 1];
            hotel->num_guests--;
            break;
        }
    }
}

// Print the hotel management system
void print_hotel_management_system(HotelManagementSystem* hotel) {
    printf("Rooms:\n");
    for (int i = 0; i < hotel->num_rooms; i++) {
        printf("Room %d: %s, $%d, ", hotel->rooms[i].room_number, hotel->rooms[i].room_type, hotel->rooms[i].price);
        if (hotel->rooms[i].availability) {
            printf("Available\n");
        } else {
            printf("Occupied\n");
        }
    }
    printf("Guests:\n");
    for (int i = 0; i < hotel->num_guests; i++) {
        printf("Guest %d: %s, %s, %s, Room %d, Check-in: %d, Check-out: %d\n", i + 1, hotel->guests[i].name, hotel->guests[i].address, hotel->guests[i].phone_number, hotel->guests[i].room_number, hotel->guests[i].check_in_date, hotel->guests[i].check_out_date);
    }
}

// Free the hotel management system
void free_hotel_management_system(HotelManagementSystem* hotel) {
    free(hotel);
}

int main() {
    // Create a new hotel management system
    HotelManagementSystem* hotel = create_hotel_management_system();

    // Add some rooms to the hotel management system
    Room room1 = {1, "Standard", 100, 1};
    add_room(hotel, room1);
    Room room2 = {2, "Deluxe", 150, 1};
    add_room(hotel, room2);
    Room room3 = {3, "Suite", 200, 1};
    add_room(hotel, room3);

    // Add some guests to the hotel management system
    Guest guest1 = {"John Doe", "123 Main Street", "555-1212", 1, 20230301, 20230305};
    add_guest(hotel, guest1);
    Guest guest2 = {"Jane Doe", "456 Elm Street", "555-1213", 2, 20230302, 20230306};
    add_guest(hotel, guest2);
    Guest guest3 = {"John Smith", "789 Oak Street", "555-1214", 3, 20230303, 20230307};
    add_guest(hotel, guest3);

    // Print the hotel management system
    print_hotel_management_system(hotel);

    // Check in a guest
    Guest guest4 = {"Mary Jones", "1011 Maple Street", "555-1215", 1, 20230304, 20230308};
    check_in_guest(hotel, guest4);

    // Print the hotel management system
    print_hotel_management_system(hotel);

    // Check out a guest
    check_out_guest(hotel, "John Doe");

    // Print the hotel management system
    print_hotel_management_system(hotel);

    // Free the hotel management system
    free_hotel_management_system(hotel);

    return 0;
}