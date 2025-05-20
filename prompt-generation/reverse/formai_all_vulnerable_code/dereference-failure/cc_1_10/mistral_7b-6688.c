//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creature structure definition
typedef struct {
    char name[50];
    char type[10];
    int magical_power;
} Creature;

// Function to print creature details
void print_creature(Creature creature) {
    printf("Name: %s\n", creature.name);
    printf("Type: %s\n", creature.type);
    printf("Magical Power: %d\n", creature.magical_power);
}

// Function to generate random magical power
int generate_magical_power() {
    return rand() % 100 + 1;
}

// Function to create a new creature
Creature create_creature(char *name, char *type) {
    Creature new_creature;
    strcpy(new_creature.name, name);
    strcpy(new_creature.type, type);
    new_creature.magical_power = generate_magical_power();
    return new_creature;
}

// Function to store a creature in the array
void store_creature(Creature *creatures, int array_size, Creature new_creature) {
    if (array_size > 0) {
        creatures[array_size - 1] = new_creature;
    } else {
        creatures[0] = new_creature;
    }
}

int main() {
    int array_size = 5;
    Creature *creatures = malloc(array_size * sizeof(Creature));

    // Creating new creatures
    Creature unicorn = create_creature("Unicorn", "Mythical");
    Creature dragon = create_creature("Dragon", "Reptile");
    Creature fairy = create_creature("Fairy", "Elemental");

    // Storing creatures in the array
    store_creature(creatures, array_size, unicorn);
    store_creature(creatures, array_size, dragon);
    store_creature(creatures, array_size, fairy);

    // Printing details of all creatures
    for (int i = 0; i < array_size; i++) {
        print_creature(creatures[i]);
    }

    free(creatures);
    return 0;
}