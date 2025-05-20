//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define hotel room data structure
typedef struct HotelRoom {
    int roomNumber;
    int occupancy;
    float price;
    char type[20];
} HotelRoom;

// Define hotel data structure
typedef struct Hotel {
    char name[50];
    int totalRooms;
    int occupiedRooms;
    float occupancyRate;
    HotelRoom *rooms;
} Hotel;

// Initialize hotel rooms
void initializeRooms(Hotel *hotel) {
    hotel->rooms = (HotelRoom *)malloc(hotel->totalRooms * sizeof(HotelRoom));
    for (int i = 0; i < hotel->totalRooms; i++) {
        hotel->rooms[i].roomNumber = i + 1;
        hotel->rooms[i].occupancy = 0;
        hotel->rooms[i].price = 100.0;
        strcpy(hotel->rooms[i].type, "Standard");
    }
}

// Display hotel room information
void displayRooms(Hotel hotel) {
    printf("Room Number\tOccupancy\tType\tPrice\n");
    for (int i = 0; i < hotel.totalRooms; i++) {
        printf("%d\t\t%d\t\t%s\t%.2f\n", hotel.rooms[i].roomNumber, hotel.rooms[i].occupancy, hotel.rooms[i].type, hotel.rooms[i].price);
    }
}

// Display hotel statistics
void displayHotelStats(Hotel hotel) {
    printf("Hotel Name: %s\n", hotel.name);
    printf("Total Rooms: %d\n", hotel.totalRooms);
    printf("Occupied Rooms: %d\n", hotel.occupiedRooms);
    printf("Occupancy Rate: %.2f%%\n", hotel.occupancyRate);
}

int main() {
    // Initialize hotel
    Hotel hotel;
    strcpy(hotel.name, "My Hotel");
    hotel.totalRooms = 10;
    hotel.occupiedRooms = 0;
    hotel.occupancyRate = 0.0;
    initializeRooms(&hotel);
    
    // Display hotel room information
    displayRooms(hotel);
    
    // Display hotel statistics
    displayHotelStats(hotel);
    
    // Free memory
    free(hotel.rooms);
    
    return 0;
}