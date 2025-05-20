//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room
{
    char name[20];
    struct Room* next;
    int num;
} Room;

void create_room(struct Room** head, char* name, int num)
{
    struct Room* new_room = malloc(sizeof(struct Room));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    new_room->num = num;

    if (*head == NULL)
    {
        *head = new_room;
    }
    else
    {
        (*head)->next = new_room;
    }
}

int main()
{
    struct Room* head = NULL;

    create_room(&head, "The Hallway", 1);
    create_room(&head, "The Kitchen", 2);
    create_room(&head, "The Dining Room", 3);
    create_room(&head, "The Living Room", 4);
    create_room(&head, "The Bedroom", 5);

    printf("You wake up in a mysterious house. You have no recollection of how you got here, only a sense of urgency. You find yourself in ");
    printf("%s. What do you do?", head->name);

    int choice = getchar();

    switch (choice)
    {
        case 1:
            printf("You decide to explore the house. You move towards the ");
            printf("%s.", head->next->name);
            break;
        case 2:
            printf("You try to find a way to escape, but there is no exit. You feel trapped.");
            break;
        default:
            printf("You are confused and scared. You don't know what to do.");
            break;
    }

    return 0;
}