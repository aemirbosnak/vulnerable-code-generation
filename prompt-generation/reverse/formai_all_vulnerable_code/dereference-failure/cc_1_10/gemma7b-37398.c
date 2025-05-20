//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[50];
    char address[100];
    int rooms_available;
    int rooms_occupied;
    double average_rate;
    struct HotelManagementSystem *next;
} HotelManagementSystem;

// Create a linked list of hotel management systems
HotelManagementSystem *head = NULL;

// Function to insert a new hotel management system into the linked list
void insert_hotel(char *name, char *address, int rooms_available, int rooms_occupied, double average_rate) {
    HotelManagementSystem *new_hotel = (HotelManagementSystem *)malloc(sizeof(HotelManagementSystem));
    strcpy(new_hotel->name, name);
    strcpy(new_hotel->address, address);
    new_hotel->rooms_available = rooms_available;
    new_hotel->rooms_occupied = rooms_occupied;
    new_hotel->average_rate = average_rate;
    new_hotel->next = NULL;

    if (head == NULL) {
        head = new_hotel;
    } else {
        HotelManagementSystem *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_hotel;
    }
}

// Function to search for a hotel management system by name
HotelManagementSystem *search_hotel(char *name) {
    HotelManagementSystem *temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the number of rooms available in a hotel management system
void update_rooms_available(HotelManagementSystem *hotel, int rooms_available) {
    hotel->rooms_available = rooms_available;
}

// Function to update the average rate of a hotel management system
void update_average_rate(HotelManagementSystem *hotel, double average_rate) {
    hotel->average_rate = average_rate;
}

// Function to print the details of a hotel management system
void print_hotel(HotelManagementSystem *hotel) {
    printf("Name: %s\n", hotel->name);
    printf("Address: %s\n", hotel->address);
    printf("Rooms Available: %d\n", hotel->rooms_available);
    printf("Rooms Occupied: %d\n", hotel->rooms_occupied);
    printf("Average Rate: %.2lf\n", hotel->average_rate);
    printf("\n");
}

int main() {
    // Insert some hotel management systems into the linked list
    insert_hotel("The Grand Hotel", "123 Main St.", 100, 20, 100.0);
    insert_hotel("The Fairmont Hotel", "456 Oak Ave.", 80, 15, 90.0);
    insert_hotel("The Ritz-Carlton Hotel", "789 Park Ave.", 60, 10, 80.0);

    // Search for a hotel management system by name
    HotelManagementSystem *hotel = search_hotel("The Grand Hotel");

    // Print the details of the hotel management system
    print_hotel(hotel);

    // Update the number of rooms available in the hotel management system
    update_rooms_available(hotel, 120);

    // Update the average rate of the hotel management system
    update_average_rate(hotel, 105.0);

    // Print the updated details of the hotel management system
    print_hotel(hotel);

    return 0;
}