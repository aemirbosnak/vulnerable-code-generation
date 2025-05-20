//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold information about mythical creatures
typedef struct {
    char name[50];
    char type[30];
    int age;
    double power_level;
} Creature;

// Function to create a new creature
Creature* create_creature(const char* name, const char* type, int age, double power_level) {
    Creature* new_creature = (Creature*)malloc(sizeof(Creature));
    if (new_creature == NULL) {
        fprintf(stderr, "Memory allocation failed for new creature.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_creature->name, name);
    strcpy(new_creature->type, type);
    new_creature->age = age;
    new_creature->power_level = power_level;
    
    return new_creature;
}

// Function to display a creature's details
void display_creature(Creature* creature) {
    if (creature == NULL) {
        fprintf(stderr, "Invalid creature reference.\n");
        return;
    }
    printf("Creature Name: %s\n", creature->name);
    printf("Creature Type: %s\n", creature->type);
    printf("Creature Age: %d\n", creature->age);
    printf("Creature Power Level: %.2f\n", creature->power_level);
}

// Function to free the memory allocated for a creature
void free_creature(Creature* creature) {
    free(creature);
}

// Function to create an army of creatures
Creature** create_army(int size) {
    Creature** army = (Creature**)malloc(size * sizeof(Creature*));
    if (army == NULL) {
        fprintf(stderr, "Memory allocation failed for army.\n");
        exit(EXIT_FAILURE);
    }
    return army;
}

// Initialize the army with random creatures
void initialize_army(Creature** army, int size) {
    const char* names[] = {"Dragon", "Unicorn", "Phoenix", "Golem", "Kraken"};
    const char* types[] = {"Fire", "Magic", "Wind", "Earth", "Water"};
    
    for (int i = 0; i < size; i++) {
        int name_index = rand() % 5;
        int type_index = rand() % 5;
        army[i] = create_creature(names[name_index], types[type_index], rand() % 100, (double)(rand() % 1000) / 10);
    }
}

// Display the entire army of creatures
void display_army(Creature** army, int size) {
    for (int i = 0; i < size; i++) {
        display_creature(army[i]);
        printf("\n");
    }
}

// Free the entire army's memory
void free_army(Creature** army, int size) {
    for (int i = 0; i < size; i++) {
        free_creature(army[i]);
    }
    free(army);
}

int main() {
    srand(time(NULL));

    int army_size;
    printf("Enter the number of creatures in the army: ");
    scanf("%d", &army_size);

    // Create and initialize the army
    Creature** army = create_army(army_size);
    initialize_army(army, army_size);

    // Display the army
    printf("\n--- The Army of Mythical Creatures ---\n");
    display_army(army, army_size);

    // Free the army memory before exiting
    free_army(army, army_size);
    
    printf("\nAll creatures have been freed successfully!\n");
    return 0;
}