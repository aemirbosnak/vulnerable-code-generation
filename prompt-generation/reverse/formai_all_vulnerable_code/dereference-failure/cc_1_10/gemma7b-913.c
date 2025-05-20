//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a hotel room
typedef struct Room {
    char name[20];
    int number;
    float rate;
    struct Room* next;
} Room;

// Define the function to insert a room into the linked list
void insertRoom(Room** head, char* name, int number, float rate) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->rate = rate;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Define the function to search for a room by name
Room* searchRoomByName(Room* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Define the function to update the rate of a room
void updateRoomRate(Room* head, char* name, float newRate) {
    Room* room = searchRoomByName(head, name);

    if (room) {
        room->rate = newRate;
    }
}

// Define the function to delete a room from the linked list
void deleteRoom(Room** head, char* name) {
    Room* previous = NULL;
    Room* current = *head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    Room* head = NULL;

    // Insert some rooms
    insertRoom(&head, "Room 1", 101, 50.0);
    insertRoom(&head, "Room 2", 102, 60.0);
    insertRoom(&head, "Room 3", 103, 70.0);

    // Search for a room by name
    Room* room = searchRoomByName(head, "Room 2");

    // Update the rate of a room
    updateRoomRate(head, "Room 2", 80.0);

    // Delete a room
    deleteRoom(&head, "Room 3");

    // Print the rooms
    for (room = head; room; room = room->next) {
        printf("Name: %s, Number: %d, Rate: %.2f\n", room->name, room->number, room->rate);
    }

    return 0;
}