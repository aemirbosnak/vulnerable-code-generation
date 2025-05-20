//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: artistic
// A Celestial Phone Book
// Connecting You to the Galaxy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 10

// Structures
struct planet {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

// Functions
void add_planet(struct planet *planets, int num_planets, char *name, char *number);
void remove_planet(struct planet *planets, int num_planets, char *name);
void print_planets(struct planet *planets, int num_planets);

// Main Function
int main() {
    // Declare Planets Array
    struct planet planets[10];
    int num_planets = 0;

    // Add Planets
    add_planet(planets, num_planets, "Earth", "555-1234");
    add_planet(planets, num_planets, "Mars", "555-5678");
    add_planet(planets, num_planets, "Jupiter", "555-9012");
    add_planet(planets, num_planets, "Saturn", "555-1111");

    // Remove Planets
    remove_planet(planets, num_planets, "Mars");

    // Print Planets
    print_planets(planets, num_planets);

    return 0;
}

// Functions
void add_planet(struct planet *planets, int num_planets, char *name, char *number) {
    // Check if Name is Empty
    if (strlen(name) == 0) {
        printf("Error: Please enter a non-empty name.\n");
        return;
    }

    // Check if Number is Empty
    if (strlen(number) == 0) {
        printf("Error: Please enter a non-empty number.\n");
        return;
    }

    // Allocate Memory for New Planet
    struct planet *new_planet = (struct planet *) malloc(sizeof(struct planet));
    strcpy(new_planet->name, name);
    strcpy(new_planet->number, number);

    // Add New Planet to Array
    planets[num_planets] = *new_planet;
    num_planets++;

    // Print Message
    printf("Planet %s added with number %s.\n", name, number);
}

void remove_planet(struct planet *planets, int num_planets, char *name) {
    // Find Index of Planet to Remove
    int index = -1;
    for (int i = 0; i < num_planets; i++) {
        if (strcmp(planets[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if Planet was Found
    if (index == -1) {
        printf("Error: Planet %s not found.\n", name);
        return;
    }

    // Remove Planet from Array
    planets[index] = planets[num_planets - 1];
    num_planets--;

    // Print Message
    printf("Planet %s removed.\n", name);
}

void print_planets(struct planet *planets, int num_planets) {
    // Print Planets
    for (int i = 0; i < num_planets; i++) {
        printf("%d. %s (%s)\n", i + 1, planets[i].name, planets[i].number);
    }
}