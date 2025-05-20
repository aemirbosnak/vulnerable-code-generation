//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define the number of rooms in the hotel
#define NUM_ROOMS 100

// Define the room structure
typedef struct room {
    char name[20];
    int number;
    double price;
    struct room* next;
} room;

// Define the hotel management system structure
typedef struct hotel_management_system {
    room* head;
    room* tail;
    int num_rooms;
} hotel_management_system;

// Function to insert a room into the hotel management system
void insert_room(hotel_management_system* hms, char* name, int number, double price) {
    // Allocate memory for a new room
    room* new_room = malloc(sizeof(room));

    // Copy the room name, number, and price
    strcpy(new_room->name, name);
    new_room->number = number;
    new_room->price = price;

    // If the head of the hotel management system is NULL, make it the new head
    if (hms->head == NULL) {
        hms->head = new_room;
        hms->tail = new_room;
    } else {
        // Otherwise, insert the new room at the tail
        hms->tail->next = new_room;
        hms->tail = new_room;
    }

    // Increment the number of rooms in the hotel management system
    hms->num_rooms++;
}

// Function to search for a room in the hotel management system
room* search_room(hotel_management_system* hms, int number) {
    // Traverse the hotel management system to find the room
    room* current_room = hms->head;
    while (current_room) {
        if (current_room->number == number) {
            return current_room;
        }
        current_room = current_room->next;
    }

    // Return NULL if the room is not found
    return NULL;
}

// Function to delete a room from the hotel management system
void delete_room(hotel_management_system* hms, int number) {
    // Search for the room to delete
    room* room_to_delete = search_room(hms, number);

    // If the room to delete is found, delete it
    if (room_to_delete) {
        // If the room to delete is the head of the hotel management system, make the second room the head
        if (room_to_delete == hms->head) {
            hms->head = room_to_delete->next;
        } else {
            // Otherwise, delete the room from the tail
            room* previous_room = hms->head;
            while (previous_room->next != room_to_delete) {
                previous_room = previous_room->next;
            }
            previous_room->next = room_to_delete->next;
        }

        // Decrement the number of rooms in the hotel management system
        hms->num_rooms--;

        // Free the memory allocated for the room
        free(room_to_delete);
    }
}

int main() {
    // Create a hotel management system
    hotel_management_system* hms = malloc(sizeof(hotel_management_system));
    hms->head = NULL;
    hms->tail = NULL;
    hms->num_rooms = 0;

    // Insert some rooms into the hotel management system
    insert_room(hms, "John Doe's Room", 101, 50.0);
    insert_room(hms, "Jane Doe's Room", 102, 60.0);
    insert_room(hms, "Bill Smith's Room", 103, 70.0);

    // Search for a room in the hotel management system
    room* room_found = search_room(hms, 102);

    // If the room is found, print its name and price
    if (room_found) {
        printf("Name: %s\n", room_found->name);
        printf("Price: %.2lf\n", room_found->price);
    } else {
        printf("Room not found.\n");
    }

    // Delete a room from the hotel management system
    delete_room(hms, 101);

    // Search for the room that was deleted
    room_found = search_room(hms, 101);

    // If the room is not found, print an error message
    if (room_found == NULL) {
        printf("Room not found.\n");
    } else {
        printf("Name: %s\n", room_found->name);
        printf("Price: %.2lf\n", room_found->price);
    }

    // Free the memory allocated for the hotel management system
    free(hms);

    return 0;
}