//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a "creature"
struct creature {
    char name[20];
    int age;
    float height;
    float weight;
};

// Define a function to create a new creature
struct creature* create_creature(char* name, int age, float height, float weight) {
    // Allocate memory for the creature struct using malloc
    struct creature* creature = malloc(sizeof(struct creature));

    // Initialize the creature's name, age, height, and weight
    strcpy(creature->name, name);
    creature->age = age;
    creature->height = height;
    creature->weight = weight;

    // Return the created creature
    return creature;
}

// Define a function to print a creature's information
void print_creature(struct creature* creature) {
    printf("Name: %s\n", creature->name);
    printf("Age: %d\n", creature->age);
    printf("Height: %f meters\n", creature->height);
    printf("Weight: %f kilograms\n", creature->weight);
}

int main() {
    // Create a new creature
    struct creature* creature = create_creature("Bart", 30, 1.8, 70.0);

    // Print the creature's information
    print_creature(creature);

    // Create another new creature
    struct creature* creature2 = create_creature("Lisa", 25, 1.6, 50.0);

    // Print the second creature's information
    print_creature(creature2);

    // Free the memory allocated for the first creature
    free(creature);

    // Print a message to indicate the memory has been freed
    printf("Memory freed! \n");

    // Create a third new creature
    struct creature* creature3 = create_creature("Maggie", 20, 1.4, 40.0);

    // Print the third creature's information
    print_creature(creature3);

    return 0;
}