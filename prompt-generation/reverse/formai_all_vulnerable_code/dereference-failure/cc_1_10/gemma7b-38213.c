//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[50];
    int rooms_available;
    double room_price;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Create a linked list of hotel management systems
HotelManagementSystem* head = NULL;

// Function to add a hotel management system to the linked list
void add_hotel(char* name, int rooms_available, double room_price) {
    HotelManagementSystem* new_hotel = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    strcpy(new_hotel->name, name);
    new_hotel->rooms_available = rooms_available;
    new_hotel->room_price = room_price;
    new_hotel->next = NULL;

    if (head == NULL) {
        head = new_hotel;
    } else {
        HotelManagementSystem* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_hotel;
    }
}

// Function to find a hotel management system by name
HotelManagementSystem* find_hotel(char* name) {
    HotelManagementSystem* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to check if a room is available
int is_room_available(char* name) {
    HotelManagementSystem* hotel = find_hotel(name);
    if (hotel) {
        return hotel->rooms_available > 0;
    }
    return 0;
}

// Function to book a room
void book_room(char* name, int num_rooms) {
    HotelManagementSystem* hotel = find_hotel(name);
    if (hotel) {
        hotel->rooms_available -= num_rooms;
    }
}

// Function to get the room price
double get_room_price(char* name) {
    HotelManagementSystem* hotel = find_hotel(name);
    if (hotel) {
        return hotel->room_price;
    }
    return -1;
}

// Main function
int main() {
    // Add some hotel management systems
    add_hotel("The Grand Hotel", 100, 100.0);
    add_hotel("The Ritz-Carlton", 50, 200.0);
    add_hotel("The Four Seasons", 25, 300.0);

    // Check if a room is available
    if (is_room_available("The Grand Hotel")) {
        printf("Room available at The Grand Hotel.\n");
    }

    // Book a room
    book_room("The Grand Hotel", 10);

    // Get the room price
    double room_price = get_room_price("The Grand Hotel");
    if (room_price != -1) {
        printf("Room price at The Grand Hotel: $%.2lf.\n", room_price);
    }

    return 0;
}