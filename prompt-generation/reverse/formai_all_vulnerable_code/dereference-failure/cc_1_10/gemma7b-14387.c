//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost
{
    char name[20];
    int room_num;
    int activity_level;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int room_num, int activity_level)
{
    Ghost* newGhost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->room_num = room_num;
    newGhost->activity_level = activity_level;
    newGhost->next = NULL;

    return newGhost;
}

void addGhost(Ghost* head, char* name, int room_num, int activity_level)
{
    Ghost* newGhost = createGhost(name, room_num, activity_level);
    if (head == NULL)
    {
        head = newGhost;
    }
    else
    {
        head->next = newGhost;
    }
}

void haunt(Ghost* head)
{
    while (head)
    {
        printf("Ghost name: %s\n", head->name);
        printf("Room number: %d\n", head->room_num);
        printf("Activity level: %d\n", head->activity_level);
        printf("\n");

        head = head->next;
    }
}

int main()
{
    Ghost* head = NULL;

    addGhost(head, "Jack", 1, 3);
    addGhost(head, "Mary", 2, 2);
    addGhost(head, "Peter", 3, 4);
    addGhost(head, "Alice", 4, 1);
    addGhost(head, "Bob", 5, 2);

    haunt(head);

    return 0;
}