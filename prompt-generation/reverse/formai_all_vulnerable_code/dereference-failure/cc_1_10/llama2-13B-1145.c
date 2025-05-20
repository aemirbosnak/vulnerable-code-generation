//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: satisfied
// This is a phone book for the fantastical creatures of the land
// Each creature has a unique number, name, and special ability

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a creature's information
struct creature {
    int id;
    char name[50];
    char ability[50];
};

// Function to create a new creature
struct creature *create_creature(int id, char *name, char *ability) {
    struct creature *new_creature = malloc(sizeof(struct creature));
    new_creature->id = id;
    strcpy(new_creature->name, name);
    strcpy(new_creature->ability, ability);
    return new_creature;
}

// Function to print all the creatures in the phone book
void print_creatures(struct creature *creatures) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d: %s (%s)\n", creatures[i].id, creatures[i].name, creatures[i].ability);
    }
}

// Example usage of the phone book
int main() {
    struct creature *creatures[10];

    // Create some creatures
    creatures[0] = create_creature(1, "Goblin", "Short temper");
    creatures[1] = create_creature(2, "Ogre", "Strong but slow");
    creatures[2] = create_creature(3, "Elf", "Fast and agile");
    creatures[3] = create_creature(4, "Dwarf", "Strong and sturdy");
    creatures[4] = create_creature(5, "Dragon", "Breathes fire");
    creatures[5] = create_creature(6, "Unicorn", "Heals with a touch");
    creatures[6] = create_creature(7, "Mermaid", "Loves to swim");
    creatures[7] = create_creature(8, "Pixie", "Mischievous and quick");
    creatures[8] = create_creature(9, "Gryphon", "Wise and noble");

    // Print all the creatures in the phone book
    print_creatures(creatures);

    return 0;
}