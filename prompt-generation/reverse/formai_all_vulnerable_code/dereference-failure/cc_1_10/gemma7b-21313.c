//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room
{
    int room_no;
    char status;
    int occupancy;
    struct Room *next;
} Room;

// Define a function to insert a room into the linked list
void insertRoom(Room **head, int room_no, char status, int occupancy)
{
    Room *newRoom = (Room *)malloc(sizeof(Room));
    newRoom->room_no = room_no;
    newRoom->status = status;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (*head == NULL)
    {
        *head = newRoom;
    }
    else
    {
        (*head)->next = newRoom;
    }
}

// Define a function to search for a room
Room *searchRoom(Room *head, int room_no)
{
    while (head)
    {
        if (head->room_no == room_no)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Define a function to update the status of a room
void updateRoomStatus(Room *head, int room_no, char new_status)
{
    Room *room = searchRoom(head, room_no);

    if (room)
    {
        room->status = new_status;
    }
}

// Define a function to check if a room is occupied
int isRoomOccupied(Room *head, int room_no)
{
    Room *room = searchRoom(head, room_no);

    if (room)
    {
        return room->occupancy;
    }

    return -1;
}

int main()
{
    // Create a linked list of rooms
    Room *head = NULL;

    // Insert some rooms
    insertRoom(&head, 101, 'O', 2);
    insertRoom(&head, 102, 'A', 1);
    insertRoom(&head, 103, 'O', 3);

    // Search for a room
    Room *room = searchRoom(head, 102);

    // Update the status of a room
    updateRoomStatus(head, 101, 'A');

    // Check if a room is occupied
    int occupancy = isRoomOccupied(head, 101);

    // Print the occupancy of the room
    printf("Occupancy of room %d: %d", 101, occupancy);

    return 0;
}