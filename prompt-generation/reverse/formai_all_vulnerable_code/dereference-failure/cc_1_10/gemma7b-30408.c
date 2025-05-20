//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost Ghost;
struct Ghost
{
    char name[20];
    int room_num;
    int strength;
    Ghost *next;
};

Ghost *ghosts = NULL;

void add_ghost(char *name, int room_num, int strength)
{
    Ghost *new_ghost = malloc(sizeof(Ghost));
    strcpy(new_ghost->name, name);
    new_ghost->room_num = room_num;
    new_ghost->strength = strength;
    new_ghost->next = ghosts;
    ghosts = new_ghost;
}

void haunt_house()
{
    time_t t = time(NULL);
    srand(t);

    Ghost *current_ghost = ghosts;
    while (current_ghost)
    {
        int room_num = current_ghost->room_num;
        int strength = current_ghost->strength;

        if (rand() % strength == 0)
        {
            printf("A chilling scream echoes through the halls of the Cybernetic Manor...\n");
            printf("The bloodstained blade of %s has been found in room %d.\n", current_ghost->name, room_num);
        }
    }
}

int main()
{
    add_ghost("Cybernetic Jack", 3, 8);
    add_ghost("Mutilated Mary", 4, 6);
    add_ghost("Corpse Colin", 2, 7);

    haunt_house();

    return 0;
}