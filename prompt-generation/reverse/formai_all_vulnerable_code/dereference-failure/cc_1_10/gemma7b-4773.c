//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void manage_hotel(int floor, int room_num, char **rooms)
{
    int room_status;
    char guest_name[20];

    printf("Floor: %d, Room Number: %d\n", floor, room_num);

    // Get the room status
    room_status = rooms[floor][room_num] - '0';

    // If the room is occupied, get the guest name
    if (room_status)
    {
        printf("Guest Name: %s\n", rooms[floor][room_num + 1]);
    }
    else
    {
        printf("The room is vacant.\n");
    }

    // Recursively manage the next floor or room number
    if (floor < 5)
    {
        manage_hotel(floor + 1, room_num, rooms);
    }
    else
    {
        return;
    }
}

int main()
{
    char **rooms = (char **)malloc(6 * sizeof(char *));

    for (int i = 0; i < 6; i++)
    {
        rooms[i] = (char *)malloc(10 * sizeof(char));
    }

    // Initialize the rooms
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            rooms[i][j] = '0';
        }
    }

    // Occupy a few rooms
    rooms[2][3] = '1';
    rooms[3][5] = '1';
    rooms[4][2] = '1';

    // Manage the hotel
    manage_hotel(1, 1, rooms);

    return 0;
}