//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUEST_ROOMS 10

typedef struct GuestRoom
{
    char room_number[5];
    char guest_name[50];
    int num_guests;
    struct GuestRoom* next;
} GuestRoom;

GuestRoom* createGuestRoom(char* room_number, char* guest_name, int num_guests)
{
    GuestRoom* new_room = malloc(sizeof(GuestRoom));
    strcpy(new_room->room_number, room_number);
    strcpy(new_room->guest_name, guest_name);
    new_room->num_guests = num_guests;
    new_room->next = NULL;

    return new_room;
}

void addGuestRoom(GuestRoom* head, char* room_number, char* guest_name, int num_guests)
{
    GuestRoom* new_room = createGuestRoom(room_number, guest_name, num_guests);

    if (head == NULL)
    {
        head = new_room;
    }
    else
    {
        GuestRoom* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_room;
    }
}

void printGuestRooms(GuestRoom* head)
{
    GuestRoom* current = head;
    while (current)
    {
        printf("Room Number: %s\n", current->room_number);
        printf("Guest Name: %s\n", current->guest_name);
        printf("Number of Guests: %d\n", current->num_guests);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    GuestRoom* head = NULL;

    addGuestRoom(head, "101", "John Doe", 2);
    addGuestRoom(head, "102", "Jane Doe", 1);
    addGuestRoom(head, "103", "Peter Pan", 3);

    printGuestRooms(head);

    return 0;
}