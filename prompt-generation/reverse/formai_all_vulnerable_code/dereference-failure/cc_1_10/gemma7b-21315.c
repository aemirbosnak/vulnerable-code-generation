//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GORE 5
#define MAX_WITCH 3

typedef struct Ghost
{
    char name[20];
    int type;
    int haunt_level;
    int current_location;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int type, int haunt_level, int current_location)
{
    Ghost* ghost = malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->type = type;
    ghost->haunt_level = haunt_level;
    ghost->current_location = current_location;
    ghost->next = NULL;

    return ghost;
}

void haunt_house(Ghost* ghost)
{
    switch (ghost->type)
    {
        case 0:
            // Gore-filled screams
            for (int i = 0; i < MAX_GORE; i++)
            {
                printf("%s! %s! The blood flows freely!\n", ghost->name, ghost->name);
            }
            break;
        case 1:
            // Witch's whispers
            printf("%s's voice echoes through the halls...\n", ghost->name);
            break;
    }
}

int main()
{
    Ghost* head = create_ghost("The Blood Countess", 0, 3, 2);
    haunt_house(head);

    return 0;
}