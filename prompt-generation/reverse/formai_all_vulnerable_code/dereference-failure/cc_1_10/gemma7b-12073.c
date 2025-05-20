//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[50];
    int rooms;
    int availableRooms;
    double rate;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Create a linked list of hotel management systems
HotelManagementSystem* head = NULL;

// Function to insert a new hotel management system into the linked list
void insertHotelManagementSystem(char* name, int rooms, int availableRooms, double rate) {
    HotelManagementSystem* newSystem = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    strcpy(newSystem->name, name);
    newSystem->rooms = rooms;
    newSystem->availableRooms = availableRooms;
    newSystem->rate = rate;
    newSystem->next = NULL;

    if (head == NULL) {
        head = newSystem;
    } else {
        HotelManagementSystem* currentSystem = head;
        while (currentSystem->next != NULL) {
            currentSystem = currentSystem->next;
        }
        currentSystem->next = newSystem;
    }
}

// Function to search for a hotel management system by name
HotelManagementSystem* searchHotelManagementSystemByName(char* name) {
    HotelManagementSystem* currentSystem = head;
    while (currentSystem) {
        if (strcmp(currentSystem->name, name) == 0) {
            return currentSystem;
        }
        currentSystem = currentSystem->next;
    }
    return NULL;
}

// Function to update the available rooms of a hotel management system
void updateAvailableRooms(char* name, int availableRooms) {
    HotelManagementSystem* system = searchHotelManagementSystemByName(name);
    if (system) {
        system->availableRooms = availableRooms;
    }
}

// Function to get the rate of a hotel management system
double getRate(char* name) {
    HotelManagementSystem* system = searchHotelManagementSystemByName(name);
    if (system) {
        return system->rate;
    }
    return -1;
}

// Main function
int main() {
    insertHotelManagementSystem("The Grand Hotel", 100, 50, 100.0);
    insertHotelManagementSystem("The Royal Hotel", 200, 100, 120.0);
    insertHotelManagementSystem("The Fairmont Hotel", 300, 70, 150.0);

    printf("Name: %s\n", searchHotelManagementSystemByName("The Grand Hotel")->name);
    printf("Available rooms: %d\n", searchHotelManagementSystemByName("The Royal Hotel")->availableRooms);
    printf("Rate: %.2lf\n", getRate("The Fairmont Hotel"));

    updateAvailableRooms("The Grand Hotel", 60);

    printf("Updated available rooms: %d\n", searchHotelManagementSystemByName("The Grand Hotel")->availableRooms);

    return 0;
}