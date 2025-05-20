//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 20

typedef struct ShapeShifter {
    char name[MAX_NAME_SIZE];
    int strength;
    int agility;
    int constitution;
    int intelligence;
    struct ShapeShifter* next;
} ShapeShifter;

void insertShifter(ShapeShifter** head, char* name, int strength, int agility, int constitution, int intelligence) {
    ShapeShifter* newShifter = malloc(sizeof(ShapeShifter));
    strcpy(newShifter->name, name);
    newShifter->strength = strength;
    newShifter->agility = agility;
    newShifter->constitution = constitution;
    newShifter->intelligence = intelligence;
    newShifter->next = NULL;

    if (*head == NULL) {
        *head = newShifter;
    } else {
        (*head)->next = newShifter;
    }
}

void printShifter(ShapeShifter* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Strength: %d\n", head->strength);
        printf("Agility: %d\n", head->agility);
        printf("Constitution: %d\n", head->constitution);
        printf("Intelligence: %d\n", head->intelligence);
        printf("\n");
        head = head->next;
    }
}

int main() {
    ShapeShifter* head = NULL;

    insertShifter(&head, "John Doe", 10, 12, 14, 16);
    insertShifter(&head, "Jane Doe", 8, 10, 12, 14);
    insertShifter(&head, "Bruce Wayne", 12, 14, 16, 18);

    printShifter(head);

    return 0;
}