//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int id;
    float x, y, z;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int id) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->id = id;
    ghost->x = rand() % 1000;
    ghost->y = rand() % 1000;
    ghost->z = rand() % 1000;
    ghost->next = NULL;
    return ghost;
}

void addGhost(Ghost* head, Ghost* ghost) {
    if (head == NULL) {
        head = ghost;
    } else {
        head->next = ghost;
        head = ghost;
    }
}

void haunt(Ghost* head) {
    while (head) {
        printf("Ghost %s has appeared! (x: %.2f, y: %.2f, z: %.2f)\n", head->name, head->x, head->y, head->z);
        sleep(rand() % 5);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));

    Ghost* head = NULL;
    for (int i = 0; i < MAX_GHOULS; i++) {
        addGhost(head, createGhost("Ghost", i));
    }

    haunt(head);

    return 0;
}