//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure to represent a hotel
typedef struct {
    char name[100];
    int capacity;
    int guests;
} Hotel;

// Function to create a new hotel
Hotel* createHotel(char name[], int capacity) {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    strcpy(hotel->name, name);
    hotel->capacity = capacity;
    hotel->guests = 0;
    return hotel;
}

// Function to add a guest to the hotel
void addGuest(Hotel* hotel) {
    if (hotel->guests < hotel->capacity) {
        hotel->guests++;
        printf("Added %d guests to %s\n", hotel->guests, hotel->name);
    } else {
        printf("Hotel is full\n");
    }
}

// Function to remove a guest from the hotel
void removeGuest(Hotel* hotel) {
    if (hotel->guests > 0) {
        hotel->guests--;
        printf("Removed %d guests from %s\n", hotel->guests, hotel->name);
    } else {
        printf("Hotel is empty\n");
    }
}

// Function to display hotel information
void displayHotelInfo(Hotel* hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Capacity: %d\n", hotel->capacity);
    printf("Guests: %d\n", hotel->guests);
}

// Function to print menu options
void printMenu() {
    printf("1. Add Guest\n");
    printf("2. Remove Guest\n");
    printf("3. Display Hotel Info\n");
    printf("4. Exit\n");
}

// Function to handle menu options
void handleMenuOption(Hotel* hotel) {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: addGuest(hotel); break;
        case 2: removeGuest(hotel); break;
        case 3: displayHotelInfo(hotel); break;
        case 4: exit(0);
    }
}

// Main function
int main() {
    Hotel* hotel = createHotel("ABC Hotel", 100);
    printMenu();
    
    while (true) {
        handleMenuOption(hotel);
    }
    
    return 0;
}