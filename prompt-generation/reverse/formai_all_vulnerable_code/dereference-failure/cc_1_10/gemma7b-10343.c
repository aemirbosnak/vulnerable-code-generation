//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store room information
typedef struct Room
{
    int room_number;
    char room_type[20];
    int available_beds;
    int current_occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room into the linked list
void insert_room(Room** head, int room_number, char* room_type, int available_beds, int current_occupancy)
{
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    strcpy(new_room->room_type, room_type);
    new_room->available_beds = available_beds;
    new_room->current_occupancy = current_occupancy;
    new_room->next = NULL;

    if (*head == NULL)
    {
        *head = new_room;
    }
    else
    {
        (*head)->next = new_room;
    }
}

// Define a function to search for a room
Room* search_room(Room* head, int room_number)
{
    while (head)
    {
        if (head->room_number == room_number)
        {
            return head;
        }
        else
        {
            head = head->next;
        }
    }

    return NULL;
}

// Define a function to update room occupancy
void update_room_occupancy(Room* head, int room_number, int new_occupancy)
{
    Room* room = search_room(head, room_number);

    if (room)
    {
        room->current_occupancy = new_occupancy;
    }
}

// Define a function to list all rooms
void list_rooms(Room* head)
{
    while (head)
    {
        printf("Room Number: %d\n", head->room_number);
        printf("Room Type: %s\n", head->room_type);
        printf("Available Beds: %d\n", head->available_beds);
        printf("Current Occupancy: %d\n", head->current_occupancy);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Room* head = NULL;

    // Insert some rooms
    insert_room(&head, 101, "Standard", 2, 0);
    insert_room(&head, 102, "Suite", 4, 2);
    insert_room(&head, 103, "Luxury", 6, 1);

    // List all rooms
    list_rooms(head);

    // Update room occupancy
    update_room_occupancy(head, 102, 4);

    // List all rooms again
    list_rooms(head);

    return 0;
}