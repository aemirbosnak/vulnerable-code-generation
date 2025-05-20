//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of planets
#define MAX_PLANETS 10

// Define the structure of a planet
typedef struct Planet {
    char name[50];
    int x, y, z;
    float population;
    struct Planet *next;
} Planet;

// Create a linked list of planets
Planet *create_planet_list() {
    Planet *head = NULL;
    for (int i = 0; i < MAX_PLANETS; i++) {
        head = malloc(sizeof(Planet));
        head->name[0] = 'a' + i;
        head->x = rand() % 1000;
        head->y = rand() % 1000;
        head->z = rand() % 1000;
        head->population = rand() % 1000000;
        head->next = NULL;

        if (head != NULL) {
            if (head->next == NULL) {
                head->next = head;
            } else {
                return head;
            }
        }
    }

    return head;
}

int main() {
    // Create a linked list of planets
    Planet *planets = create_planet_list();

    // Print the name of the first planet
    printf("The name of the first planet is: %s\n", planets->name);

    // Print the coordinates of the first planet
    printf("The coordinates of the first planet are: (%d, %d, %d)\n", planets->x, planets->y, planets->z);

    // Print the population of the first planet
    printf("The population of the first planet is: %d\n", planets->population);

    return 0;
}