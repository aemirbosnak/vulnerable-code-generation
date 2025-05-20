//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int spirit_level;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int room_num, int spirit_level) {
    Ghost* newGhost = malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->room_num = room_num;
    newGhost->spirit_level = spirit_level;
    newGhost->next = NULL;
    return newGhost;
}

void addGhost(Ghost* head, char* name, int room_num, int spirit_level) {
    Ghost* newGhost = createGhost(name, room_num, spirit_level);
    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
    }
}

void hauntHouse(Ghost* head) {
    srand(time(NULL));
    for (Ghost* currentGhost = head; currentGhost; currentGhost = currentGhost->next) {
        int haunt_chance = rand() % 100;
        if (haunt_chance <= currentGhost->spirit_level) {
            printf("The ghostly voice of %s echoes through the halls...\n", currentGhost->name);
            printf("The hairs on your neck prickle as you feel a cold hand brush against you...\n");
            printf("You hear footsteps approaching... Is it the ghost?\n");
            printf("Suddenly, a door slams shut...\n");
            printf("You are trapped in the haunted house...\n");
            sleep(1);
        }
    }
}

int main() {
    Ghost* head = NULL;
    addGhost(head, "John Doe", 1, 80);
    addGhost(head, "Mary Smith", 2, 60);
    addGhost(head, "Peter Jones", 3, 40);
    hauntHouse(head);
    return 0;
}