//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[50];
    int room_number;
    float rate;
    char type;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to insert a node into the hotel management system
void insertNode(HotelManagementSystem** head, HotelManagementSystem* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

// Function to search for a room in the hotel management system
HotelManagementSystem* searchRoom(HotelManagementSystem* head, int room_number) {
    while (head) {
        if (head->room_number == room_number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the rate of a room in the hotel management system
void updateRate(HotelManagementSystem* head, int room_number, float new_rate) {
    HotelManagementSystem* room = searchRoom(head, room_number);

    if (room) {
        room->rate = new_rate;
    }
}

// Function to delete a room from the hotel management system
void deleteRoom(HotelManagementSystem* head, int room_number) {
    HotelManagementSystem* prev = NULL;
    HotelManagementSystem* current = head;

    while (current) {
        if (current->room_number == room_number) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            free(current);
            current = NULL;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    // Create a hotel management system
    HotelManagementSystem* head = NULL;

    // Insert some nodes into the hotel management system
    insertNode(&head, (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem)));
    insertNode(&head, (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem)));
    insertNode(&head, (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem)));

    // Search for a room in the hotel management system
    HotelManagementSystem* room = searchRoom(head, 101);

    // If the room is found, update its rate
    if (room) {
        updateRate(head, 101, 100.0);
    }

    // Delete a room from the hotel management system
    deleteRoom(head, 102);

    // Print the rooms in the hotel management system
    for (room = head; room; room = room->next) {
        printf("Room number: %d, Rate: %.2f\n", room->room_number, room->rate);
    }

    return 0;
}