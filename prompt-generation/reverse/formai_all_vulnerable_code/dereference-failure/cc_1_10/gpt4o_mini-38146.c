//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for representing a character
typedef struct Character {
    char name[50];
    struct Character *left;   // Family relation (left)
    struct Character *right;  // Family relation (right)
    struct Character *next;   // Next in friendship (linked list)
} Character;

// Function to create a new character node
Character *createCharacter(const char *name) {
    Character *newCharacter = (Character *)malloc(sizeof(Character));
    strcpy(newCharacter->name, name);
    newCharacter->left = newCharacter->right = NULL;
    newCharacter->next = NULL;
    return newCharacter;
}

// Function to add a friendship in the linked list
void addFriendship(Character *character, const char *friendName) {
    Character *friend = createCharacter(friendName);
    if (character->next == NULL) {
        character->next = friend;
    } else {
        Character *tmp = character->next;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = friend;
    }
}

// Function to print friendships
void printFriendships(Character *character) {
    printf("Friendships of %s:\n", character->name);
    Character *friend = character->next;
    while (friend != NULL) {
        printf("   - %s\n", friend->name);
        friend = friend->next;
    }
}

// Pre-order traversal to show family tree
void printFamilyTree(Character *character, int depth) {
    if (character == NULL)
        return;
    
    for (int i = 0; i < depth; i++) {
        printf("   ");
    }
    printf("%s\n", character->name);
    
    printFamilyTree(character->left, depth + 1);
    printFamilyTree(character->right, depth + 1);
}

// Main function to illustrate characters and their relationships
int main() {
    // Create family tree for the Montague and Capulet families
    Character *romeo = createCharacter("Romeo Montague");
    Character *juliet = createCharacter("Juliet Capulet");

    // Building Romeo's family
    romeo->left = createCharacter("Lord Montague");
    romeo->right = createCharacter("Lady Montague");

    // Building Juliet's family
    juliet->left = createCharacter("Lord Capulet");
    juliet->right = createCharacter("Lady Capulet");

    // Establish friendships
    addFriendship(romeo, "Mercutio");
    addFriendship(romeo, "Benvolio");
    addFriendship(juliet, "Nurse");
    addFriendship(juliet, "Paris");

    // Display Family Trees
    printf("Montague Family Tree:\n");
    printFamilyTree(romeo, 0);
    printf("\nCapulet Family Tree:\n");
    printFamilyTree(juliet, 0);

    // Display Friendships
    printFriendships(romeo);
    printFriendships(juliet);

    // Free allocated memory (for demonstration purpose)
    free(romeo->left);
    free(romeo->right);
    free(romeo->next->next);
    free(romeo->next);
    free(romeo);
    
    free(juliet->left);
    free(juliet->right);
    free(juliet->next->next);
    free(juliet->next);
    free(juliet);

    return 0;
}