//Gemma-7B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20

typedef struct Knight {
    char name[MAX_NAME_LENGTH];
    int strength;
    int bravery;
    struct Knight *next;
} Knight;

int main() {
    Knight *head = NULL;
    Knight *current = NULL;

    // Allocate memory for the first knight
    head = malloc(sizeof(Knight));
    current = head;

    // Set the knight's name, strength, and bravery
    strcpy(current->name, "Sir Robin Hood");
    current->strength = 10;
    current->bravery = 8;

    // Allocate memory for the second knight
    current->next = malloc(sizeof(Knight));
    current = current->next;

    // Set the knight's name, strength, and bravery
    strcpy(current->name, "Sir William Wallace");
    current->strength = 8;
    current->bravery = 9;

    // Print the knights' names and strengths
    current = head;
    while (current) {
        printf("%s has a strength of %d.\n", current->name, current->strength);
        current = current->next;
    }

    // Free the memory allocated for the knights
    current = head;
    while (current) {
        Knight *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}