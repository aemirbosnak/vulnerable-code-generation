//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room
{
    int room_number;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room into the hotel
void insert_room(Room* head, int room_number, char status, int occupancy)
{
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->status = status;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (head == NULL)
    {
        head = new_room;
    }
    else
    {
        Room* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_room;
    }
}

// Define a function to find a room in the hotel
Room* find_room(Room* head, int room_number)
{
    Room* current = head;
    while (current)
    {
        if (current->room_number == room_number)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Define a function to check if a room is available
int is_room_available(Room* head, int room_number)
{
    Room* current = find_room(head, room_number);
    if (current)
    {
        return current->status == 'A';
    }
    return 0;
}

// Define a function to book a room
void book_room(Room* head, int room_number, int occupancy)
{
    Room* current = find_room(head, room_number);
    if (current)
    {
        current->occupancy = occupancy;
        current->status = 'O';
    }
}

// Main function
int main()
{
    Room* head = NULL;

    insert_room(head, 101, 'A', 2);
    insert_room(head, 102, 'A', 1);
    insert_room(head, 103, 'A', 3);

    if (is_room_available(head, 102))
    {
        book_room(head, 102, 4);
    }

    if (is_room_available(head, 102))
    {
        book_room(head, 102, 2);
    }

    return 0;
}