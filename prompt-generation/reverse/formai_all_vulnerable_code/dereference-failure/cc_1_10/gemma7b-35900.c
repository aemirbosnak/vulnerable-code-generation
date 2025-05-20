//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room
{
    int room_no;
    char status;
    char occupancy;
    int price;
} Room;

// Define a function to search for a room
Room* search_room(int room_no)
{
    // Create an array of rooms
    Room rooms[] = {
        {101, 'O', 'A', 1000},
        {102, 'A', 'B', 1200},
        {103, 'A', 'C', 1400},
        {104, 'O', 'D', 1600}
    };

    // Iterate over the array of rooms to find the room with the specified room number
    for (int i = 0; i < 4; i++)
    {
        if (rooms[i].room_no == room_no)
        {
            return &rooms[i];
        }
    }

    // Return NULL if no room is found
    return NULL;
}

// Define a function to book a room
void book_room(Room* room)
{
    // Update the room status to "B" (booked)
    room->status = 'B';

    // Update the room occupancy to the guest's name
    room->occupancy = 'G';

    // Print a confirmation message
    printf("Your booking for room %d has been confirmed.\n", room->room_no);
}

int main()
{
    // Get the room number from the user
    int room_no;
    printf("Enter the room number: ");
    scanf("%d", &room_no);

    // Search for the room
    Room* room = search_room(room_no);

    // If the room is found, book it
    if (room)
    {
        book_room(room);
    }
    else
    {
        printf("Room not found.\n");
    }

    return 0;
}