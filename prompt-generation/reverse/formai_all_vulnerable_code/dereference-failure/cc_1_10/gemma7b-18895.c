//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[50];
    int room_number;
    float price;
    struct HotelManagementSystem *next;
} HotelManagementSystem;

// Function to insert a new room into the hotel management system
void insert_room(HotelManagementSystem **head) {
    // Allocate memory for the new room
    HotelManagementSystem *new_room = (HotelManagementSystem *)malloc(sizeof(HotelManagementSystem));

    // Get the room name, number, and price from the user
    printf("Enter the room name: ");
    scanf("%s", new_room->name);

    printf("Enter the room number: ");
    scanf("%d", &new_room->room_number);

    printf("Enter the room price: ");
    scanf("%f", &new_room->price);

    // Insert the new room into the linked list
    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
        *head = new_room;
    }
}

// Function to search for a room in the hotel management system
void search_room(HotelManagementSystem *head) {
    // Get the room number from the user
    int room_number;
    printf("Enter the room number: ");
    scanf("%d", &room_number);

    // Search for the room in the linked list
    HotelManagementSystem *current_room = head;
    while (current_room) {
        if (current_room->room_number == room_number) {
            // Print the room information
            printf("Room name: %s\n", current_room->name);
            printf("Room number: %d\n", current_room->room_number);
            printf("Room price: %.2f\n", current_room->price);
            break;
        }
        current_room = current_room->next;
    }

    // If the room is not found, print an error message
    if (current_room == NULL) {
        printf("Room not found.\n");
    }
}

// Function to delete a room from the hotel management system
void delete_room(HotelManagementSystem *head) {
    // Get the room number from the user
    int room_number;
    printf("Enter the room number: ");
    scanf("%d", &room_number);

    // Search for the room in the linked list
    HotelManagementSystem *current_room = head;
    HotelManagementSystem *previous_room = NULL;
    while (current_room) {
        if (current_room->room_number == room_number) {
            // If the room is the first room in the list, update the head of the list
            if (previous_room == NULL) {
                head = current_room->next;
            } else {
                // Otherwise, update the previous room to point to the next room in the list
                previous_room->next = current_room->next;
            }

            // Free the memory of the room
            free(current_room);
            break;
        }
        previous_room = current_room;
        current_room = current_room->next;
    }

    // If the room is not found, print an error message
    if (current_room == NULL) {
        printf("Room not found.\n");
    }
}

int main() {
    // Create a linked list of rooms
    HotelManagementSystem *head = NULL;

    // Insert some rooms into the list
    insert_room(&head);
    insert_room(&head);
    insert_room(&head);

    // Search for a room in the list
    search_room(head);

    // Delete a room from the list
    delete_room(head);

    // Search for the room after deletion
    search_room(head);

    return 0;
}