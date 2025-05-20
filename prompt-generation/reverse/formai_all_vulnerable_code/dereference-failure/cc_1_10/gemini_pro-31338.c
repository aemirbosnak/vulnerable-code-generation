//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum number of guests per room
#define MAX_GUESTS_PER_ROOM 4

// Define the maximum length of a guest name
#define MAX_GUEST_NAME_LENGTH 32

// Define the maximum length of a room type
#define MAX_ROOM_TYPE_LENGTH 32

// Define the maximum length of a date
#define MAX_DATE_LENGTH 11

// Define the structure of a guest
typedef struct {
    char name[MAX_GUEST_NAME_LENGTH];
    char room_type[MAX_ROOM_TYPE_LENGTH];
    char arrival_date[MAX_DATE_LENGTH];
    char departure_date[MAX_DATE_LENGTH];
} guest;

// Define the structure of a room
typedef struct {
    int room_number;
    int number_of_guests;
    guest guests[MAX_GUESTS_PER_ROOM];
} room;

// Define the structure of the hotel
typedef struct {
    room rooms[MAX_ROOMS];
    int number_of_rooms;
} hotel;

// Create a new hotel
hotel* create_hotel() {
    hotel* h = (hotel*)malloc(sizeof(hotel));
    h->number_of_rooms = 0;
    return h;
}

// Add a new room to the hotel
void add_room(hotel* h, int room_number) {
    h->rooms[h->number_of_rooms].room_number = room_number;
    h->number_of_rooms++;
}

// Add a new guest to a room
void add_guest(hotel* h, int room_number, guest g) {
    h->rooms[room_number].guests[h->rooms[room_number].number_of_guests] = g;
    h->rooms[room_number].number_of_guests++;
}

// Print the hotel information
void print_hotel(hotel* h) {
    for (int i = 0; i < h->number_of_rooms; i++) {
        printf("Room %d:\n", h->rooms[i].room_number);
        for (int j = 0; j < h->rooms[i].number_of_guests; j++) {
            printf("  Guest %d:\n", j + 1);
            printf("    Name: %s\n", h->rooms[i].guests[j].name);
            printf("    Room type: %s\n", h->rooms[i].guests[j].room_type);
            printf("    Arrival date: %s\n", h->rooms[i].guests[j].arrival_date);
            printf("    Departure date: %s\n", h->rooms[i].guests[j].departure_date);
        }
    }
}

// Free the memory allocated for the hotel
void free_hotel(hotel* h) {
    free(h);
}

// Main function
int main() {
    // Create a new hotel
    hotel* h = create_hotel();

    // Add some rooms to the hotel
    add_room(h, 101);
    add_room(h, 102);
    add_room(h, 103);

    // Add some guests to the rooms
    guest g1 = {"John Smith", "Single", "2023-06-01", "2023-06-07"};
    add_guest(h, 101, g1);

    guest g2 = {"Jane Doe", "Double", "2023-06-02", "2023-06-08"};
    add_guest(h, 102, g2);

    guest g3 = {"Bill Jones", "Triple", "2023-06-03", "2023-06-09"};
    add_guest(h, 103, g3);

    // Print the hotel information
    print_hotel(h);

    // Free the memory allocated for the hotel
    free_hotel(h);

    return 0;
}