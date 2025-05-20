//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int type;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int room_num, int type) {
    Ghost* newGhost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->room_num = room_num;
    newGhost->type = type;
    newGhost->next = NULL;
    return newGhost;
}

void addGhost(Ghost* head, Ghost* newGhost) {
    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
        head = newGhost;
    }
}

void haunt(Ghost* head) {
    while (head) {
        printf("The ghostly figure of %s has entered the room.\n", head->name);
        switch (head->type) {
            case 0:
                printf("They are a malevolent spirit, ready to cause harm.\n");
                break;
            case 1:
                printf("They are a tormented spirit, seeking revenge.\n");
                break;
            case 2:
                printf("They are a mischievous spirit, playing tricks on you.\n");
                break;
            default:
                printf("They are an enigmatic spirit, beyond comprehension.\n");
                break;
        }
        printf("The spirit moves towards you...\n");
        sleep(1);
        printf("You feel a cold wind blowing on your skin.\n");
        sleep(1);
        printf("The spirit's voice echoes in your head.\n");
        sleep(1);
        printf("Suddenly, you wake up...\n");
        sleep(2);
    }
}

int main() {
    Ghost* head = NULL;

    // Create a few ghosts
    Ghost* ghost1 = createGhost("John Doe", 1, 0);
    Ghost* ghost2 = createGhost("Jane Doe", 2, 1);
    Ghost* ghost3 = createGhost("Jack Doe", 3, 2);

    // Add the ghosts to the list
    addGhost(head, ghost1);
    addGhost(head, ghost2);
    addGhost(head, ghost3);

    // Haunt the house
    haunt(head);

    return 0;
}