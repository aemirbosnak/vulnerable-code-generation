//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel information
typedef struct Hotel {
    char name[50];
    char address[100];
    int num_rooms;
    int num_occupied;
    float avg_nightly_rate;
} Hotel;

// Function to create a new hotel
Hotel *create_hotel(char *name, char *address, int num_rooms, int num_occupied, float avg_nightly_rate) {
    Hotel *hotel = (Hotel *)malloc(sizeof(Hotel));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    hotel->num_rooms = num_rooms;
    hotel->num_occupied = num_occupied;
    hotel->avg_nightly_rate = avg_nightly_rate;
    return hotel;
}

// Function to print hotel information
void print_hotel(Hotel *hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Hotel Address: %s\n", hotel->address);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Occupied Rooms: %d\n", hotel->num_occupied);
    printf("Average Nightly Rate: $%.2f\n", hotel->avg_nightly_rate);
}

// Function to check if a hotel is full
int is_hotel_full(Hotel *hotel) {
    return hotel->num_occupied == hotel->num_rooms;
}

// Function to check in a guest
int check_in_guest(Hotel *hotel) {
    if (is_hotel_full(hotel)) {
        return 0;
    }
    hotel->num_occupied++;
    return 1;
}

// Function to check out a guest
int check_out_guest(Hotel *hotel) {
    if (hotel->num_occupied == 0) {
        return 0;
    }
    hotel->num_occupied--;
    return 1;
}

// Function to calculate the total revenue for a hotel
float calculate_revenue(Hotel *hotel) {
    return hotel->num_occupied * hotel->avg_nightly_rate;
}

// Main function
int main() {
    // Create a new hotel
    Hotel *hotel = create_hotel("Hilton", "123 Main Street", 100, 50, 120.00);

    // Print hotel information
    print_hotel(hotel);

    // Check in a guest
    check_in_guest(hotel);

    // Print hotel information again
    print_hotel(hotel);

    // Check out a guest
    check_out_guest(hotel);

    // Print hotel information again
    print_hotel(hotel);

    // Calculate the total revenue for the hotel
    float revenue = calculate_revenue(hotel);

    // Print the total revenue
    printf("Total Revenue: $%.2f\n", revenue);

    return 0;
}