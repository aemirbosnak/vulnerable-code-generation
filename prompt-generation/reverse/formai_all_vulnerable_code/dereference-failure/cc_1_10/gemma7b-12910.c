//Gemma-7B DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Knight {
    char name[20];
    int strength, agility, wisdom;
    struct Knight *next;
} Knight;

Knight *createKnight(char *name, int strength, int agility, int wisdom) {
    Knight *knight = malloc(sizeof(Knight));
    strcpy(knight->name, name);
    knight->strength = strength;
    knight->agility = agility;
    knight->wisdom = wisdom;
    knight->next = NULL;
    return knight;
}

void addKnight(Knight *head, Knight *newKnight) {
    if (head == NULL) {
        head = newKnight;
    } else {
        head->next = newKnight;
        head = newKnight;
    }
}

int main() {
    Knight *head = NULL;
    Knight *newKnight;

    // Create a few knights
    newKnight = createKnight("Sir Robin", 15, 12, 10);
    addKnight(head, newKnight);

    newKnight = createKnight("Sir Lancelot", 12, 15, 8);
    addKnight(head, newKnight);

    newKnight = createKnight("Sir Gareth", 10, 13, 9);
    addKnight(head, newKnight);

    // Print the knights
    for (Knight *knight = head; knight; knight = knight->next) {
        printf("%s: Strength %d, Agility %d, Wisdom %d\n", knight->name, knight->strength, knight->agility, knight->wisdom);
    }

    return 0;
}