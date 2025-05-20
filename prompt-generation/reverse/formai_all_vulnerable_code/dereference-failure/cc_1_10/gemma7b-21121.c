//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_no;
    char room_type;
    int occupancy;
    struct Room* next;
} Room;

// Function to insert a new room into the hotel list
void insert_room(Room** head) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    printf("Enter room number: ");
    scanf("%d", &new_room->room_no);
    printf("Enter room type (e.g. single, double): ");
    scanf("%s", &new_room->room_type);
    printf("Enter occupancy: ");
    scanf("%d", &new_room->occupancy);
    new_room->next = NULL;

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

// Function to search for a room in the hotel list
Room* search_room(Room* head, int room_no) {
    while (head) {
        if (head->room_no == room_no) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update room occupancy
void update_occupancy(Room* head, int room_no, int new_occupancy) {
    Room* room = search_room(head, room_no);
    if (room) {
        room->occupancy = new_occupancy;
    }
}

// Function to delete a room from the hotel list
void delete_room(Room* head, int room_no) {
    Room* room = search_room(head, room_no);
    if (room) {
        Room* prev = NULL;
        while (room->next) {
            prev = room;
            room = room->next;
        }

        if (prev) {
            prev->next = room->next;
        } else {
            head = room->next;
        }

        free(room);
    }
}

int main() {
    Room* head = NULL;

    // Insert some rooms
    insert_room(&head);
    insert_room(&head);
    insert_room(&head);

    // Search for a room
    Room* room = search_room(head, 1);
    if (room) {
        printf("Room number: %d\n", room->room_no);
        printf("Room type: %s\n", room->room_type);
        printf("Occupancy: %d\n", room->occupancy);
    }

    // Update room occupancy
    update_occupancy(head, 1, 2);

    // Search for the updated room
    room = search_room(head, 1);
    if (room) {
        printf("Room number: %d\n", room->room_no);
        printf("Room type: %s\n", room->room_type);
        printf("Occupancy: %d\n", room->occupancy);
    }

    // Delete a room
    delete_room(head, 2);

    // Search for the deleted room
    room = search_room(head, 2);
    if (room) {
        printf("Error: Room does not exist.\n");
    }

    return 0;
}