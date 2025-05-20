//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GHOULS 5

typedef struct Ghost Ghost;

struct Ghost {
    char name[20];
    int age;
    float haunt_rating;
    Ghost* next;
};

Ghost* createGhost(char* name, int age, float haunt_rating) {
    Ghost* newGhost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->age = age;
    newGhost->haunt_rating = haunt_rating;
    newGhost->next = NULL;
    return newGhost;
}

void addGhost(Ghost* head, char* name, int age, float haunt_rating) {
    Ghost* newGhost = createGhost(name, age, haunt_rating);
    if (head == NULL) {
        head = newGhost;
    } else {
        newGhost->next = head;
        head = newGhost;
    }
}

void haunt(Ghost* head) {
    while (head) {
        printf("The spirit of %s haunts you...\n", head->name);
        printf("You feel a cold wind blowing through your hair...\n");
        printf("The hairs on your neck stand on end...\n");
        printf("You hear whispers in your ear...\n");
        printf("Your blood turns to ice...\n");
        sleep(1);
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;
    addGhost(head, "John", 25, 4.5);
    addGhost(head, "Mary", 30, 3.2);
    addGhost(head, "Bob", 40, 2.8);
    addGhost(head, "Alice", 50, 4.2);

    haunt(head);

    return 0;
}