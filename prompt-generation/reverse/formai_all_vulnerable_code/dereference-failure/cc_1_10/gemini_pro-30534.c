//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hotel {
    char name[50];
    char address[100];
    char phone[20];
    int num_rooms;
    int num_occupied;
    float avg_price;
};

// Function to create a new hotel
struct Hotel *create_hotel(char *name, char *address, char *phone, int num_rooms, float avg_price) {
    struct Hotel *hotel = malloc(sizeof(struct Hotel));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    strcpy(hotel->phone, phone);
    hotel->num_rooms = num_rooms;
    hotel->num_occupied = 0;
    hotel->avg_price = avg_price;
    return hotel;
}

// Function to print the details of a hotel
void print_hotel(struct Hotel *hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Hotel Address: %s\n", hotel->address);
    printf("Hotel Phone: %s\n", hotel->phone);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Occupied Rooms: %d\n", hotel->num_occupied);
    printf("Average Price: %.2f\n", hotel->avg_price);
}

// Function to check in a guest
void check_in(struct Hotel *hotel) {
    if (hotel->num_occupied == hotel->num_rooms) {
        printf("Sorry, the hotel is full.\n");
    } else {
        hotel->num_occupied++;
    }
}

// Function to check out a guest
void check_out(struct Hotel *hotel) {
    if (hotel->num_occupied == 0) {
        printf("Sorry, there are no guests checked in.\n");
    } else {
        hotel->num_occupied--;
    }
}

// Function to main
int main() {
    // Create a new hotel
    struct Hotel *hotel = create_hotel("The Grand Hotel", "123 Main Street", "555-1212", 100, 100.00);

    // Print the details of the hotel
    print_hotel(hotel);

    // Check in a guest
    check_in(hotel);

    // Print the details of the hotel
    print_hotel(hotel);

    // Check out a guest
    check_out(hotel);

    // Print the details of the hotel
    print_hotel(hotel);

    // Free the memory allocated for the hotel
    free(hotel);

    return 0;
}