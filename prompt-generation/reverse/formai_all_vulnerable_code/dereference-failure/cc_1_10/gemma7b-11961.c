//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 5

typedef struct Room
{
    char name[20];
    struct Room* next;
    int is_visited;
    int is_haunted;
    int ghosts_num;
} Room;

Room* create_room(char* name, int is_haunted, int ghosts_num)
{
    Room* new_room = (Room*)malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    new_room->is_visited = 0;
    new_room->is_haunted = is_haunted;
    new_room->ghosts_num = ghosts_num;
    return new_room;
}

void traverse_rooms(Room* current_room)
{
    if (current_room)
    {
        printf("%s\n", current_room->name);

        if (current_room->next)
        {
            traverse_rooms(current_room->next);
        }
    }
}

int main()
{
    srand(time(NULL));

    Room* first_room = create_room("Entrance Hall", 1, 3);
    Room* second_room = create_room("Living Room", 0, 1);
    Room* third_room = create_room("Dining Room", 1, 2);
    Room* fourth_room = create_room("Kitchen", 0, 0);
    Room* fifth_room = create_room("Master Bedroom", 1, 4);

    first_room->next = second_room;
    second_room->next = third_room;
    third_room->next = fourth_room;
    fourth_room->next = fifth_room;

    traverse_rooms(first_room);

    return 0;
}