//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel information
struct Hotel {
    char name[50];
    char address[100];
    int num_rooms;
    double price;
};

// Function to create a new hotel
struct Hotel* create_hotel(char* name, char* address, int num_rooms, double price) {
    struct Hotel* hotel = (struct Hotel*)malloc(sizeof(struct Hotel));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    hotel->num_rooms = num_rooms;
    hotel->price = price;
    return hotel;
}

// Function to print hotel information
void print_hotel(struct Hotel* hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Address: %s\n", hotel->address);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Price: $%.2f\n", hotel->price);
}

// Main function
int main() {
    // Create three hotels
    struct Hotel* hotel1 = create_hotel("The Grand Hotel", "123 Main Street", 100, 120.00);
    struct Hotel* hotel2 = create_hotel("The Ritz-Carlton", "456 Park Avenue", 200, 200.00);
    struct Hotel* hotel3 = create_hotel("The Four Seasons", "789 Fifth Avenue", 300, 250.00);

    // Print the information of each hotel
    print_hotel(hotel1);
    printf("\n");
    print_hotel(hotel2);
    printf("\n");
    print_hotel(hotel3);
    printf("\n");

    // Free the memory allocated for each hotel
    free(hotel1);
    free(hotel2);
    free(hotel3);

    return 0;
}