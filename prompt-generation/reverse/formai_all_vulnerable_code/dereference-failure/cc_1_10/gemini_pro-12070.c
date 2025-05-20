//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store hotel information
typedef struct Hotel {
    char name[50];
    char address[100];
    int num_rooms;
    float price;
} Hotel;

// Data structure to store booking information
typedef struct Booking {
    char customer_name[50];
    char check_in_date[20];
    char check_out_date[20];
    int num_guests;
    Hotel *hotel;
} Booking;

// Function to create a new hotel
Hotel *create_hotel(char *name, char *address, int num_rooms, float price) {
    Hotel *hotel = (Hotel *)malloc(sizeof(Hotel));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    hotel->num_rooms = num_rooms;
    hotel->price = price;
    return hotel;
}

// Function to create a new booking
Booking *create_booking(char *customer_name, char *check_in_date, char *check_out_date, int num_guests, Hotel *hotel) {
    Booking *booking = (Booking *)malloc(sizeof(Booking));
    strcpy(booking->customer_name, customer_name);
    strcpy(booking->check_in_date, check_in_date);
    strcpy(booking->check_out_date, check_out_date);
    booking->num_guests = num_guests;
    booking->hotel = hotel;
    return booking;
}

// Function to print hotel information
void print_hotel(Hotel *hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Address: %s\n", hotel->address);
    printf("Number of rooms: %d\n", hotel->num_rooms);
    printf("Price: %.2f\n", hotel->price);
}

// Function to print booking information
void print_booking(Booking *booking) {
    printf("Customer name: %s\n", booking->customer_name);
    printf("Check-in date: %s\n", booking->check_in_date);
    printf("Check-out date: %s\n", booking->check_out_date);
    printf("Number of guests: %d\n", booking->num_guests);
    printf("Hotel: %s\n", booking->hotel->name);
}

// Main function
int main() {
    // Create a few hotels
    Hotel *hotel1 = create_hotel("Hotel 1", "123 Main Street", 100, 100.0);
    Hotel *hotel2 = create_hotel("Hotel 2", "456 Elm Street", 200, 150.0);
    Hotel *hotel3 = create_hotel("Hotel 3", "789 Oak Street", 300, 200.0);

    // Create a few bookings
    Booking *booking1 = create_booking("John Doe", "2023-06-01", "2023-06-07", 2, hotel1);
    Booking *booking2 = create_booking("Jane Smith", "2023-07-01", "2023-07-10", 4, hotel2);
    Booking *booking3 = create_booking("Bill Jones", "2023-08-01", "2023-08-15", 6, hotel3);

    // Print the hotel and booking information
    print_hotel(hotel1);
    print_booking(booking1);
    printf("\n");
    print_hotel(hotel2);
    print_booking(booking2);
    printf("\n");
    print_hotel(hotel3);
    print_booking(booking3);

    // Free the allocated memory
    free(hotel1);
    free(hotel2);
    free(hotel3);
    free(booking1);
    free(booking2);
    free(booking3);

    return 0;
}