//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

typedef struct room {
    char name[20];
    struct room *next;
} room_t;

room_t *create_room(char *name)
{
    room_t *new_room = malloc(sizeof(room_t));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    return new_room;
}

void connect_rooms(room_t *room1, room_t *room2)
{
    room1->next = room2;
}

int main()
{
    room_t *rooms = NULL;
    rooms = create_room("The Great Hall");
    connect_rooms(rooms, create_room("The Dining Hall"));
    connect_rooms(rooms, create_room("The Library"));
    connect_rooms(rooms, create_room("The Bedroom"));
    connect_rooms(rooms, create_room("The Kitchen"));

    printf("You are in the %s.\n", rooms->name);

    char direction;
    printf("Enter a direction: ");
    scanf("%c", &direction);

    switch (direction)
    {
        case 'n':
            printf("You went north to the %s.\n", rooms->next->name);
            break;
        case 's':
            printf("You went south to the %s.\n", rooms->next->next->name);
            break;
        case 'e':
            printf("You went east to the %s.\n", rooms->next->next->next->name);
            break;
        case 'w':
            printf("You went west to the %s.\n", rooms->next->next->next->next->name);
            break;
        default:
            printf("Invalid direction.\n");
    }

    return 0;
}