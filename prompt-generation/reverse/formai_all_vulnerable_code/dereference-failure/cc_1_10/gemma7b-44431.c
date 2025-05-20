//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROOM_NUM 5
#define GHOST_NUM 3

typedef struct Room
{
    char name[20];
    int num_ghosts;
    struct Room* next;
} Room;

typedef struct Ghost
{
    char name[20];
    int room_num;
    struct Ghost* next;
} Ghost;

void generate_rooms(Room** head)
{
    int i;
    for(i = 0; i < ROOM_NUM; i++)
    {
        Room* new_room = malloc(sizeof(Room));
        snprintf(new_room->name, 20, "Room %d", i + 1);
        new_room->num_ghosts = rand() % GHOST_NUM;
        new_room->next = *head;
        *head = new_room;
    }
}

void generate_ghosts(Ghost** head)
{
    int i;
    for(i = 0; i < GHOST_NUM; i++)
    {
        Ghost* new_ghost = malloc(sizeof(Ghost));
        snprintf(new_ghost->name, 20, "Ghost %d", i + 1);
        new_ghost->room_num = rand() % ROOM_NUM + 1;
        new_ghost->next = *head;
        *head = new_ghost;
    }
}

void haunt_house(Room* head, Ghost* head2)
{
    Room* current_room = head;
    Ghost* current_ghost = head2;

    while(current_room && current_ghost)
    {
        if(current_room->num_ghosts > 0)
        {
            printf("You are in %s.\n", current_room->name);
            printf("Suddenly, you hear a noise.\n");
            printf("You feel a cold wind blowing on your skin.\n");
            current_room->num_ghosts--;
        }

        current_room = current_room->next;
        current_ghost = current_ghost->next;
    }
}

int main()
{
    Room* head = NULL;
    Ghost* head2 = NULL;

    generate_rooms(&head);
    generate_ghosts(&head2);
    haunt_house(head, head2);

    return 0;
}