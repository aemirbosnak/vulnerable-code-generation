//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of planets in the galaxy
#define MAX_PLANETS 100

// Define the structure of a planet
typedef struct Planet {
    char name[20];
    int distance;
    int population;
    struct Planet* next;
} Planet;

// Create a linked list of planets
Planet* create_planet_list() {
    Planet* head = NULL;
    for (int i = 0; i < MAX_PLANETS; i++) {
        head = malloc(sizeof(Planet));
        head->name[0] = 'a' + i;
        head->distance = rand() % 1000;
        head->population = rand() % 100000;
        head->next = NULL;

        if (head) {
            if (head->next) {
                head->next = head;
            } else {
                head->next = head;
            }
        }
    }

    return head;
}

// Traverse the linked list of planets
void traverse_planet_list(Planet* head) {
    while (head) {
        printf("Planet name: %s, distance: %d, population: %d\n", head->name, head->distance, head->population);
        head = head->next;
    }
}

int main() {
    // Create a linked list of planets
    Planet* head = create_planet_list();

    // Traverse the linked list of planets
    traverse_planet_list(head);

    return 0;
}