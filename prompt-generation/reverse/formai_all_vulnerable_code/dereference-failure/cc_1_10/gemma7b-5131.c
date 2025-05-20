//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
    int room_num;
    char *name;
    struct Room *next;
} Room;

Room *createRoom(int room_num, char *name)
{
    Room *newRoom = malloc(sizeof(Room));
    newRoom->room_num = room_num;
    newRoom->name = name;
    newRoom->next = NULL;

    return newRoom;
}

void traverseRooms(Room *room)
{
    while (room)
    {
        printf("You are in %s.\n", room->name);
        printf("You can go to:");

        if (room->next)
        {
            printf(" - %s\n", room->next->name);
        }

        printf("Please enter your choice: ");
        int choice = scanf("%d");

        switch (choice)
        {
            case 1:
                room = room->next;
                traverseRooms(room);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
}

int main()
{
    Room *start = createRoom(1, "The Hall");
    createRoom(2, "The Kitchen");
    createRoom(3, "The Living Room");
    createRoom(4, "The Bedroom");
    createRoom(5, "The Garden");

    traverseRooms(start);

    return 0;
}