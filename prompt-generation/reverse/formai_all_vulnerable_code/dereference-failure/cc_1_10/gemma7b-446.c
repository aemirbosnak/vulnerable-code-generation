//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_NUM 10
#define MAX_GUEST 2

typedef struct Room
{
    int number;
    char status;
    char guest_name[MAX_GUEST];
    struct Room* next;
} Room;

Room* create_room(int number)
{
    Room* new_room = malloc(sizeof(Room));
    new_room->number = number;
    new_room->status = 'O';
    new_room->guest_name[0] = '\0';
    new_room->next = NULL;
    return new_room;
}

void check_in(Room* room, char* guest_name)
{
    if (room->status == 'O')
    {
        strcpy(room->guest_name, guest_name);
        room->status = 'B';
    }
    else
    {
        printf("Room is not available\n");
    }
}

void check_out(Room* room)
{
    if (room->status == 'B')
    {
        room->status = 'O';
        room->guest_name[0] = '\0';
    }
    else
    {
        printf("Room is not occupied\n");
    }
}

int main()
{
    Room* head = NULL;

    for (int i = 0; i < ROOM_NUM; i++)
    {
        head = create_room(i + 1);
        head = head->next;
    }

    check_in(head, "John Doe");
    check_in(head, "Jane Doe");

    check_out(head);
    check_out(head);

    return 0;
}