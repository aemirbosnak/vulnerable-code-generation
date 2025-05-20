//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NUM 5

typedef struct Room
{
    char name[20];
    struct Room* next;
    struct Room* prev;
    int room_num;
    char description[100];
} Room;

Room* create_room(char* name, int room_num, char* description)
{
    Room* new_room = (Room*)malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->room_num = room_num;
    strcpy(new_room->description, description);
    new_room->next = NULL;
    new_room->prev = NULL;
    return new_room;
}

void connect_rooms(Room* room1, Room* room2)
{
    room1->next = room2;
    room2->prev = room1;
}

void play_adventure(Room* start_room)
{
    Room* current_room = start_room;
    char input[20];

    printf("You are in the %s.\n", current_room->name);
    printf("%s\n", current_room->description);

    printf("What do you want to do? (look, go, interact): ");
    scanf("%s", input);

    if (strcmp(input, "look") == 0)
    {
        printf("You see:\n");
        printf("%s\n", current_room->description);
    }
    else if (strcmp(input, "go") == 0)
    {
        char direction[20];
        printf("In which direction do you want to go? (north, south, east, west): ");
        scanf("%s", direction);

        if (strcmp(direction, "north") == 0)
        {
            if (current_room->next)
            {
                current_room = current_room->next;
                play_adventure(current_room);
            }
            else
            {
                printf("There is no north exit.\n");
            }
        }
        else if (strcmp(direction, "south") == 0)
        {
            if (current_room->prev)
            {
                current_room = current_room->prev;
                play_adventure(current_room);
            }
            else
            {
                printf("There is no south exit.\n");
            }
        }
        else if (strcmp(direction, "east") == 0)
        {
            if (current_room->next)
            {
                current_room = current_room->next;
                play_adventure(current_room);
            }
            else
            {
                printf("There is no east exit.\n");
            }
        }
        else if (strcmp(direction, "west") == 0)
        {
            if (current_room->prev)
            {
                current_room = current_room->prev;
                play_adventure(current_room);
            }
            else
            {
                printf("There is no west exit.\n");
            }
        }
    }
    else if (strcmp(input, "interact") == 0)
    {
        // Interact with objects in the room
    }

    play_adventure(current_room);
}

int main()
{
    Room* start_room = create_room("The Hallway", 1, "You are in a long hallway. There is a door at the end of the hallway.");

    Room* room2 = create_room("The Bedroom", 2, "You are in a bedroom. There is a bed, a dresser, and a window.");

    connect_rooms(start_room, room2);

    play_adventure(start_room);

    return 0;
}