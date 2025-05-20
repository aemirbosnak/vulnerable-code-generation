//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a mystical creature
typedef struct Creature {
    char *name;
    char *description;
    struct Creature *next;
} Creature;

// Function to create a new mystical creature
Creature* createCreature(char *name, char *description) {
    Creature *newCreature = (Creature *)malloc(sizeof(Creature));
    newCreature->name = strdup(name);
    newCreature->description = strdup(description);
    newCreature->next = NULL;
    return newCreature;
}

// Recursive function to traverse the creatures and search for treasure
void questForTreasure(Creature *creature, int depth) {
    if (creature == NULL) {
        printf("You have encountered a wise old forest spirit, and you've reached a dead end!\n");
        return;
    }

    // Print the current creature's details
    printf("%*sHere lies the %s:\n", depth * 2, "", creature->name);
    printf("%*s%s\n\n", depth * 2, "", creature->description);

    // Ask the user for direction
    char choice[10];
    printf("%*sDo you wish to approach the %s? (yes/no): ", depth * 2, "", creature->name);
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0; // remove trailing newline

    if (strcmp(choice, "yes") == 0) {
        printf("%*sYou have gained the trust of the %s!\n", depth * 2, "", creature->name);
        printf("%*sContinuing deeper into the forest...\n\n", depth * 2, "");
        questForTreasure(creature->next, depth + 1);
    } else {
        printf("%*sYou decide to venture elsewhere...\n\n", depth * 2, "");
        questForTreasure(creature->next, depth);
    }
}

// Function to create a linked list of mystical creatures for the quest
Creature* setupMysticalForest() {
    Creature *head = createCreature("Eldertree", "A towering tree that whispers ancient secrets.");
    head->next = createCreature("Glowing Sprite", "A tiny being with a shimmering light, dancing in the air.");
    head->next->next = createCreature("Dragonfly of Illusions", "A colorful dragonfly that creates vivid mirages.");
    head->next->next->next = createCreature("Phoenix Feather", "A rare feather that grants the wisdom of ages.");
    head->next->next->next->next = createCreature("Griffin Guardian", "A majestic creature, part lion, part eagle, that protects the treasure.");

    return head;
}

// Function to clean up the memory used for creatures
void freeCreatures(Creature *creature) {
    while (creature != NULL) {
        Creature *temp = creature;
        creature = creature->next;
        free(temp->name);
        free(temp->description);
        free(temp);
    }
}

// Main function: The quest begins here!
int main() {
    printf("Welcome to the Enchanted Forest!\n");
    printf("Your quest is to find the hidden treasure guarded by mystical creatures...\n\n");

    Creature *forestCreatures = setupMysticalForest();
    questForTreasure(forestCreatures, 0);

    printf("Thank you for exploring the forest! The adventure continues...\n");

    freeCreatures(forestCreatures);
    return 0;
}