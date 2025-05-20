//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure to represent a curious creature
typedef struct {
    char name[50];
    int age;
    float height;
} Creature;

// Function to create a new creature
Creature* create_creature(const char* name, int age, float height) {
    Creature* new_creature = (Creature*)malloc(sizeof(Creature));
    if (new_creature == NULL) {
        fprintf(stderr, "Memory allocation failed for creature creation!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_creature->name, name);
    new_creature->age = age;
    new_creature->height = height;
    return new_creature;
}

// Function to display creature details
void display_creature(Creature* creature) {
    if (creature == NULL) {
        printf("No creature to display!\n");
        return;
    }
    printf("Creature Name: %s\n", creature->name);
    printf("Creature Age: %d\n", creature->age);
    printf("Creature Height: %.2f units\n", creature->height);
}

// Function to free creature memory
void destroy_creature(Creature* creature) {
    if (creature != NULL) {
        free(creature);
        creature = NULL;
    }
}

// Function to create a herd of creatures
Creature** create_herd(int size) {
    Creature** herd = (Creature**)malloc(size * sizeof(Creature*));
    if (herd == NULL) {
        fprintf(stderr, "Memory allocation failed for herd creation!\n");
        exit(EXIT_FAILURE);
    }
    return herd;
}

// Function to add creatures to the herd
void add_creature_to_herd(Creature** herd, int index, const char* name, int age, float height) {
    herd[index] = create_creature(name, age, height);
}

// Function to display herd details
void display_herd(Creature** herd, int size) {
    printf("\n--- Displaying Herd of Creatures ---\n");
    for (int i = 0; i < size; i++) {
        display_creature(herd[i]);
    }
}

// Function to free herd memory
void destroy_herd(Creature** herd, int size) {
    for (int i = 0; i < size; i++) {
        destroy_creature(herd[i]);
    }
    free(herd);
}

int main() {
    // Creating a herd of curious creatures
    int herd_size = 3;
    Creature** curious_herd = create_herd(herd_size);

    add_creature_to_herd(curious_herd, 0, "Fluffy", 2, 1.5);
    add_creature_to_herd(curious_herd, 1, "Gizmo", 3, 0.8);
    add_creature_to_herd(curious_herd, 2, "Sparky", 1, 1.2);

    // Display the creatures in the herd
    display_herd(curious_herd, herd_size);

    // Freeing the allocated memory
    destroy_herd(curious_herd, herd_size);

    printf("\nAll creatures have been sent to a better place!\n");
    return 0;
}