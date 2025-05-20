//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a knight
typedef struct {
    char *name;
    int health;
    int strength;
} Knight;

// A function to create a new knight
Knight *createKnight(char *name, int health, int strength) {
    // Allocate memory for the knight
    Knight *knight = malloc(sizeof(Knight));

    // Copy the name, health, and strength to the knight
    knight->name = strdup(name);
    knight->health = health;
    knight->strength = strength;

    // Return the knight
    return knight;
}

// A function to free the memory allocated for a knight
void destroyKnight(Knight *knight) {
    // Free the name
    free(knight->name);

    // Free the knight
    free(knight);
}

// A function to print the information about a knight
void printKnight(Knight *knight) {
    printf("Name: %s\n", knight->name);
    printf("Health: %d\n", knight->health);
    printf("Strength: %d\n", knight->strength);
}

int main() {
    // Create three knights
    Knight *knight1 = createKnight("Sir Lancelot", 100, 10);
    Knight *knight2 = createKnight("Sir Galahad", 80, 12);
    Knight *knight3 = createKnight("Sir Percival", 90, 11);

    // Print the information about the knights
    printKnight(knight1);
    printKnight(knight2);
    printKnight(knight3);

    // Free the memory allocated for the knights
    destroyKnight(knight1);
    destroyKnight(knight2);
    destroyKnight(knight3);

    return 0;
}