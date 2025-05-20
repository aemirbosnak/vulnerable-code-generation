//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a "creature"
struct creature {
    char name[20];
    int age;
    float height;
};

// Define a function to create a new creature
struct creature *create_creature(char *name, int age, float height) {
    // Allocate memory for the creature struct using malloc
    struct creature *creature = malloc(sizeof(struct creature));

    // Set the creature's name, age, and height
    strcpy(creature->name, name);
    creature->age = age;
    creature->height = height;

    // Return the created creature
    return creature;
}

// Define a function to print a creature
void print_creature(struct creature *creature) {
    printf("Name: %s\nAge: %d\nHeight: %f\n", creature->name, creature->age, creature->height);
}

int main() {
    // Create a new creature
    struct creature *creature = create_creature("Alice", 25, 165.5);

    // Print the creature
    print_creature(creature);

    // Create another new creature
    struct creature *creature2 = create_creature("Bob", 30, 180.5);

    // Print the second creature
    print_creature(creature2);

    // Free the memory allocated for the first creature
    free(creature);

    // Print the third creature (which is the same as the second creature)
    print_creature(creature2);

    return 0;
}