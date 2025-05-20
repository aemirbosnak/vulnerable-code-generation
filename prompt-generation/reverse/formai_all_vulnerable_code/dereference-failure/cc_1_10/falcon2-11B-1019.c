//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to represent a room
typedef struct {
    char roomNumber[10];
    char roomType[50];
    int pricePerNight;
} Room;

// Define a structure to represent a customer
typedef struct {
    char customerName[50];
    char customerEmail[100];
    char customerPhone[20];
} Customer;

// Define a structure to represent the hotel
typedef struct {
    int numRooms;
    Room *rooms;
    int numCustomers;
    Customer *customers;
} Hotel;

// Function to initialize the hotel
void initHotel(Hotel *hotel, int numRooms, Room *rooms, int numCustomers, Customer *customers) {
    hotel->numRooms = numRooms;
    hotel->rooms = rooms;
    hotel->numCustomers = numCustomers;
    hotel->customers = customers;
}

// Function to print the hotel details
void printHotelDetails(Hotel *hotel) {
    printf("Hotel Details:\n");
    printf("Number of Rooms: %d\n", hotel->numRooms);
    printf("Room Types:\n");
    for (int i = 0; i < hotel->numRooms; i++) {
        printf("%d - %s\n", i + 1, hotel->rooms[i].roomType);
    }
    printf("Number of Customers: %d\n", hotel->numCustomers);
    printf("Customers:\n");
    for (int i = 0; i < hotel->numCustomers; i++) {
        printf("%d - %s - %s - %s\n", i + 1, hotel->customers[i].customerName, hotel->customers[i].customerEmail, hotel->customers[i].customerPhone);
    }
}

// Function to add a room to the hotel
void addRoom(Hotel *hotel, char roomNumber[10], char roomType[50], int pricePerNight) {
    hotel->numRooms++;
    Room *newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->roomNumber, roomNumber);
    strcpy(newRoom->roomType, roomType);
    newRoom->pricePerNight = pricePerNight;
    hotel->rooms = (Room*)realloc(hotel->rooms, (hotel->numRooms + 1) * sizeof(Room));
    hotel->rooms[hotel->numRooms - 1] = *newRoom;
}

// Function to add a customer to the hotel
void addCustomer(Hotel *hotel, char customerName[50], char customerEmail[100], char customerPhone[20]) {
    hotel->numCustomers++;
    Customer *newCustomer = (Customer*)malloc(sizeof(Customer));
    strcpy(newCustomer->customerName, customerName);
    strcpy(newCustomer->customerEmail, customerEmail);
    strcpy(newCustomer->customerPhone, customerPhone);
    hotel->customers = (Customer*)realloc(hotel->customers, (hotel->numCustomers + 1) * sizeof(Customer));
    hotel->customers[hotel->numCustomers - 1] = *newCustomer;
}

// Function to book a room for a customer
void bookRoom(Hotel *hotel, int roomNumber, int days) {
    for (int i = 0; i < hotel->numRooms; i++) {
        if (strcmp(hotel->rooms[i].roomNumber, roomNumber) == 0) {
            hotel->rooms[i].pricePerNight *= (days + 1);
            printf("Room %d booked for %d days at %d credits per night.\n", roomNumber, days, hotel->rooms[i].pricePerNight);
            break;
        }
    }
}

// Function to check out a customer
void checkOutCustomer(Hotel *hotel, int customerNumber) {
    for (int i = 0; i < hotel->numCustomers; i++) {
        if (strcmp(hotel->customers[i].customerName, customerNumber) == 0) {
            printf("Customer %d has checked out.\n", customerNumber);
            break;
        }
    }
}

// Main function
int main() {
    Hotel hotel;
    initHotel(&hotel, 10, NULL, 0, NULL);

    Room rooms[10];
    Customer customers[10];

    // Add rooms to the hotel
    addRoom(&hotel, "101", "Standard", 50);
    addRoom(&hotel, "102", "Deluxe", 100);
    addRoom(&hotel, "103", "Executive", 150);

    // Add customers to the hotel
    addCustomer(&hotel, "John Doe", "john@example.com", "1234567890");
    addCustomer(&hotel, "Jane Doe", "jane@example.com", "9876543210");
    addCustomer(&hotel, "Bob Smith", "bob@example.com", "5555555555");

    // Book rooms for customers
    bookRoom(&hotel, "101", 3);
    bookRoom(&hotel, "102", 1);
    bookRoom(&hotel, "103", 2);

    // Check out customers
    checkOutCustomer(&hotel, "John Doe");
    checkOutCustomer(&hotel, "Bob Smith");

    printHotelDetails(&hotel);

    return 0;
}