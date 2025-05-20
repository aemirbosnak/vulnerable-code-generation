//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int age;
    float haunt_rating;
    int location_x;
    int location_y;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int age, float haunt_rating, int location_x, int location_y) {
    Ghost* newGhost = malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->age = age;
    newGhost->haunt_rating = haunt_rating;
    newGhost->location_x = location_x;
    newGhost->location_y = location_y;
    newGhost->next = NULL;
    return newGhost;
}

void addGhost(Ghost* head, char* name, int age, float haunt_rating, int location_x, int location_y) {
    Ghost* newGhost = createGhost(name, age, haunt_rating, location_x, location_y);
    if (head == NULL) {
        head = newGhost;
    } else {
        newGhost->next = head;
        head = newGhost;
    }
}

void displayGhosts(Ghost* head) {
    Ghost* currentGhost = head;
    while (currentGhost) {
        printf("%s, %d, %.2f, (%d, %d)\n", currentGhost->name, currentGhost->age, currentGhost->haunt_rating, currentGhost->location_x, currentGhost->location_y);
        currentGhost = currentGhost->next;
    }
}

int main() {
    Ghost* head = NULL;
    addGhost(head, "Mary", 25, 8.5, 10, 10);
    addGhost(head, "John", 30, 7.2, 12, 12);
    addGhost(head, "Alice", 18, 9.1, 14, 14);

    displayGhosts(head);

    return 0;
}