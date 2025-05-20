//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

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
        head = newGhost;
    }
}

void hauntHouse(Ghost* head) {
    srand(time(NULL));
    int numGhosts = rand() % MAX_GHOULS + 1;
    for (int i = 0; i < numGhosts; i++) {
        printf("Ghostly presence detected! (%s)\n", head->name);
        head = head->next;
    }
}

int main() {
    Ghost* head = createGhost("Mr. Bartholomew", 25, 8.5);
    addGhost(head, createGhost("Ms. Emily", 32, 7.2));
    addGhost(head, createGhost("Mr. Henderson", 40, 9.1));
    addGhost(head, createGhost("Ms. Jackson", 22, 8.2));
    addGhost(head, createGhost("Mr. Jones", 38, 7.6));

    hauntHouse(head);

    return 0;
}