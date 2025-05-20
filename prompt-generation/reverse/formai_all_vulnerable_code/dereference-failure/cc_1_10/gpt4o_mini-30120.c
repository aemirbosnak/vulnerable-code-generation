//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Spell {
    char name[50];
    char incantation[100];
    struct Spell *next;
} Spell;

typedef struct Spellbook {
    char owner[50];
    Spell *spells;
} Spellbook;

// Function to create a new spell
Spell *createSpell(const char *name, const char *incantation) {
    Spell *newSpell = (Spell *)malloc(sizeof(Spell));
    if (newSpell == NULL) {
        printf("Memory allocation failed for new spell.\n");
        exit(1);
    }
    strncpy(newSpell->name, name, sizeof(newSpell->name) - 1);
    strncpy(newSpell->incantation, incantation, sizeof(newSpell->incantation) - 1);
    newSpell->next = NULL;
    return newSpell;
}

// Function to add a spell to the spellbook
void addSpell(Spellbook *spellbook, const char *name, const char *incantation) {
    Spell *newSpell = createSpell(name, incantation);
    newSpell->next = spellbook->spells;
    spellbook->spells = newSpell;
}

// Function to display all spells in a spellbook
void displaySpells(const Spellbook *spellbook) {
    printf("Spellbook of %s:\n", spellbook->owner);
    Spell *current = spellbook->spells;
    if (current == NULL) {
        printf("This spellbook is empty.\n");
        return;
    }

    while (current != NULL) {
        printf(" - %s: \"%s\"\n", current->name, current->incantation);
        current = current->next;
    }
}

// Function to free all spells in a spellbook
void freeSpells(Spell *spell) {
    while (spell != NULL) {
        Spell *temp = spell;
        spell = spell->next;
        free(temp);
    }
}

// Function to free the spellbook
void freeSpellbook(Spellbook *spellbook) {
    freeSpells(spellbook->spells);
    free(spellbook);
}

// Main function to interact with the user
int main() {
    Spellbook *mySpellbook = (Spellbook *)malloc(sizeof(Spellbook));
    if (mySpellbook == NULL) {
        printf("Memory allocation failed for spellbook.\n");
        return 1;
    }
    printf("Enter the name of the spellbook owner: ");
    fgets(mySpellbook->owner, sizeof(mySpellbook->owner), stdin);
    mySpellbook->owner[strcspn(mySpellbook->owner, "\n")] = 0; // Remove newline

    mySpellbook->spells = NULL;
    
    int choice;
    char name[50];
    char incantation[100];

    do {
        printf("\n1. Add a spell\n");
        printf("2. View spells\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter the name of the spell: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter the incantation: ");
                fgets(incantation, sizeof(incantation), stdin);
                incantation[strcspn(incantation, "\n")] = 0; // Remove newline

                addSpell(mySpellbook, name, incantation);
                printf("Spell added!\n");
                break;
            case 2:
                displaySpells(mySpellbook);
                break;
            case 3:
                printf("Exiting. Releasing memory...\n");
                freeSpellbook(mySpellbook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}