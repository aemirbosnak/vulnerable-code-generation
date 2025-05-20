//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int activity;
    struct Ghost* next;
} Ghost;

Ghost* CreateGhost(char* name, int room, int activity) {
    Ghost* newGhost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->room = room;
    newGhost->activity = activity;
    newGhost->next = NULL;
    return newGhost;
}

void AddGhost(Ghost* head, char* name, int room, int activity) {
    Ghost* newGhost = CreateGhost(name, room, activity);
    if (head == NULL) {
        head = newGhost;
    } else {
        newGhost->next = head;
        head = newGhost;
    }
}

void HauntedHouse(Ghost* head) {
    srand(time(NULL));
    int randomRoom = rand() % MAX_GHOSTS;
    Ghost* currentGhost = head;

    while (currentGhost) {
        if (currentGhost->room == randomRoom) {
            switch (currentGhost->activity) {
                case 0:
                    printf("%s is whispering secrets...\n", currentGhost->name);
                    break;
                case 1:
                    printf("%s is moving slowly...\n", currentGhost->name);
                    break;
                case 2:
                    printf("%s is laughing...\n", currentGhost->name);
                    break;
                case 3:
                    printf("%s is crying...\n", currentGhost->name);
                    break;
                case 4:
                    printf("%s is teleporting...\n", currentGhost->name);
                    break;
            }
        }
        currentGhost = currentGhost->next;
    }
}

int main() {
    Ghost* head = NULL;
    AddGhost(head, "John Doe", 1, 0);
    AddGhost(head, "Mary Smith", 2, 1);
    AddGhost(head, "Peter Pan", 3, 2);
    AddGhost(head, "The Phantom", 4, 3);
    AddGhost(head, "The Witch", 5, 4);

    HauntedHouse(head);

    return 0;
}