//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store hotel information
struct hotel {
    char name[100];
    int capacity;
    float price;
    int occupancy;
};

// Function to create a new hotel
struct hotel* create_hotel(const char* name, int capacity, float price) {
    struct hotel* hotel = malloc(sizeof(struct hotel));
    strcpy(hotel->name, name);
    hotel->capacity = capacity;
    hotel->price = price;
    hotel->occupancy = 0;
    return hotel;
}

// Function to display hotel information
void display_hotel(struct hotel* hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Capacity: %d\n", hotel->capacity);
    printf("Price: $%.2f\n", hotel->price);
    printf("Occupancy: %d/%d\n", hotel->occupancy, hotel->capacity);
}

// Function to book a room in the hotel
void book_room(struct hotel* hotel, int room_number) {
    if (hotel->occupancy < hotel->capacity) {
        hotel->occupancy++;
        printf("Room %d has been booked.\n", room_number);
    } else {
        printf("Hotel is full.\n");
    }
}

// Function to check out a room in the hotel
void check_out(struct hotel* hotel, int room_number) {
    if (hotel->occupancy > 0) {
        hotel->occupancy--;
        printf("Room %d has been checked out.\n", room_number);
    } else {
        printf("No rooms available.\n");
    }
}

// Function to calculate the total price for a booking
float calculate_price(struct hotel* hotel, int days) {
    float price_per_day = hotel->price * (1 + (float)hotel->occupancy / 100);
    return days * price_per_day;
}

// Function to print the hotel's bill
void print_bill(struct hotel* hotel, int days) {
    float total_price = calculate_price(hotel, days);
    printf("Total Price: $%.2f\n", total_price);
}

// Main function
int main() {
    // Create a hotel
    struct hotel* hotel = create_hotel("ABC Hotel", 100, 100.00);

    // Display hotel information
    display_hotel(hotel);

    // Book a room
    book_room(hotel, 101);
    book_room(hotel, 102);

    // Check out a room
    check_out(hotel, 101);
    check_out(hotel, 102);

    // Calculate the total price for a 10-day booking
    int days = 10;
    float total_price = calculate_price(hotel, days);

    // Print the hotel's bill
    print_bill(hotel, days);

    // Free the memory allocated for the hotel
    free(hotel);

    return 0;
}