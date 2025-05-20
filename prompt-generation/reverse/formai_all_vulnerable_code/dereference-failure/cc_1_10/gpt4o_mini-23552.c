//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Creature {
    char name[30];
    char power[50];
    struct Creature *next;
} Creature;

Creature* createCreature(const char *name, const char *power) {
    Creature *newCreature = (Creature *)malloc(sizeof(Creature));
    strcpy(newCreature->name, name);
    strcpy(newCreature->power, power);
    newCreature->next = NULL;
    return newCreature;
}

void addCreature(Creature **head, const char *name, const char *power) {
    Creature *newCreature = createCreature(name, power);
    newCreature->next = *head;
    *head = newCreature;
    printf("A mystical creature named '%s' with the power '%s' has entered the forest!\n", name, power);
}

void displayForest(Creature *head) {
    if (head == NULL) {
        printf("The forest is empty, no magical creatures can be found.\n");
        return;
    }

    printf("In the magical forest, you can find:\n");
    Creature *current = head;
    while (current != NULL) {
        printf("Creature: %s, Power: %s\n", current->name, current->power);
        current = current->next;
    }
    printf("\n");
}

void removeCreature(Creature **head, const char *name) {
    Creature *current = *head;
    Creature *previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("The creature '%s' could not be found in the forest.\n", name);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("The creature '%s' has left the magical forest.\n", name);
}

Creature* searchCreature(Creature *head, const char *name) {
    Creature *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Creature *forest = NULL;

    addCreature(&forest, "Phoenix", "Rebirth from ashes");
    addCreature(&forest, "Unicorn", "Healing and purity");
    addCreature(&forest, "Dragon", "Fire-breathing might");
    addCreature(&forest, "Fairy", "Wings of enchantment");
    
    displayForest(forest);

    char creatureToFind[30] = "Unicorn";
    Creature *foundCreature = searchCreature(forest, creatureToFind);
    if (foundCreature) {
        printf("You've discovered a %s with the power: %s\n\n", foundCreature->name, foundCreature->power);
    } else {
        printf("Unfortunately, the creature '%s' is not in the forest.\n\n", creatureToFind);
    }

    removeCreature(&forest, "Dragon");
    displayForest(forest);

    // Cleanup remaining creatures
    while (forest != NULL) {
        removeCreature(&forest, forest->name);
    }

    printf("The magical forest has been cleared of all creatures. Until next time!\n");
    return 0;
}