//FormAI DATASET v1.0 Category: Sorting ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our struct for character data
typedef struct Character {
    char* name;
    int strength;
    int agility;
    int intelligence;
    struct Character* next;
} Character;

// Declare our functions
Character* createCharacter(char* name, int strength, int agility, int intelligence);
void insertCharacter(Character** head, Character* character);
void sortCharacters(Character** head);
void swapNodes(Character** a, Character** b);
void printCharacters(Character* head);

// Main function
int main() {
    Character* head = NULL;

    // Create our characters
    Character* c1 = createCharacter("Neo", 8, 10, 9);
    Character* c2 = createCharacter("Trinity", 6, 7, 10);
    Character* c3 = createCharacter("Morpheus", 9, 8, 7);
    Character* c4 = createCharacter("Agent Smith", 10, 9, 8);

    // Insert our characters into the linked list
    insertCharacter(&head, c1);
    insertCharacter(&head, c2);
    insertCharacter(&head, c3);
    insertCharacter(&head, c4);

    // Print the unsorted list
    printf("Unsorted Characters:\n");
    printCharacters(head);

    // Sort the list by intelligence
    sortCharacters(&head);

    // Print the sorted list
    printf("\nSorted Characters:\n");
    printCharacters(head);

    return 0;
}

// Function to create a new character
Character* createCharacter(char* name, int strength, int agility, int intelligence) {
    Character* character = malloc(sizeof(Character));
    character->name = malloc(strlen(name) + 1);
    strcpy(character->name, name);
    character->strength = strength;
    character->agility = agility;
    character->intelligence = intelligence;
    character->next = NULL;
    return character;
}

// Function to insert a character into a linked list
void insertCharacter(Character** head, Character* character) {
    if (*head == NULL) {
        *head = character;
    } else {
        Character* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = character;
    }
}

// Function to sort a linked list of characters by intelligence
void sortCharacters(Character** head) {
    Character** i;
    Character** j;

    // Bubble sort
    for (i = head; *i != NULL; i = &((*i)->next)) {
        for (j = &((*i)->next); *j != NULL; j = &((*j)->next)) {
            if ((*i)->intelligence < (*j)->intelligence) {
                swapNodes(i, j);
            }
        }
    }
}

// Function to swap two linked list nodes
void swapNodes(Character** a, Character** b) {
    Character* temp = *a;
    *a = *b;
    *b = temp;

    temp = (*a)->next;
    (*a)->next = (*b)->next;
    (*b)->next = temp;
}

// Function to print a linked list of characters
void printCharacters(Character* head) {
    Character* current = head;
    while (current != NULL) {
        printf("%s: Strength %d, Agility %d, Intelligence %d\n", current->name, current->strength, current->agility, current->intelligence);
        current = current->next;
    }
}