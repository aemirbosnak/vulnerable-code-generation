//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int age;
    float haunt_rating;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int age, float haunt_rating) {
    Ghost* newGhost = malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->age = age;
    newGhost->haunt_rating = haunt_rating;
    newGhost->next = NULL;
    return newGhost;
}

void addGhost(Ghost* head, Ghost* newGhost) {
    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
    }
}

void wanderGhosts(Ghost* head) {
    while (head) {
        printf("%s has wandered the halls.\n", head->name);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));
    Ghost* head = NULL;

    // Create a few ghosts
    Ghost* ghost1 = createGhost("Mr. Jones", 25, 8.5);
    Ghost* ghost2 = createGhost("Miss Smith", 30, 7.2);
    Ghost* ghost3 = createGhost("Mr. Brown", 40, 9.0);

    // Add the ghosts to the head
    addGhost(head, ghost1);
    addGhost(head, ghost2);
    addGhost(head, ghost3);

    // Wander the ghosts
    wanderGhosts(head);

    return 0;
}