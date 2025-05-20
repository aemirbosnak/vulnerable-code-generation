//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CREATURE_COUNT 2
#define NAME_MAX_LENGTH 50

// Structure defining a magical creature
typedef struct {
    char name[NAME_MAX_LENGTH];
    int powerLevel;
} Creature;

// Function prototypes
Creature* createCreature(const char* name, int powerLevel);
void displayCreatures(Creature* creatures, int count);
void addCreature(Creature** creatures, int* count, const char* name, int powerLevel);
void removeCreature(Creature** creatures, int* count, const char* name);
void freeCreatures(Creature* creatures, int count);

int main() {
    int creatureCount = INITIAL_CREATURE_COUNT;
    Creature* creatures = (Creature*)malloc(creatureCount * sizeof(Creature));

    if (creatures == NULL) {
        fprintf(stderr, "Magic failure! Unable to allocate memory for creatures!\n");
        return EXIT_FAILURE;
    }

    // Initialize some magical creatures.
    strcpy(creatures[0].name, "Fluffy");
    creatures[0].powerLevel = 5;

    strcpy(creatures[1].name, "Sparkle");
    creatures[1].powerLevel = 7;

    printf("Welcome to the Magical Creature Sanctuary!\n");
    displayCreatures(creatures, creatureCount);

    // Adding a new magical creature
    addCreature(&creatures, &creatureCount, "Glimmer", 10);
    displayCreatures(creatures, creatureCount);

    // Adding another magical creature
    addCreature(&creatures, &creatureCount, "Shadow", 6);
    displayCreatures(creatures, creatureCount);

    // Remove a creature
    printf("\nOh no! It's time for Fluffy to go!\n");
    removeCreature(&creatures, &creatureCount, "Fluffy");
    displayCreatures(creatures, creatureCount);

    // Free the memory allocated for creatures
    freeCreatures(creatures, creatureCount);
    printf("All creatures have safely returned to the magical realm. Bye bye!\n");

    return EXIT_SUCCESS;
}

// Create a new creature
Creature* createCreature(const char* name, int powerLevel) {
    Creature* newCreature = (Creature*)malloc(sizeof(Creature));
    if (newCreature == NULL) {
        fprintf(stderr, "Magic failure! Unable to create creature!\n");
        return NULL;
    }
    strncpy(newCreature->name, name, NAME_MAX_LENGTH);
    newCreature->powerLevel = powerLevel;
    return newCreature;
}

// Display all magical creatures
void displayCreatures(Creature* creatures, int count) {
    printf("\n🦄 Magical Creatures in the Sanctuary! 🦄\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Power Level: %d\n", creatures[i].name, creatures[i].powerLevel);
    }
    printf("\n");
}

// Add a new creature to the array
void addCreature(Creature** creatures, int* count, const char* name, int powerLevel) {
    *count += 1;
    *creatures = (Creature*)realloc(*creatures, (*count) * sizeof(Creature));
    
    if (*creatures == NULL) {
        fprintf(stderr, "Magic failure! Unable to resize creatures array!\n");
        return;
    }

    strcpy((*creatures)[*count - 1].name, name);
    (*creatures)[*count - 1].powerLevel = powerLevel;
    
    printf("✨ A new creature has entered the sanctuary: %s! ✨\n", name);
}

// Remove a creature by name from the array
void removeCreature(Creature** creatures, int* count, const char* name) {
    int index = -1;

    for (int i = 0; i < *count; i++) {
        if (strcmp((*creatures)[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Creature named '%s' not found!\n", name);
        return;
    }

    printf("🦇 Creature '%s' has left the sanctuary! 🦇\n", name);
    
    // Shift creatures down
    for (int i = index; i < *count - 1; i++) {
        (*creatures)[i] = (*creatures)[i + 1];
    }
    
    *count -= 1;
    *creatures = (Creature*)realloc(*creatures, (*count) * sizeof(Creature));
}

// Free allocated memory for creatures
void freeCreatures(Creature* creatures, int count) {
    free(creatures);
}