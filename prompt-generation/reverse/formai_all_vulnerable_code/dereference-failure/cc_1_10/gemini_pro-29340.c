//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hotel structure
typedef struct hotel {
    char name[50];
    char address[100];
    int num_rooms;
    int num_occupied;
    float price;
} hotel_t;

// Define the guest structure
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    int num_nights;
    float total_cost;
} guest_t;

// Function to create a new hotel
hotel_t *create_hotel(char *name, char *address, int num_rooms, float price) {
    hotel_t *hotel = (hotel_t *)malloc(sizeof(hotel_t));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    hotel->num_rooms = num_rooms;
    hotel->num_occupied = 0;
    hotel->price = price;
    return hotel;
}

// Function to create a new guest
guest_t *create_guest(char *name, char *address, char *phone, int num_nights) {
    guest_t *guest = (guest_t *)malloc(sizeof(guest_t));
    strcpy(guest->name, name);
    strcpy(guest->address, address);
    strcpy(guest->phone, phone);
    guest->num_nights = num_nights;
    guest->total_cost = 0;
    return guest;
}

// Function to check in a guest
void check_in_guest(hotel_t *hotel, guest_t *guest) {
    if (hotel->num_occupied < hotel->num_rooms) {
        hotel->num_occupied++;
        guest->total_cost = guest->num_nights * hotel->price;
    } else {
        printf("Sorry, the hotel is full.\n");
    }
}

// Function to check out a guest
void check_out_guest(hotel_t *hotel, guest_t *guest) {
    hotel->num_occupied--;
}

// Function to print the hotel details
void print_hotel_details(hotel_t *hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Hotel Address: %s\n", hotel->address);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Occupied Rooms: %d\n", hotel->num_occupied);
    printf("Price per Night: %.2f\n", hotel->price);
}

// Function to print the guest details
void print_guest_details(guest_t *guest) {
    printf("Guest Name: %s\n", guest->name);
    printf("Guest Address: %s\n", guest->address);
    printf("Guest Phone: %s\n", guest->phone);
    printf("Number of Nights: %d\n", guest->num_nights);
    printf("Total Cost: %.2f\n", guest->total_cost);
}

// Main function
int main() {
    // Create a new hotel
    hotel_t *hotel = create_hotel("The Grand Hotel", "123 Main Street", 100, 100.00);

    // Create a new guest
    guest_t *guest = create_guest("John Doe", "123 Main Street", "555-1212", 3);

    // Check in the guest
    check_in_guest(hotel, guest);

    // Print the hotel details
    print_hotel_details(hotel);

    // Print the guest details
    print_guest_details(guest);

    // Check out the guest
    check_out_guest(hotel, guest);

    // Print the hotel details
    print_hotel_details(hotel);

    // Free the memory allocated for the hotel and guest
    free(hotel);
    free(guest);

    return 0;
}