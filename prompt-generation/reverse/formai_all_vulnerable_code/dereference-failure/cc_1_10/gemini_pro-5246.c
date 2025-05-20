//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum length of a guest name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a room type
#define MAX_TYPE_LENGTH 20

// Define the structure of a guest
typedef struct Guest {
    char name[MAX_NAME_LENGTH];
    char room_type[MAX_TYPE_LENGTH];
    int room_number;
    int check_in_date;
    int check_out_date;
} Guest;

// Define the structure of a hotel
typedef struct Hotel {
    Guest guests[MAX_ROOMS];
    int num_guests;
} Hotel;

// Create a new hotel
Hotel* create_hotel() {
    Hotel* hotel = malloc(sizeof(Hotel));
    hotel->num_guests = 0;
    return hotel;
}

// Add a guest to the hotel
void add_guest(Hotel* hotel, Guest guest) {
    hotel->guests[hotel->num_guests] = guest;
    hotel->num_guests++;
}

// Remove a guest from the hotel
void remove_guest(Hotel* hotel, int room_number) {
    for (int i = 0; i < hotel->num_guests; i++) {
        if (hotel->guests[i].room_number == room_number) {
            hotel->guests[i] = hotel->guests[hotel->num_guests - 1];
            hotel->num_guests--;
            break;
        }
    }
}

// Print the list of guests in the hotel
void print_guests(Hotel* hotel) {
    for (int i = 0; i < hotel->num_guests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", hotel->guests[i].name);
        printf("Room type: %s\n", hotel->guests[i].room_type);
        printf("Room number: %d\n", hotel->guests[i].room_number);
        printf("Check-in date: %d\n", hotel->guests[i].check_in_date);
        printf("Check-out date: %d\n\n", hotel->guests[i].check_out_date);
    }
}

// Main function
int main() {
    // Create a new hotel
    Hotel* hotel = create_hotel();

    // Add some guests to the hotel
    Guest guest1 = {"John Smith", "Single", 101, 20230101, 20230107};
    add_guest(hotel, guest1);
    Guest guest2 = {"Jane Doe", "Double", 102, 20230102, 20230108};
    add_guest(hotel, guest2);
    Guest guest3 = {"Peter Jones", "Suite", 103, 20230103, 20230109};
    add_guest(hotel, guest3);

    // Print the list of guests in the hotel
    print_guests(hotel);

    // Remove a guest from the hotel
    remove_guest(hotel, 102);

    // Print the list of guests in the hotel
    print_guests(hotel);

    // Free the memory allocated for the hotel
    free(hotel);

    return 0;
}