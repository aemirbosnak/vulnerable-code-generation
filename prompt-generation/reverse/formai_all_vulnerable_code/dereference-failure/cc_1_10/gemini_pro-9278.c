//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel data
typedef struct Hotel {
    int hotel_id;
    char hotel_name[50];
    char hotel_address[100];
    int num_rooms;
    int num_available_rooms;
    float avg_room_price;
} Hotel;

// Function to create a new hotel
Hotel* create_hotel(int hotel_id, char* hotel_name, char* hotel_address, int num_rooms, int num_available_rooms, float avg_room_price) {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    hotel->hotel_id = hotel_id;
    strcpy(hotel->hotel_name, hotel_name);
    strcpy(hotel->hotel_address, hotel_address);
    hotel->num_rooms = num_rooms;
    hotel->num_available_rooms = num_available_rooms;
    hotel->avg_room_price = avg_room_price;
    return hotel;
}

// Function to print hotel details
void print_hotel(Hotel* hotel) {
    printf("Hotel ID: %d\n", hotel->hotel_id);
    printf("Hotel Name: %s\n", hotel->hotel_name);
    printf("Hotel Address: %s\n", hotel->hotel_address);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Available Rooms: %d\n", hotel->num_available_rooms);
    printf("Average Room Price: %.2f\n", hotel->avg_room_price);
}

// Function to search for a hotel by name
Hotel* search_hotel_by_name(Hotel* hotels[], int num_hotels, char* hotel_name) {
    for (int i = 0; i < num_hotels; i++) {
        if (strcmp(hotels[i]->hotel_name, hotel_name) == 0) {
            return hotels[i];
        }
    }
    return NULL;
}

// Function to book a room in a hotel
int book_room(Hotel* hotel) {
    if (hotel->num_available_rooms > 0) {
        hotel->num_available_rooms--;
        return 1;
    } else {
        return 0;
    }
}

// Function to cancel a room booking in a hotel
int cancel_room_booking(Hotel* hotel) {
    if (hotel->num_available_rooms < hotel->num_rooms) {
        hotel->num_available_rooms++;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Create an array of hotels
    Hotel* hotels[] = {
        create_hotel(1, "Hotel 1", "123 Main Street", 100, 50, 100.0),
        create_hotel(2, "Hotel 2", "456 Elm Street", 150, 75, 120.0),
        create_hotel(3, "Hotel 3", "789 Oak Street", 200, 100, 150.0)
    };
    int num_hotels = sizeof(hotels) / sizeof(Hotel*);

    // Print the details of all hotels
    for (int i = 0; i < num_hotels; i++) {
        print_hotel(hotels[i]);
        printf("\n");
    }

    // Search for a hotel by name
    char hotel_name[50];
    printf("Enter the name of the hotel you want to search for: ");
    scanf("%s", hotel_name);
    Hotel* hotel = search_hotel_by_name(hotels, num_hotels, hotel_name);
    if (hotel != NULL) {
        printf("Hotel found:\n");
        print_hotel(hotel);
    } else {
        printf("Hotel not found.\n");
    }

    // Book a room in a hotel
    int hotel_id;
    printf("Enter the ID of the hotel you want to book a room in: ");
    scanf("%d", &hotel_id);
    hotel = search_hotel_by_name(hotels, num_hotels, hotel_id);
    if (hotel != NULL) {
        if (book_room(hotel)) {
            printf("Room booked successfully.\n");
        } else {
            printf("No rooms available.\n");
        }
    } else {
        printf("Hotel not found.\n");
    }

    // Cancel a room booking in a hotel
    printf("Enter the ID of the hotel you want to cancel a room booking in: ");
    scanf("%d", &hotel_id);
    hotel = search_hotel_by_name(hotels, num_hotels, hotel_id);
    if (hotel != NULL) {
        if (cancel_room_booking(hotel)) {
            printf("Room booking cancelled successfully.\n");
        } else {
            printf("No room bookings to cancel.\n");
        }
    } else {
        printf("Hotel not found.\n");
    }

    return 0;
}