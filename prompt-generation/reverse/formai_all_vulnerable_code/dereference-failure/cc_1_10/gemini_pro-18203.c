//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// A declaration of a structure to store a knight's stats
typedef struct knight {
    char *name;
    int strength;
    int agility;
    int intelligence;
    int charisma;
} knight;

// A function to create a new knight
knight *create_knight(char *name, int strength, int agility, int intelligence, int charisma) {
    knight *new_knight = malloc(sizeof(knight));
    new_knight->name = name;
    new_knight->strength = strength;
    new_knight->agility = agility;
    new_knight->intelligence = intelligence;
    new_knight->charisma = charisma;
    return new_knight;
}

// A function to print a knight's stats
void print_knight(knight *knight) {
    printf("Name: %s\n", knight->name);
    printf("Strength: %d\n", knight->strength);
    printf("Agility: %d\n", knight->agility);
    printf("Intelligence: %d\n", knight->intelligence);
    printf("Charisma: %d\n", knight->charisma);
}

// A recursive function to find the strongest knight in a list of knights
knight *find_strongest_knight(knight **knights, int num_knights) {
    if (num_knights == 1) {
        return knights[0];
    } else {
        knight *strongest_knight = find_strongest_knight(knights + 1, num_knights - 1);
        if (strongest_knight->strength > knights[0]->strength) {
            return strongest_knight;
        } else {
            return knights[0];
        }
    }
}

int main() {
    // Create a list of knights
    knight *knights[] = {
        create_knight("Sir Lancelot", 10, 10, 10, 10),
        create_knight("Sir Galahad", 9, 9, 9, 9),
        create_knight("Sir Percival", 8, 8, 8, 8),
        create_knight("Sir Tristan", 7, 7, 7, 7),
        create_knight("Sir Gawain", 6, 6, 6, 6),
    };

    // Find the strongest knight in the list
    knight *strongest_knight = find_strongest_knight(knights, 5);

    // Print the strongest knight's stats
    print_knight(strongest_knight);

    return 0;
}